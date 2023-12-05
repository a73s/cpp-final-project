//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: city.cpp

#include "func.h"
#include "city.h"
#include "jewel.h"

#include <iostream>
#include <cstdlib>

using namespace std;



void city::updateLetterGrids(){

    //clear grids

    for(int i = 0; i < GRID_SIZE; i++){

        for(int j = 0; j < GRID_SIZE; j++){

            jewelGrid[i][j] = ' ';
        }
    }

    //put the jewels back on the grid
    for(int i = 0; i < NUM_STARTING_JEWELS; i++){

        jewel tempJewel = jewels[i];

        if(!tempJewel.isPickedUp && tempJewel.initialized){

            jewelGrid[tempJewel.getX()][tempJewel.getY()] = 'j';
        }

    }

    //put robbers back on the grid


    //put cops back on the grid
}


void city::printGrid(){

    cout << "-------------------------------------" << endl;
    cout << "   0    1    2    3    4    5    6   Y"<< endl;

    for(int i = 0; i < GRID_SIZE; i++){

        cout << i;

        for(int j = 0; j < GRID_SIZE; j++){
            
            int tempNumThings = 0;
            cout << "|";

            if(jewelGrid[i][j] == 'j'){

                cout << 'j';
                tempNumThings++;
            }

            if(robberGrid[i][j] == 'p'){

                cout << 'p';
                tempNumThings++;
            }

            if(robberGridGreedy[i][j] == 'r'){

                cout << 'r';
                tempNumThings++;
            }

            //add thing to print cops

            for(int k = 0; k < 4 - tempNumThings; k++){//allows us to keep the spacing consistent

                cout << ' ';
            }
        }

        cout << '|' << endl;

    }

    cout << "X" << endl;  
    cout << " Key: " << endl;
    cout << "       robber: \'p\'" << endl;
    cout << "greedy robber: \'r\'" << endl;
    cout << "        jewel: \'j\'" << endl;
    cout << "          cop: \'c\'" << endl;
}
