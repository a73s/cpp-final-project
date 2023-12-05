//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: robber.h

#ifndef ROBBER_H
#define ROBBER_H

#include "func.h"
#include "jewel.h"

#include <iostream>
#include <cstdlib>


//description: 
//pre: 
//post: 
class robber{

    public:


        

        robber(){}//default constructor

        //description: initializes the robber's grid location, this must be run after the creation of the robber
        //pre: the coordinate should be within the grid starting at 0 and ending at GRID_SIZE - 1
        //post: returns 1 if there is an error, 0 otherwise, changes robberX and robberY to the desired values. can be run again if there is an error
        robber(const int X, const int Y, const bool isGreedyInput);
        
        //description: picks up a jewel thats in the same place as the robber
        //pre: a jewel 
        //post: returns true if theres an error, otherwise return 0. adds the gem to the robber's bag
        bool pickUpLoot(jewel j);

        //description: moves the robber by 1 space in a random valid direction
        //pre: robber should be initialized
        //post: 
        //void move();
        void move(char robberGrid[][GRID_SIZE], char robberGridGreedy[][GRID_SIZE]);

        /*
        //description: 
        //pre: 
        //post: 
        void getArrested()
        */

    private:


        int id;//increment then assign id
        
        bool initialized = false;
        int robberX = -1, robberY = -1;//x values start at 0 at the left and go to GRID_SIZE - 1 at the right, same for y values except top to bottom
        int gemBag = 0;
        int bagValue = 0;

        static int currentId;
        static int collectiveBagValue;
    
        bool active = true;
        bool isGreedy = 0;//50/50 chance of being greedy if the default constructor is run

};











//description: 
//pre: 
//post: 


#endif






