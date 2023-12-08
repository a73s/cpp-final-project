//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: city.h

//Other Author: Mason Bateman (mcbqrz, lab section 301, class section 101)

#ifndef CITY_H
#define CITY_H

#include "func.h"
#include "robber.h"
#include "jewel.h"
#include "police.h"

#include <iostream>
#include <cstdlib>

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

    //description: checks to see if the future position is within the area of the grid
    //pre: pass coordinates to check if that location is valid
    //post: returns true if in the grid otherwits false
    bool isValidMove(const int & X, const int & Y) const;

    int numJewels = 0;

    //each grid starts at x=0 and y=0 in the top left and ends at x=GRID_SIZE-1 and y=GRID_SIZE-1 in the bottom right
    char jewelGrid[GRID_SIZE][GRID_SIZE] = {};


    //theres one for each robber
    //'p' for normal robber, 'r' for greedy robber
    char robberGrid1[GRID_SIZE][GRID_SIZE] = {};//robber 1
    char robberGrid2[GRID_SIZE][GRID_SIZE] = {};//robber 2

    char robberGridGreedy1[GRID_SIZE][GRID_SIZE] = {};// greedy robber 1
    char robberGridGreedy2[GRID_SIZE][GRID_SIZE] = {};// greedy robber 2

    char copGrid1[GRID_SIZE][GRID_SIZE] = {};
    char copGrid2[GRID_SIZE][GRID_SIZE] = {};

    char inactiveCopGrid[GRID_SIZE][GRID_SIZE] = {};
    char inactiveRobberGrid[GRID_SIZE][GRID_SIZE] = {};

    robber robbers[NUM_STARTING_ROBBERS] = {};// should be placed in this order: robber 1, robber 2, greedy robber 1, greedy robber 2
    jewel jewels[NUM_STARTING_JEWELS] = {};
    police polices[NUM_STARTING_POLICE] = {};

    private:

    
};





//description: 
//pre: 
//post: 











#endif






