//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: police.h

//Other Author: Mason Bateman (mcbqrz, lab section 301, class section 101)

#ifndef POLICE_H
#define POLICE_H

#include "func.h"
#include "jewel.h"

#include <iostream>
#include <cstdlib>

class city;//forward declaration


//description: 
//pre: 
//post: 
class police{

    public:

        police(){}

        //description: initializes the police's grid location, this must be run after the creation of the police
        //pre: the coordinate should be within the grid starting at 0 and ending at GRID_SIZE - 1
        //post: returns 1 if there is an error, 0 otherwise, changes robberX and robberY to the desired values. can be run again if there is an error
        police(city* city, const int X, const int Y, const bool isActive = true);

        void arrest();

        void move(city* city);

        void tryArrest(city* c);
        
        

        //description: picks up a jewel thats in the same place as the robber
        //pre: a jewel 
        //post: returns true if theres an error, otherwise return 0. adds the gem to the robber's bag
        //bool pickUpLoot(jewel & j);

        //-----====== Getters and setters =====-----

        int getX(){return policeX;}

        int getY(){return policeY;}

        bool isActive(){return active;}

        bool isInitialized(){return initialized;}

    private:

        void arrest(robber & theRobber, city* c);

        bool active = false;
        bool initialized = false;

        static int currentId;
        static int collectiveConfiscateValue;

        int id;
        int policeX;
        int policeY;
        int confiscatedValue;
    
};








//description: 
//pre: 
//post: 



#endif






