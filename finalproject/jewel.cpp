//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: jewel.cpp

//Other Author: Mason Bateman (mcbqrz, lab section 301, class section 101)

#include "func.h"
#include "jewel.h"

#include <iostream>
#include <cstdlib>

using namespace std;

//-----====== constructors =====-----

jewel::jewel(const int X, const int Y){

    if(!initialized){//after the first run we will only run if there was an error last time

        if(X < GRID_SIZE && Y < GRID_SIZE && X > -1 && Y > -1){//if the coordinates are within the grid and the value is positive

            initialized = true;
            originalX = X;
            originalY = Y;
            jewelValue = X*X + Y*Y;
            id = generateRand(1, 10000);

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

    return jewelValue;
}










