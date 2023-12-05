//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: jewel.cpp

#include "func.h"
#include "jewel.h"

#include <iostream>
#include <cstdlib>

using namespace std;

//-----====== constructors =====-----

jewel::jewel(const int X, const int Y, const int value){

    if(!initialized){//after the first run we will only run if there was an error last time

        if((X < GRID_SIZE && Y < GRID_SIZE && X > -1 && Y > -1) && (value > -1)){//if the coordinates are within the grid and the value is positive

            initialized = true;
            originalX = X;
            originalY = Y;
            jewelValue = value;

        }else{

            if(DEBUG){
                cout << "ERROR: jewel.init() failed, jewel coordinates out of range" << endl;
            }

            initialized = false;
        }
    }

    return;
}

//-----====== getters and setters =====-----

int jewel::getX() const{

    return originalX;
}

int jewel::getY() const{

    return originalY;
}

int jewel::getValue() const{

    return originalY;
}










