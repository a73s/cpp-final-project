//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: robber.cpp

//Other Author: Mason Bateman (mcbqrz, lab section 301, class section 101)

#include "func.h"
#include "robber.h"
#include "city.h"
#include "jewel.h"
#include <iostream>
#include <cstdlib>


//-----====== Static member variables =====-----

int robber::collectiveBagValue = 0;

int robber::currentId = 0;


//-----====== Constructors =====-----


robber::robber(city* city, const int X, const int Y, const bool isGreedyInput, const bool isActive){

    if(!initialized){//after the first run we will only run if there was an error last time

        if(city->isValidMove(X, Y)){//if the coordinates are within the grid and the value is positive

            initialized = true;
            robberX = X;
            robberY = Y;
            isGreedy = isGreedyInput;
            id = ++currentId;//increment then assign id
            active = isActive;
            //active = 0;

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


    if(gemBag >= 10){

        if(DEBUG){
            cout << "DEBUG:Warning(robber.pickUpLoot()): Gem bag full, jewel not collected" << endl;
        }

        return true;//return an error if gem bag is full
    }

    if(robberX == j.getX() && robberY == j.getY()){//if in the same location

        pickedJewels[gemBag] = &j;
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

    if(c->numCopsBribed >= NUM_STARTING_POLICE){

        if(DEBUG){
            cout << "DEBUG(robber.move): all the police are bribed, skipping" << endl;
        }

        return;
    }

    int moveDownAmount = 0, moveRightAmount = 0;
    int newx = robberX, newy = robberY;
    bool doAgain;//this is for checking if we need to do the do-while loop again, i use this to differentiate between greedy and non greedy robbers
    int numDistErrors = 0;

    do{//we can only get away with using a do while loop because there is never a situation where there is not an open space to move to

        int allDistAreSameSafeguard = 0;


        if(DEBUG){

            cout << "DEBUG(robber.move):finding coordinates for robber move" << endl;
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

        newx = robberX + moveRightAmount;
        newy = robberY + moveDownAmount;

        //EXTRA CREDIT:

        doAgain = false;//default state is that the candidtate coordinates are accepted

        if(isGreedy){//if we are greedy, change the condition in these ways

            if(isAJewelClose(c) && !(gemBag == 10)){

                doAgain = (!(c->jewelGrid[newx][newy] == 'j'));//if greedy and can fit another gem
            }

            if(gemBag == 10){//if gem bag full, compare the lowest cop distances

                float currentMinDist;
                float newMinDist;

                float maxDist = distance(1,1,GRID_SIZE,GRID_SIZE);

                currentMinDist = maxDist;//set to the current max distance given the board size


                bool skippedAll = true;//safeguard against there being no valid cops
                //get the minimum distance to a cop using the current coordinates
                for(int i = 0; i < NUM_STARTING_POLICE; i++){

                    if(!c->polices[i].isActive() || !c->polices[i].isInitialized()){//if the cop is invalid, skip him

                        continue;
                    }

                    skippedAll = false;

                    float tempDist = distance(robberX, robberY, c->polices[i].getX(), c->polices[i].getY());
                    float tempDist2 = distance(newx, newy, c->polices[i].getX(), c->polices[i].getY());

                    if(tempDist == 0){
                        
                        if(DEBUG){
                            cout << "Error(robber.move, greedy robber whos bag is full(moving tword a cop)): we are already on a cop, distance is 0" << endl;
                        }

                        numDistErrors++;
                        
                    }

                    if(tempDist < currentMinDist){

                        currentMinDist = tempDist;
                    }

                    if(tempDist2 < currentMinDist){

                        newMinDist = tempDist2;
                    }
                }
            
                doAgain = (currentMinDist <= newMinDist);//if the smallest distance for the candidate coordinates is greater thatn that of the current coordinates go again

                if(currentMinDist == newMinDist){

                    allDistAreSameSafeguard++;

                    if(allDistAreSameSafeguard > 10){

                        doAgain = false;
                        allDistAreSameSafeguard = 0;
                    }

                    if(DEBUG){
                        cout << "ERROR(robber.move, greedy robber whos bag is full(moving tword a cop)): The current and candidate distances are the same, trying again" << endl;
                    }
                }

                if(skippedAll){

                    cout << "ERROR(robber.move, greedy robber whos bag is full(moving tword a cop)): there is no active or initialized cop to compare with the current distance, something went wrong" << endl;
                }
            }
        }

        //END EXTRA CREDIT SECTION

        

        if(!(c->isValidMove(newx, newy))){//no matter what we cannot make an invalid move

            doAgain = true;
        }

        if(numDistErrors > 10){
            
            numDistErrors = 0;

            doAgain = false;
        }

    }while(doAgain);//redo if it would move us out of bounds

    robberX = newx;
    robberY = newy;


    if(DEBUG){

        cout << "DEBUG(robber.move): The new x is " << newx << endl;
        cout << "DEBUG(robber.move): The new y is " << newy << endl;
    }

    c->updateLetterGrids();//refresh grid before checking for a jewel

    bool picked = false;
    bool pickupError;
    
    //attempt to pick up every jewel, if the jewel is not in the same location then it will not work
    if(!(moveRightAmount == 0 && moveDownAmount == 0) && c->jewelGrid[robberX][robberY] == 'j'){//if moved at all

        for(int i = 0; i < NUM_STARTING_JEWELS; i++){

            pickupError = pickUpLoot(c->jewels[i]);

            if(!pickupError){

                picked = true;
            }
        }

        c->updateLetterGrids();//refresh the grid after collecting jewel

    }

    if(picked){
        movesSinceJewel = 0;
        cout << "Gem picked up by robber id: " << id << endl;

    }else{

        movesSinceJewel++;
    }

    if(movesSinceJewel > 4){

        immobilized = 2;
        movesSinceJewel = 0;
    }


    return;
}


bool robber::isAJewelClose(city* city){

    if(city->jewelGrid[robberX - 1][robberY - 1] == 'j' && city->isValidMove(robberX-1, robberY-1)){//north west of robber

        return true;
    }
    if(city->jewelGrid[robberX - 1][robberY - 0] == 'j' && city->isValidMove(robberX-1, robberY-0)){//north of robber

        return true;
    }
    if(city->jewelGrid[robberX - 1][robberY + 1] == 'j' && city->isValidMove(robberX-1, robberY+1)){//north east of robber

        return true;
    }
    if(city->jewelGrid[robberX - 0][robberY - 1] == 'j' && city->isValidMove(robberX+0, robberY-1)){//west of robber

        return true;
    }
    if(city->jewelGrid[robberX - 0][robberY + 1] == 'j' && city->isValidMove(robberX-0, robberY+1)){//east of robber

        return true;
    }
    if(city->jewelGrid[robberX + 1][robberY - 1] == 'j' && city->isValidMove(robberX+1, robberY-1)){//south west of robber

        return true;
    }
    if(city->jewelGrid[robberX + 1][robberY - 0] == 'j' && city->isValidMove(robberX+1, robberY-0)){//south of robber

        return true;
    }
    if(city->jewelGrid[robberX + 1][robberY + 1] == 'j' && city->isValidMove(robberX+1, robberY+1)){//south east of robber

        return true;
    }
    
    return false;
}


void robber::tryBribe(city* c){

    if(isGreedy && (c->copGrid1[robberX][robberY] == 'c' || c->copGrid2[robberX][robberY] == 'c') && active && gemBag >= 10){//if !(i am a greedy robber and there is a cop in this spot)

        if(DEBUG){

            cout << "DEBUG(robber::tryBribe): no cop in the same spot as a greedy robber" << endl;
        }

        for(int i = 0; i < NUM_STARTING_POLICE; i++){

            if(c->polices[i].isActive() && c->polices[i].getX() == robberX && c->polices[i].getY() == robberY){

                c->polices[i].active = false;

                cout << "Robber id " << id << "bribed cop id " << c->polices[i].getid() << endl;
                c->numCopsBribed++;
            }
        }

        c->updateLetterGrids();

        return;
    }
}
