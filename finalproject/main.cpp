//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: main.cpp

/*
Note to grader: You can turn on debug options in func.h, there is a lot of output though
*/

/*
note to mason: 
1. put your name, username, and sections at the top of every file
2. if you need to debug output do this:

if(DEBUG){

    cout << "DEBUG(main): initializing jewel #" << i << endl;
}

3. always use "g++ -Wall -W -s -pedantic-errors" when compiling, this is equivalent to fg++ on the school machines.
4. use a branch when making changes, dont commit directly to main
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

        if(DEBUG){

            cout << "DEBUG(main): initializing jewel #" << i << endl;
        }

        int newJewelX, newJewelY;

        do{
            
            newJewelX = generateRand(0, GRID_SIZE - 1);
            newJewelY = generateRand(0, GRID_SIZE - 1);

            if(DEBUG){
                
                cout << "DEBUG(main): generating random for jewel #" << i << endl;
            }
            
        }while(city.jewelGrid[newJewelX][newJewelY] == 'j');//make sure that theres only one jewel in each spot/ that we have 30 total

        jewel newJewel(newJewelX, newJewelY, generateRand(JEWEL_MIN_VALUE, JEWEL_MAX_VALUE));//initialize jewel objects

        jewels[i-1] = newJewel;

        city.jewelGrid[newJewelX][newJewelY] = 'j';

    }


    


    return 0;
}







