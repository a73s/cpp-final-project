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

/*
to do 
make the robber class modify the city grid when the robber moves
change random seed back to 100
add police to many member functions when police class is complete 
*/

#include "jewel.h"

#include "robber.h"
#include "city.h"


#include "func.h"
#include "police.h"

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    srand(time(NULL));

    city city;

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
        city.updateLetterGrids();
    }

    

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

        }while(city.jewelGrid[newRobberX][newRobberY] == 'j' || city.robberGrid1[newRobberX][newRobberY] == 'p' || city.robberGridGreedy1[newRobberX][newRobberY] == 'r' || city.robberGrid2[newRobberX][newRobberY] == 'p' || city.robberGridGreedy2[newRobberX][newRobberY] == 'r');//if there is a jewel or a robber in that spot

        robber newRobber(newRobberX, newRobberY, 0);
        city.robbers[i-1] = newRobber;

        if(i == 1){
            city.robberGrid1[newRobberX][newRobberY] = 'p';
        }
        if(i == 2){
            city.robberGrid2[newRobberX][newRobberY] = 'p';
        }
    }

    //greedy robbers
    for(int i = 3; i <= NUM_STARTING_ROBBERS; i++){

        if(DEBUG){

            cout << "DEBUG(main): creating greedy robber #" << i << endl;
        }

        int newRobberX, newRobberY;

        do{

            newRobberX = generateRand(0, GRID_SIZE - 1);
            newRobberY = generateRand(0, GRID_SIZE - 1);

        }while(city.jewelGrid[newRobberX][newRobberY] == 'j' || city.robberGrid1[newRobberX][newRobberY] == 'p' || city.robberGridGreedy1[newRobberX][newRobberY] == 'r' || city.robberGrid2[newRobberX][newRobberY] == 'p' || city.robberGridGreedy2[newRobberX][newRobberY] == 'r');

        robber newRobber(newRobberX, newRobberY, 1);
        city.robbers[i-1] = newRobber;
        
        if(i == 3){
            city.robberGridGreedy1[newRobberX][newRobberY] = 'r';
        }
        if(i == 4){
            city.robberGridGreedy2[newRobberX][newRobberY] = 'r';
        }

    }



    //-----===== Generate cops =====-----







    //Print the starting grid
    cout << "The starting grid: " << endl;
    city.printGrid();
    //city.updateLetterGrids();




    return 0;
}







