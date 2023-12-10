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
#include <cmath>

using namespace std;

//-----===== FUNCTION DEFINITIONS =====-----

int generateRand(const int & min, const int & max){

    return (rand()%(max-min+1)+min);
}


void generateStartingBoard(city & city){

    //generate jewels onto the grid
    for(int i = 1; i <= NUM_STARTING_JEWELS; i++){

        if(DEBUG){

            cout << "DEBUG(genStartBoard): initializing jewel #" << i << endl;
        }

        int newJewelX, newJewelY;

        do{
            
            newJewelX = generateRand(0, GRID_SIZE - 1);
            newJewelY = generateRand(0, GRID_SIZE - 1);

            if(DEBUG){
                
                cout << "DEBUG(genStartBoard): generating random for jewel #" << i << endl;
                cout << "coordinates X, Y: " << newJewelX << " " << newJewelY << endl;
            }
            
        }while(city.jewelGrid[newJewelX][newJewelY] == 'j');//make sure that theres only one jewel in each spot/ that we have 30 total

        jewel newJewel(newJewelX, newJewelY);//initialize jewel objects

        city.jewels[i-1] = newJewel;
    }

    city.updateLetterGrids();
    

    //-----===== Create Robbers =====-----

    //regular robbers
    for(int i = 1; i <= NUM_STARTING_ROBBERS-2; i++){

        if(DEBUG){

            cout << "DEBUG(genStartBoard): creating robber #" << i << endl;
        }

        int newRobberX, newRobberY;

        do{

            newRobberX = generateRand(0, GRID_SIZE - 1);
            newRobberY = generateRand(0, GRID_SIZE - 1);

            if(DEBUG){
                
                cout << "DEBUG(genStartBoard): generating random for robber #" << i << endl;
                cout << "coordinates X, Y: " << newRobberX << " " << newRobberY << endl;
            }

        }while(city.jewelGrid[newRobberX][newRobberY] == 'j' || city.robberGrid1[newRobberX][newRobberY] == 'p' || city.robberGridGreedy1[newRobberX][newRobberY] == 'r' || city.robberGrid2[newRobberX][newRobberY] == 'p' || city.robberGridGreedy2[newRobberX][newRobberY] == 'r');//if there is a jewel or a robber in that spot

        robber newRobber(&city, newRobberX, newRobberY, 0);
        city.robbers[i-1] = newRobber;

        city.updateLetterGrids();
    }

    //greedy robbers
    for(int i = 3; i <= NUM_STARTING_ROBBERS; i++){

        if(DEBUG){

            cout << "DEBUG(genStartBoard): creating greedy robber #" << i << endl;
        }

        int newRobberX, newRobberY;

        do{

            newRobberX = generateRand(0, GRID_SIZE - 1);
            newRobberY = generateRand(0, GRID_SIZE - 1);

        //do it again if there is a robber in the newly generated spot
        }while(city.jewelGrid[newRobberX][newRobberY] == 'j' || city.robberGrid1[newRobberX][newRobberY] == 'p' || city.robberGridGreedy1[newRobberX][newRobberY] == 'r' || city.robberGrid2[newRobberX][newRobberY] == 'p' || city.robberGridGreedy2[newRobberX][newRobberY] == 'r');

        robber newRobber(&city, newRobberX, newRobberY, 1);
        city.robbers[i-1] = newRobber;

        city.updateLetterGrids();

    }


    //-----===== Generate cops =====-----

    if(DEBUG){

        cout << "DEBUG(genStartBoard): creating police #1" << endl;
    }

    int newPoliceX, newPoliceY;

    do{

        newPoliceX = generateRand(0, GRID_SIZE - 1);
        newPoliceY = generateRand(0, GRID_SIZE - 1);

    //do it again if there is a police in the newly generated spot
    }while(city.jewelGrid[newPoliceX][newPoliceY] == 'j' || city.robberGrid1[newPoliceX][newPoliceY] == 'p' || city.robberGridGreedy1[newPoliceX][newPoliceY] == 'r' || city.robberGrid2[newPoliceX][newPoliceY] == 'p' || city.robberGridGreedy2[newPoliceX][newPoliceY] == 'r');

    police newPolice(&city, newPoliceX, newPoliceY);
    city.polices[0] = newPolice;
    
    city.updateLetterGrids();



    //generate second cop
    if(DEBUG){

        cout << "DEBUG(genStartBoard): creating police # 2" << endl;
    }

    do{

        newPoliceX = generateRand(0, GRID_SIZE - 1);
        newPoliceY = generateRand(0, GRID_SIZE - 1);

    //do it again if there is a police in the newly generated spot
    }while(city.jewelGrid[newPoliceX][newPoliceY] == 'j' || city.robberGrid1[newPoliceX][newPoliceY] == 'p' || city.robberGridGreedy1[newPoliceX][newPoliceY] == 'r' || city.robberGrid2[newPoliceX][newPoliceY] == 'p' || city.robberGridGreedy2[newPoliceX][newPoliceY] == 'r' || city.copGrid1[newPoliceX][newPoliceY] == 'c');

    police newPolice2(&city, newPoliceX, newPoliceY);
    city.polices[1] = newPolice2;
    
    city.updateLetterGrids();

}




float distance(const int & firstX, const int & firstY, const int & secondX, const int & secondY){

    // distance = norm(u-v), linear algebra ftw, however this assumes that the grid is continuous, ill just hope this doesnt cause issues later

    //y = u - v

    float yX = firstX - secondX;
    float yY = firstY - secondY;
    //norm(y) = sqrt(dot-prod(y,y))

    return sqrt((yX * yX)+(yY * yY));
}


