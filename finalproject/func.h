//Author: Adam Seals (agsgv4)
//date: 11/29/23
//purpose: Final Project
//file: func.h

#ifndef FINC_H
#define FUNC_H

#include <string>
using namespace std;

//-----===== CONSTANTS =====-----

const bool DEBUG = false;

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







//description: 
//pre: 
//post: 


#endif


