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

class police{

    public:

        friend class robber;

        police(){}

        //description: initializes the police's grid location, this must be run after the creation of the police
        //pre: the coordinate should be within the grid starting at 0 and ending at GRID_SIZE - 1
        //post: returns 1 if there is an error, 0 otherwise, changes robberX and robberY to the desired values. can be run again if there is an error
        police(city* city, const int X, const int Y, const bool isActive = true);

        //description: moves teh robber throught the city
        //pre: none
        //post: changes everything
        void move(city* city);

        //description: checks if there are any robbers to arrest, then arrests them by calling the arrest function
        //pre: pass in city
        //post: calls the arrest function if the cop can arrest a robber
        void tryArrest(city* c);

        //-----====== Getters and setters =====-----

        int getX() const {return policeX;}

        int getY() const {return policeY;}

        bool isActive() const {return active;}

        bool isInitialized() const {return initialized;}

        int getid() const {return id;}

    private:

        //description: arrests the robber passed
        //pre: pass robber and pass city adderess into pointer
        //post: changes the robber to be inactive and changes the city grid to reflect that
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





#endif






