//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: police.cpp

//Other Author: Mason Bateman (mcbqrz, lab section 301, class section 101)

#include "func.h"
#include "police.h"
#include "city.h"

#include <iostream>
#include <cstdlib>

class city;//forward declaration of city

//-----====== Static member variables =====-----

int police::collectiveConfiscateValue = 0;

int police::currentId = 4;


//-----====== Constructors =====-----


police::police(city* city, const int X, const int Y, const bool isActive){

    if(city->isValidMove(X, Y)){//if the coordinates are within the grid and the value is positive

        initialized = true;
        policeX = X;
        policeY = Y;
        id = ++currentId;//increment then assign id
        active = isActive;

    }else{

        if(DEBUG){
            cout << "ERROR: police constructor failed, police coordinates out of range" << endl;
        }

        initialized = false;
    }

    return;
}



void police::move(city* c){

    if(!initialized || !active){//do not run function if the police is not initialized

        if(DEBUG){
            cout << "DEBUG(police.move): cop not initialized or not active, therefore not moved" << endl;
        }

        return;
    }

    int moveDownAmount = 0, moveRightAmount = 0;
    int newx = policeX, newy = policeY;

    do{//we can only get away with using a do while loop because there is never a situation where there is not an open space to move to
        
        if(DEBUG){

            cout << "DEBUG(police.move):finding coordinates for police move" << endl;
        }

        int choice = generateRand(0,7);

        switch(choice){

            case 0:{
                
                moveDownAmount = -1;
                moveRightAmount = -1;
                break;
            }
            case 1:{

                moveDownAmount = -1;
                moveRightAmount = 0;
                break;
            }
            case 2:{
                
                moveDownAmount = -1;
                moveRightAmount = 1;
                break;
            }
            case 3:{
                
                moveDownAmount = 0;
                moveRightAmount = -1;
                break;
            }
            case 4:{

                moveDownAmount = 0;
                moveRightAmount = 1;                
                break;
            }
            case 5:{
                
                moveDownAmount = 1;
                moveRightAmount = -1;
                break;
            }
            case 6:{
                
                moveDownAmount = 1;
                moveRightAmount = 0;
                break;
            }
            case 7:{
                
                moveDownAmount = 1;
                moveRightAmount = 1;
                break;
            }
        }

        newx = policeX + moveRightAmount;
        newy = policeY + moveDownAmount;

    }while(!(c->isValidMove(newx, newy)));//redo if it would move us out of bounds

    policeX = newx;
    policeY = newy;

    if(DEBUG){

        cout << "DEBUG(police.move): The new x is " << newx << endl;
        cout << "DEBUG(police.move): The new y is " << newy << endl;
    }

    c->updateLetterGrids();//refresh the grid after move

    //check for jewels, if so, make that jewel inactive

    if(c->jewelGrid[policeX][policeY] == 'j'){

        for(int i = 0; i < NUM_STARTING_JEWELS; i++){

            if(policeX == c->jewels[i].getX() && policeY == c->jewels[i].getY()){//if in the same location

                c->jewels[i].isPickedUp = true;

                if(DEBUG){

                    cout << "DEBUG(police.move):Jewel Picked up by police" << endl;
                }
            }
        }

        c->updateLetterGrids();//refresh the grid after collecting jewel
    }


    if(c->copGrid1[policeX][policeY] == 'c' && c->copGrid2[policeX][policeY] == 'c'){//if both cops in the same place, exchange jewels

        int totalValue;

        totalValue = c->polices[0].confiscatedValue + c->polices[1].confiscatedValue;

        c->polices[0].confiscatedValue = static_cast <int> (totalValue/2);//round down
        c->polices[1].confiscatedValue = static_cast <int> (totalValue/2);

        cout << "The cops meet and exchange jewels, they now each have $" << totalValue/2 << " worth of jewels" << endl;
    }


    return;
}



void police::arrest(robber & theRobber, city* c){

    if(DEBUG){

        cout << "DEBUG(police.arrest): we are arresting a robber" << endl;
    }

    theRobber.active = false;
    int numconfiscated = 0;

    if(theRobber.gemBag > 0){//prevent segfaults

        for(int i = 0; i < theRobber.gemBag; i++){

            //we gotta dereference every time we use this

            if((theRobber.pickedJewels[i])->initialized){


                theRobber.pickedJewels[i]->confiscated = true;
                confiscatedValue += theRobber.pickedJewels[i]->getValue();
                collectiveConfiscateValue += theRobber.pickedJewels[i]->getValue();
                numconfiscated++;
            }
        }

        cout << "Cop id #" << id << " arrested robber id #" << theRobber.id << " and confiscated " << numconfiscated << " jewels." << endl;

        c->updateLetterGrids();//refresh the grid after arrest
    }

    c->numRobbersArrested++;

    return;
}


void police::tryArrest(city* c){

    c->updateLetterGrids();

    if(c->robberGrid1[policeX][policeY] == 'p' || c->robberGrid2[policeX][policeY] == 'p' || c->robberGridGreedy1[policeX][policeY] == 'r' || c->robberGridGreedy2[policeX][policeY] == 'r'){//if there is a robber in the same grid

        for(int i = 0; i < NUM_STARTING_ROBBERS; i++){

            if(c->robbers[i].getX() == policeX && c->robbers[i].getY() == policeY && active){//arrest all robbers in this spot

                arrest(c->robbers[i], c);
            }
        }
    }

}