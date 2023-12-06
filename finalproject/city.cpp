//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: city.cpp

//Other Author: Mason Bateman (mcbqrz, lab section 301, class section 101)

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

    for(int i = 0; i < GRID_SIZE; i++){

        for(int j = 0; j < GRID_SIZE; j++){

            robberGrid1[i][j] = ' ';
        }
    }

    for(int i = 0; i < GRID_SIZE; i++){

        for(int j = 0; j < GRID_SIZE; j++){

            robberGrid2[i][j] = ' ';
        }
    }

    for(int i = 0; i < GRID_SIZE; i++){

        for(int j = 0; j < GRID_SIZE; j++){

            robberGridGreedy1[i][j] = ' ';
        }
    }

    for(int i = 0; i < GRID_SIZE; i++){

        for(int j = 0; j < GRID_SIZE; j++){

            robberGridGreedy2[i][j] = ' ';
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
    for(int i = 0; i < NUM_STARTING_ROBBERS; i++){

        robber tempRobber = robbers[i];

        if(!tempRobber.isActive() || !tempRobber.isInitialized()){//if robber is not initialized or not active we skip that robber

            continue;
        }

        switch(i){
            case 0:{

                robberGrid1[tempRobber.getX()][tempRobber.getY()] = 'p';
                break;
            }
            case 1:{

                robberGrid2[tempRobber.getX()][tempRobber.getY()] = 'p';
                break;
            }
            case 2:{
                    
                robberGridGreedy1[tempRobber.getX()][tempRobber.getY()] = 'r';
                break;
            }
            case 3:{
                    
                robberGridGreedy2[tempRobber.getX()][tempRobber.getY()] = 'r';
                break;
            }
        }
    }

    //put cops back on the grid

    
}


void city::printGrid(){

    cout << " |0      |1      |2      |3      |4      |5      |6      |Y"<< endl;

    for(int i = 0; i < GRID_SIZE; i++){

        cout << "----------------------------------------------------------" << endl;

        cout << i;

        for(int j = 0; j < GRID_SIZE; j++){
            
            int tempNumThings = 0;
            cout << "|";

            if(jewelGrid[i][j] == 'j'){

                cout << 'j';
                tempNumThings++;
            }

            if(robberGrid1[i][j] == 'p'){

                cout << 'p';
                tempNumThings++;
            }

            if(robberGrid2[i][j] == 'p'){

                cout << 'p';
                tempNumThings++;
            }

            if(robberGridGreedy1[i][j] == 'r'){

                cout << 'r';
                tempNumThings++;
            }

            if(robberGridGreedy2[i][j] == 'r'){

                cout << 'r';
                tempNumThings++;
            }

            //add thing to print cops

            for(int k = 0; k < 7 - tempNumThings; k++){//allows us to keep the spacing consistent

                cout << ' ';
            }
        }

        cout << '|' << endl;

    }

    cout << "----------------------------------------------------------" << endl;
    cout << "X" << endl;  
    cout << "Key: " << "                                               N" << endl;
    cout << "       robber: \'p\'" << "                                  |" << endl;
    cout << "greedy robber: \'r\'" << "                              W---|---E" << endl;
    cout << "        jewel: \'j\'" << "                                  |" << endl;
    cout << "          cop: \'c\'" << "                                  S" << endl;
    cout << endl;
}
