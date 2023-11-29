//Author: Adam Seals (agsgv4 section 306)
//date: 11/29/23
//purpose: Final Project
//file: city.h

#ifndef CITY_H
#define CITY_H

#include "func.h"

#include <iostream>
#include <cstdlib>


class city{

    public:
        
        //description: gets the number of jewels on the board
        //pre: none
        //post: returns the number of jewels on the board
        int getNumJewels();

        //description: returns whats in the grid in the location given to it
        //pre: the column you want, starts at 0 at the top, goes to (GRID_SIZE - 1), the row you want, starts at 0 at the left, goes to (GRID_SIZE - 1) on the right
        //post: returns the character from the array
        char getGridLocation(int column, int row);

    private:

        int numJewels;//numbers of jewels on the city grid
        char cityGrid[GRID_SIZE][GRID_SIZE] = {};

    
};





//description: 
//pre: 
//post: 











#endif






