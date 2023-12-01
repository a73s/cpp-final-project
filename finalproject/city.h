//Author: Adam Seals (agsgv4 section 306)
//date: 11/29/23
//purpose: Final Project
//file: city.h

#ifndef CITY_H
#define CITY_H

#include "func.h"

#include <iostream>
#include <cstdlib>

//description: 
//pre: 
//post: 
class city{

    public:
        
        //description: gets the number of jewels on the board
        //pre: none
        //post: returns the number of jewels on the board
        int getNumJewels() const;

        //description: returns whats in the grid in the location given to it
        //pre: the column you want, starts at 0 at the top, goes to (GRID_SIZE - 1), the row you want, starts at 0 at the left, goes to (GRID_SIZE - 1) on the right
        //post: returns the character from the array
        char getGridLocation(const int column, const int row);

        //description: sets the number of jewels on the board
        //pre: input the number you want to set to
        //post: returns nothing, sets the number of jewels
        void setNumJewels(const int setnum);

        //description: sets a particular 
        //pre: the column you want, starts at 0 at the top, goes to (GRID_SIZE - 1), the row you want, starts at 0 at the left, goes to (GRID_SIZE - 1) on the right. also input the char you want to set that location to.
        //post: returns nothing, changes the grid to your liking
        void setGridLocation(const int column, const int row, const char charToSet);

    private:

        int numJewels;//numbers of jewels on the city grid
        char cityGrid[GRID_SIZE][GRID_SIZE] = {};

    
};





//description: 
//pre: 
//post: 











#endif






