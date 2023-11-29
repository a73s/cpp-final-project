//Author: Adam Seals
//date: 11/13/23
//purpose: HW7
//file: func.cpp

#include "func.h"

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//-----===== FUNCTION DEFINITIONS =====-----

int generateRand(const int & min, const int & max){

    return (rand()%(max-min+1)+min);
}





