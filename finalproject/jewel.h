//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: jewel.h

//Other Author: Mason Bateman (mcbqrz, lab section 301, class section 101)

#ifndef JEWEL_H
#define JEWEL_H

#include "func.h"

#include <iostream>
#include <cstdlib>


//description: 
//pre: 
//post: 
class jewel{

    public:

        friend class robber;
        friend class police;

        //-----====== Constructors =====-----

        jewel(){}

        //description: sets the values for the jewel, must be run after creation of the jewel, can only be run once, unless there is an error
        //pre: input the initial X, Y, and value of the jewel, the X and Y should be within the bounds of the board and the jewel value should be positive
        //post: the function will check if the X and Y are in the board returns 1 if there is an error, otherwise it will return 0, if there is an error the function may be run again
        jewel(const int X, const int Y, const int value);


        //-----====== Getters and setters =====-----

        //description: retrieves the x coordinate of the jewel
        //pre: should be initialized befor calling, otherwise will return -1 no matter what
        //post: returns the x coordinate of the jewel
        int getX() const;

        //description: retrieves the Y coordinate of the jewel
        //pre: should be initialized befor calling, otherwise will return -1 no matter what
        //post: returns the Y coordinate of the jewel
        int getY() const;

        //description: retrieves the value of the jewel
        //pre: should be initialized befor calling, otherwise will return -1 no matter what
        //post: returns the value og the jewel
        int getValue() const;

        bool pickedUp() const{return isPickedUp;}


        bool initialized = false;

    private: 

        bool isPickedUp = false;
        bool confiscated = false;
        int jewelValue = -1;
        int originalX = -1, originalY = -1;//x values start at 0 at the left and go to GRID_SIZE - 1 at the right, same for y values except top to bottom
    
};








//description: 
//pre: 
//post: 





#endif






