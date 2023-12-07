//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: robber.h

//Other Author: Mason Bateman (mcbqrz, lab section 301, class section 101)

#ifndef ROBBER_H
#define ROBBER_H

#include "func.h"
#include "jewel.h"

#include <iostream>
#include <cstdlib>

class city;//fixes error
class jewel;

//description: 
//pre: 
//post: 
class robber{

    public:

        // -----===== constructors =====------

        robber(){}//default constructor

        //description: initializes the robber's grid location, this must be run after the creation of the robber
        //pre: the coordinate should be within the grid starting at 0 and ending at GRID_SIZE - 1
        //post: returns 1 if there is an error, 0 otherwise, changes robberX and robberY to the desired values. can be run again if there is an error
        robber(city* city, const int X, const int Y, const bool isGreedyInput, const bool isActive = true);
        

        //-----====== functions =====-----

        //description: picks up a jewel thats in the same place as the robber
        //pre: a jewel 
        //post: returns true if theres an error, otherwise return 0. adds the gem to the robber's bag
        bool pickUpLoot(jewel & j);

        //description: moves the robber by 1 space in a random valid direction
        //pre: robber should be initialized and active
        //post: moves the robber and redraws the board
        void move(city* c);


        /*
        //description: 
        //pre: 
        //post: 
        void getArrested()
        */


        //-----====== Getters and setters =====-----

        int getX();

        int getY();

        bool isActive();

        bool isInitialized();


        //-----====== Friends =====------  

        //friend distance(robber & robber, police & cop);  
      

    private:


        int id;

        int robberX = -1, robberY = -1;//x values start at 0 at the left and go to GRID_SIZE - 1 at the right, same for y values except top to bottom
        int gemBag = 0;
        int bagValue = 0;
        int movesSinceJewel = 0;
        int immobilized = 0;

        static int currentId;
        static int collectiveBagValue;

        bool active = true;
        bool initialized = false;
        bool isGreedy = 0;//normal by default

        //description: checks if there is a jewel within 1 move of the robber
        //pre: input the city that the robber is on, input by pointer cuz its the only way to avoid bug (because both robber and city reference eachother, trust me i tried everything)
        //post: returns true if there is a gem nearby
        bool isAJewelClose(city* city);

};











//description: 
//pre: 
//post: 


#endif






