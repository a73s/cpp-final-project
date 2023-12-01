//Author: Adam Seals (agsgv4 section 306)
//date: 11/29/23
//purpose: Final Project
//file: robber.cpp

#include "func.h"
#include "robber.h"

#include <iostream>
#include <cstdlib>


bool robber::init(const int X, const int Y);{

    if(!initialized){//after the first run we will only run if there was an error last time

        if((X < GRID_SIZE && Y < GRID_SIZE && X > -1 && Y > -1) && (value > -1)){//if the coordinates are within the grid and the value is positive

            initialized = true;
            robberX = X;
            robberY = Y;

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

    jewelX = j.getX();
    jewelY = j.getY();
    jewelVal = j.getValue();

    if(gemBag == 10){

        return true;//return an error if gem bag is full

        if(DEBUG){
            cout << "Warning(robber.pickUpLoot()): Gem bag full, jewel not collected" << endl;
        }
    }

    if(jewelX == robberX && jewelY == robberY){//if in the same location

        gemBag++;
        bagValue += jewelValue;
    }else{

        return true;//return error if not in the same location

        if(debug){
            cout << "Error(robber.pickUpLoot()): robber and jewel not in the same place" << endl;
        }
    }

    return false;
}







