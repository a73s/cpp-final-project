//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: police.cpp

//Other Author: Mason Bateman (mcbqrz, lab section 301, class section 101)

#include "func.h"
#include "police.h"
#include "city.h"

#include <iostream>
#include <cstdlib>

class city;//forward declaration of city

//-----====== Static member variables =====-----

int police::collectiveConfiscateValue = 0;

int police::currentId = 4;


//-----====== Constructors =====-----


police::police(city* city, const int X, const int Y, const bool isActive){

    if(city->isValidMove(X, Y)){//if the coordinates are within the grid and the value is positive

        initialized = true;
        policeX = X;
        policeY = Y;
        id = ++currentId;//increment then assign id
        active = isActive;

    }else{

        if(DEBUG){
            cout << "ERROR: police constructor failed, police coordinates out of range" << endl;
        }

        initialized = false;
    }

    return;
}



void police::move(city* c){

    if(!initialized || !active){//do not run function if the police is not initialized

        if(DEBUG){
            cout << "DEBUG(police.move): cop not initialized or not active, therefore not moved" << endl;
        }

        return;
    }

    int moveDownAmount = 0, moveRightAmount = 0;
    int newx = policeX, newy = policeY;

    do{//we can only get away with using a do while loop because there is never a situation where there is not an open space to move to
        
        if(DEBUG){

            cout << "DEBUG(police.move):finding coordinates for police move" << endl;
        }

        int choice = generateRand(0,7);

        switch(choice){

            case 0:{
                
                moveDownAmount = -1;
                moveRightAmount = -1;
                break;
            }
            case 1:{

                moveDownAmount = -1;
                moveRightAmount = 0;
                break;
            }
            case 2:{
                
                moveDownAmount = -1;
                moveRightAmount = 1;
                break;
            }
            case 3:{
                
                moveDownAmount = 0;
                moveRightAmount = -1;
                break;
            }
            case 4:{

                moveDownAmount = 0;
                moveRightAmount = 1;                
                break;
            }
            case 5:{
                
                moveDownAmount = 1;
                moveRightAmount = -1;
                break;
            }
            case 6:{
                
                moveDownAmount = 1;
                moveRightAmount = 0;
                break;
            }
            case 7:{
                
                moveDownAmount = 1;
                moveRightAmount = 1;
                break;
            }
        }

        newx = policeX + moveRightAmount;
        newy = policeY + moveDownAmount;

    }while(!(c->isValidMove(newx, newy)));//redo if it would move us out of bounds

    policeX = newx;
    policeY = newy;


    if(DEBUG){

        cout << "DEBUG(police.move): The new x is " << newx << endl;
        cout << "DEBUG(police.move): The new y is " << newy << endl;
    }

    c->updateLetterGrids();//refresh the grid after move

    return;
}


