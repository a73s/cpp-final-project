//Author: Adam Seals (agsgv4 section 306)
//date: 11/29/23
//purpose: Final Project
//file: jewel.cpp

#include "func.h"
#include "jewel.h"

#include <iostream>
#include <cstdlib>

using namespace std;



bool jewel::initJewel(const int X, const int Y, const int value){

    if(!initialized){//after the first run we will only run if there was an error last time

        if((X < GRID_SIZE && Y < GRID_SIZE && X > -1 && Y > -1) && (value > -1)){//if the coordinates are within the grid and the value is positive

            initialized = true;
            originalX = X;
            originalY = Y;
            jewelValue = value;

        }else{

            initialized = false;
        }
    }

    return !initialized;
}

int jewel::getX() const{

    return originalX;
}

int jewel::getY() const{

    return originalY;
}

int jewel::getValue() const{

    return originalY;
}










