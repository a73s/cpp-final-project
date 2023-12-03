//Author: Adam Seals (agsgv4 section 306)
//date: 11/29/23
//purpose: Final Project
//file: main.cpp

/*
NOTE: You can turn on debug options in func.h
*/


#include "func.h"
#include "city.h"
#include "jewel.h"
#include "robber.h"
#include "police.h"
#include "city.h"

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    srand(100);

    city city;
    jewel jewels[NUM_STARTING_JEWELS] = {};

    //generate jewels onto the grid
    for(int i = 1; i <= NUM_STARTING_JEWELS; i++){

        int newJewelX, newJewelY;

        do{
            
            newJewelX = generateRand(0, GRID_SIZE - 1);
            newJewelY = generateRand(0, GRID_SIZE - 1);
            
        }while(city.jewelGrid[newJewelX][newJewelY] != 'j');//make sure that theres only one jewel in each spot/ that we have 30 total

        jewel newJewel;
        newJewel.init(newJewelX, newJewelY, generateRand(JEWEL_MIN_VALUE, JEWEL_MAX_VALUE));

        jewels[i-1] = newJewel;

        city.jewelGrid[newJewelX][newJewelY] = 'j';

    }


    


    return 0;
}







