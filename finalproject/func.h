//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: func.h

//Other Author: Mason Bateman (mcbqrz, lab section 301, class section 101)

#ifndef FUNC_H
#define FUNC_H

#include "jewel.h"
#include "robber.h"
#include "police.h"

#include <string>

using namespace std;

//-----===== CONSTANTS =====-----

const bool DEBUG = false;
const bool PRINT_GRID_EVERY_ROUND = true;
const int GRID_SIZE = 7;
const int NUM_STARTING_JEWELS = 30;
const int NUM_STARTING_ROBBERS = 4;
const int NUM_STARTING_POLICE = 2;

//-----===== FUNCTIONS =====-----

//description: generates a random number in the range (inclusive)
//pre:input 2 integers, otherwise will set to default, srand is assumed to be pre-seeded in main
//post: returns the random number within the parameters
int generateRand(const int & min = 0, const int & max = 9);

class city;//forward declaration of city so that we can use it in the next function

//description: generates the starting state of the city
//pre: give an initialized city
//post: adds jewels, robbers, and cops to the bored
void generateStartingBoard(city & city);

//description:calculates the distance between a cop an a robber
//pre: pass a cop and a robber by reference
//post: calculates the distance between the two
float distance(const int & firstX, const int & firstY, const int & secondX, const int & secondY);






//description: 
//pre: 
//post: 


#endif


