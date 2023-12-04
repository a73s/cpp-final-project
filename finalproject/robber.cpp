//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: robber.cpp

#include "func.h"
#include "robber.h"

#include <iostream>
#include <cstdlib>


int robber::collectiveBagValue = 0;


bool robber::init(const int X, const int Y, const bool isGreedyInput){

    if(!initialized){//after the first run we will only run if there was an error last time

        if(X < GRID_SIZE && Y < GRID_SIZE && X > -1 && Y > -1){//if the coordinates are within the grid and the value is positive

            initialized = true;
            robberX = X;
            robberY = Y;
            isGreedy = isGreedyInput;

        }else{

            if(DEBUG){
                cout << "ERROR: robber.init() failed, robber coordinates out of range" << endl;
            }

            initialized = false;
        }
    }

    return !initialized;
}

bool robber::pickUpLoot(jewel & j){

    int jewelX = j.getX();
    int jewelY = j.getY();
    int jewelVal = j.getValue();

    if(gemBag == 10){

        return true;//return an error if gem bag is full

        if(DEBUG){
            cout << "Warning(robber.pickUpLoot()): Gem bag full, jewel not collected" << endl;
        }
    }

    if(jewelX == robberX && jewelY == robberY){//if in the same location

        gemBag++;
        bagValue += jewelVal;
        collectiveBagValue += jewelVal;

    }else{

        return true;//return error if not in the same location

        if(DEBUG){

            cout << "Error(robber.pickUpLoot()): robber and jewel not in the same place" << endl;
        }
    }

    return false;
}


void robber::move(){

    if(!initialized){//do not run function if the robber is not initialized

        if(DEBUG){
            cout << "DEBUG(robber.move): robber not initialized, not moved" << endl;
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

    return;
}


