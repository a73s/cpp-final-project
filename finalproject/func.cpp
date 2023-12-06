//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: func.cpp

//Other Author: Mason Bateman (mcbqrz, lab section 301, class section 101)

#include "func.h"

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//-----===== FUNCTION DEFINITIONS =====-----

int generateRand(const int & min, const int & max){

    return (rand()%(max-min+1)+min);
}






