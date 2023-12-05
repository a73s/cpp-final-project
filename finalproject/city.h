//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: city.h

#ifndef CITY_H
#define CITY_H




#include "func.h"
#include "robber.h"
#include "jewel.h"

#include <iostream>
#include <cstdlib>

//class robber;//fixes error, same as the pointer on the robber array

//description: 
//pre: 
//post: 
class city{

    public:

    //description: 
    //pre: 
    //post: 
    void updateLetterGrids();

    //description: 
    //pre: 
    //post: 
    void printGrid();

    int numJewels = 0;

    //each grid starts at x=0 and y=0 in the top left and ends at x=GRID_SIZE-1 and y=GRID_SIZE-1 in the bottom right
    char jewelGrid[GRID_SIZE][GRID_SIZE] = {};

    char robberGrid[GRID_SIZE][GRID_SIZE] = {};//'p' for normal robber
    char robberGridGreedy[GRID_SIZE][GRID_SIZE] = {};// 'r' for greedy robber
    bool isAnotherRobber[GRID_SIZE][GRID_SIZE] = {};

    char copGrid[GRID_SIZE][GRID_SIZE] = {};

    robber robbers[NUM_STARTING_ROBBERS] = {};
    jewel jewels[NUM_STARTING_JEWELS] = {};

    private:

    
};





//description: 
//pre: 
//post: 











#endif






