//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: func.cpp

//Other Author: Mason Bateman (mcbqrz, lab section 301, class section 101)

#include "func.h"
#include "city.h"

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//-----===== FUNCTION DEFINITIONS =====-----

int generateRand(const int & min, const int & max){

    return (rand()%(max-min+1)+min);
}


void generateStartingBoard(city & city){

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
                cout << "coordinates X, Y: " << newJewelX << " " << newJewelY << endl;
            }
            
        }while(city.jewelGrid[newJewelX][newJewelY] == 'j');//make sure that theres only one jewel in each spot/ that we have 30 total

        jewel newJewel(newJewelX, newJewelY, generateRand(JEWEL_MIN_VALUE, JEWEL_MAX_VALUE));//initialize jewel objects

        city.jewels[i-1] = newJewel;
    }

    city.updateLetterGrids();
    

    //-----===== Create Robbers =====-----

    //regular robbers
    for(int i = 1; i <= NUM_STARTING_ROBBERS-2; i++){

        if(DEBUG){

            cout << "DEBUG(main): creating robber #" << i << endl;
        }

        int newRobberX, newRobberY;

        do{

            newRobberX = generateRand(0, GRID_SIZE - 1);
            newRobberY = generateRand(0, GRID_SIZE - 1);

            if(DEBUG){
                
                cout << "DEBUG(main): generating random for robber #" << i << endl;
                cout << "coordinates X, Y: " << newRobberX << " " << newRobberY << endl;
            }

        }while(city.jewelGrid[newRobberX][newRobberY] == 'j' || city.robberGrid1[newRobberX][newRobberY] == 'p' || city.robberGridGreedy1[newRobberX][newRobberY] == 'r' || city.robberGrid2[newRobberX][newRobberY] == 'p' || city.robberGridGreedy2[newRobberX][newRobberY] == 'r');//if there is a jewel or a robber in that spot

        robber newRobber(&city, newRobberX, newRobberY, 0);
        city.robbers[i-1] = newRobber;
    }


    city.updateLetterGrids();

    //greedy robbers
    for(int i = 3; i <= NUM_STARTING_ROBBERS; i++){

        if(DEBUG){

            cout << "DEBUG(main): creating greedy robber #" << i << endl;
        }

        int newRobberX, newRobberY;

        do{

            newRobberX = generateRand(0, GRID_SIZE - 1);
            newRobberY = generateRand(0, GRID_SIZE - 1);

        //do it again if there is a robber in the newly generated spot
        }while(city.jewelGrid[newRobberX][newRobberY] == 'j' || city.robberGrid1[newRobberX][newRobberY] == 'p' || city.robberGridGreedy1[newRobberX][newRobberY] == 'r' || city.robberGrid2[newRobberX][newRobberY] == 'p' || city.robberGridGreedy2[newRobberX][newRobberY] == 'r');

        robber newRobber(&city, newRobberX, newRobberY, 1);
        city.robbers[i-1] = newRobber;

    }
    
    city.updateLetterGrids();


    //-----===== Generate cops =====-----





}




