//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: robber.cpp

//Other Author: Mason Bateman (mcbqrz, lab section 301, class section 101)

#include "func.h"
#include "robber.h"
#include "city.h"
#include <iostream>
#include <cstdlib>


//-----====== Static member variables =====-----

int robber::collectiveBagValue = 0;

int robber::currentId = 0;


//-----====== Constructors =====-----


robber::robber(const int X, const int Y, const bool isGreedyInput, const bool isActive){

    if(!initialized){//after the first run we will only run if there was an error last time

        if(X < GRID_SIZE && Y < GRID_SIZE && X > -1 && Y > -1){//if the coordinates are within the grid and the value is positive

            initialized = true;
            robberX = X;
            robberY = Y;
            isGreedy = isGreedyInput;
            id = ++currentId;//increment then assign id
            active = isActive;

        }else{

            if(DEBUG){
                cout << "ERROR: robber constructor failed, robber coordinates out of range" << endl;
            }

            initialized = false;
        }
    }

    return;
}


//-----====== Functions =====-----

bool robber::pickUpLoot(jewel & j){

    if(DEBUG){
        cout << j.getX() << j.getY() << endl;
        cout << j.isPickedUp << endl;
    }

    if(gemBag >= 10){

        if(DEBUG){
            cout << "DEBUG:Warning(robber.pickUpLoot()): Gem bag full, jewel not collected" << endl;
        }

        return true;//return an error if gem bag is full
    }

    if(robberX == j.getX() && robberY == j.getY()){//if in the same location

        gemBag++;
        bagValue += j.getValue();
        collectiveBagValue += j.getValue();
        j.isPickedUp = true;
        return false;

    }else{

        if(DEBUG){

            cout << "DEBUG:Error(robber.pickUpLoot()): robber and jewel not in the same place" << endl;
        }
        
        return true;//return error if not in the same location
    }

    return false;
}


void robber::move(city* c){

    if(immobilized > 0){

        cout << "robber immobilized" << endl;
        immobilized--;

        return;
    }

    if(!initialized || !active){//do not run function if the robber is not initialized

        if(DEBUG){
            cout << "DEBUG(robber.move): robber not initialized or not active, therefore not moved" << endl;
        }

        return;
    }

    int moveDownAmount = 0, moveRightAmount = 0;
    int newx = robberX, newy = robberY;

    do{//we can only get away with using a do while loop because there is never a situation where there is not an open space to move to

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

        newx = robberX + moveRightAmount;
        newy = robberY + moveDownAmount;

    }while(!(newx < GRID_SIZE && newy < GRID_SIZE && newx > -1 && newy > -1));//redo if it would move us out of bounds

    robberX = newx;
    robberY = newy;


    if(DEBUG){

        cout << "DEBUG: The new x is " << newx << endl;
        cout << "DEBUG: The new y is " << newy << endl;
    }

    c->updateLetterGrids();//refresh the grid after move

    bool picked = false;
    bool pickupError;
    
    //attempt to pick up every jewel, if the jewel is not in the same location then it will not work
    if(moveRightAmount != 0 || moveDownAmount != 0){//if moved at all

        for(int i = 0; i < NUM_STARTING_JEWELS; i++){

            pickupError = pickUpLoot(c->jewels[i]);

            if(!pickupError){

                picked = true;
            }
        }
    }

    if(picked){
        movesSinceJewel++;
        cout << "Gem picked up by robber id: " << id << endl;
    }

    if(movesSinceJewel > 4){

        immobilized = 2;
        movesSinceJewel = 0;
    }

    c->updateLetterGrids();//refresh the grid after move

    return;
}



//-----====== Getters and setters =====-----

int robber::getX(){

    return robberX;
}

int robber::getY(){

    return robberY;
}

bool robber::isActive(){

    return active;
}

bool robber::isInitialized(){

    return initialized;
}
