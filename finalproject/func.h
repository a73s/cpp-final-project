//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: func.h

#ifndef FUNC_H
#define FUNC_H

#include <string>
using namespace std;

//-----===== CONSTANTS =====-----

const bool DEBUG = true;
const int GRID_SIZE = 7;
const int NUM_STARTING_JEWELS = 30;
const int JEWEL_MIN_VALUE = 10;
const int JEWEL_MAX_VALUE = 1000;

//-----===== FUNCTIONS =====-----

//description: swaps any 2 variables of the same type
//pre: any two variables of the same kind as input
//post: returns nothing, swaps the values
namespace myTemplates{

    template <typename U>
    void swap(U & v1, U & v2){

        U temp = v1;
        v1 = v2;
        v2 = temp;

        return;
    }
}

//description: generates a random number in the range (inclusive)
//pre:input 2 integers, otherwise will set to default, srand is assumed to be pre-seeded in main
//post: returns the random number within the parameters
int generateRand(const int & min = 0, const int & max = 9);

//description: generates a random number in the range (inclusive)
//pre:input 2 integers, otherwise will set to default, srand is assumed to be pre-seeded in main
//post: returns the random number within the parameters
unsigned long int generateBigRand(const unsigned long int & min = 0, const unsigned long int & max = 9);







//description: 
//pre: 
//post: 


#endif


