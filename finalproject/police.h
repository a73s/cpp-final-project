//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: police.h

//Other Author: Mason Bateman (mcbqrz, lab section 301, class section 101)

#ifndef POLICE_H
#define POLICE_H

#include "func.h"

#include <iostream>
#include <cstdlib>

//description: 
//pre: 
//post: 
class police{

    public:

        const int pol_id = generateRand(0,9999999); //assign a random id and hope theres no collision

        //description: initializes the police's grid location, this must be run after the creation of the police
        //pre: the coordinate should be within the grid starting at 0 and ending at GRID_SIZE - 1
        //post: returns 1 if there is an error, 0 otherwise, changes robberX and robberY to the desired values. can be run again if there is an error
        bool init(const int X, const int Y, const bool isGreedyInput);

        //description: picks up a jewel thats in the same place as the robber
        //pre: a jewel 
        //post: returns true if theres an error, otherwise return 0. adds the gem to the robber's bag
        //bool pickUpLoot(jewel & j);

        //description: moves the robber by 1 space in a random valid direction
        //pre: robber should be initialized
        //post: 
        //void move();

    private:

    int pol_X;
    int pol_Y;
    int pol_Count;
    int pol_BurgArrested;
    void arrest();
    void move();
};








//description: 
//pre: 
//post: 



#endif






