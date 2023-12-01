//Author: Adam Seals (agsgv4 section 306)
//date: 11/29/23
//purpose: Final Project
//file: robber.h

#ifndef ROBBER_H
#define ROBBER_H

#include "func.h"

#include <iostream>
#include <cstdlib>

//description: 
//pre: 
//post: 
class robber{

    public:

        const unsigned long int id = generateRand(0,18446744073709551614);//assign a random id in the range of an unsigned long int

        //description: initializes the robber's grid location, this must be run after the creation of the robber
        //pre: the coordinate should be within the grid starting at 0 and ending at GRID_SIZE - 1
        //post: returns 1 if there is an error, 0 otherwise, changes robberX and robberY to the desired values. can be run again if there is an error
        void init(const int X, const int Y);
        
        //description: picks up a jewel thats in the same place as the robber
        //pre: a jewel 
        //post: returns true if theres an error, otherwise return 0. adds the gem to the robber's bag
        bool pickUpLoot(jewel & j);

    private:

        bool initialized = false;
        int robberX = -1, robberY = -1;//x values start at 0 at the left and go to GRID_SIZE - 1 at the right, same for y values except top to bottom
        int gemBag = 0;
        int bagValue = 0;
        bool active = true;
        bool isGreedy = generateRand(0,1);//50/50 chance of being greedy or not

};











//description: 
//pre: 
//post: 


#endif






