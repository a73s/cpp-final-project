//Author: Adam Seals (agsgv4 section 306)
//date: 11/29/23
//purpose: Final Project
//file: city.cpp

#include "func.h"
#include "city.h"

#include <iostream>
#include <cstdlib>


int city::getNumJewels() const{

    return numJewels;
}


char city::getGridLocation(const int column, const int row){

    return cityGrid[column][row];
}


void city::setNumJewels(const int setnum){

    numJewels = setnum;
    return;
}