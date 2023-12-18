//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: main.cpp

//Other Author: Mason Bateman (mcbqrz, lab section 301, class section 101)

/*
NOTES TO GRADER:

I dont have time to finish the assignment, ill make this easy, heres the rundown:

**to the best of my knowledge**
THINGS THAT WORK:

all of the basic functionality works, the game compiles and runs, everything moves, picks up jewels, and arrests as you would expect.

all of extra credits are implemented, there is a comment in front and behind the section of code that implements the extra credit (robber.cpp -> robber::move())

I know I should have done that last but I didnt think I would have a problem finishing

THINGS THAT DONT WORK:

There should be more output to the console during the game

the greedy robbers dont drop their loot when they run into another robber

cops exchanging loot is messed up and the value of their confiscations is way higher than it should be


THINGS THAT WORK DIFFERENTLY THAN THEY SHOULD:

the greedy robber moving tword the cop works slightly differently.
the robber just makes moves that lower the distance to the nearest cop, 
if the distances to each cop is equal, than the robber will just continue to make moves that lower the distance

The city grid is not just one grid. I did this to make it easier to quickly tell what characters are where
also i regret not making these private


FINAL NOTES:

You can turn on debug options in func.h, there is a lot more output if you turn that on

as is the grid is printed out every round, if this overflows your terminal you can turn it off in func.h

I was getting errors in several places where one class contained the second class but the second class also reference the first
and the best solution I could find is to use pointers to refer back to the first class. I know we havent covered these in class and I kinda 
had to learn them on my own but this was the only way to make it work the way I wanted without too much pain.

Have a great winter break!!!!
*/

#include "jewel.h"
#include "robber.h"
#include "city.h"
#include "func.h"
#include "police.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    srand(100);
    
    //-----===== Welcome message =====-----
    
    cout << "-----===== The Urban Jewel Heist =====-----" << endl;

    city city;

    generateStartingBoard(city);

    //Print the starting grid
    cout << "The starting grid: " << endl;
    city.printGrid();


    int round = 0;
    bool anotherRound = true;

    do{

        round++;
        cout << "It is round #" << round << " of 50." << endl;

        //move police and robbers

        for(int i = 0; i < NUM_STARTING_POLICE; i++){//move police

            city.polices[i].move(&city);
        }

        for(int i = 0; i < NUM_STARTING_ROBBERS; i++){//move robbers

            city.robbers[i].move(&city);
        }

        //check for bribes and arrests

        for(int i = 0; i < NUM_STARTING_ROBBERS; i++){//greedy robber attempt to bribe the cops

            if(city.robbers[i].getGreeyness()){

                city.robbers[i].tryBribe(&city);
            }
        }
        

        for(int i = 0; i < NUM_STARTING_POLICE; i++){//police arrest any robbers in their squares

            city.polices[i].tryArrest(&city);
        }

        if(PRINT_GRID_EVERY_ROUND){
            city.printGrid();
        }

        cout << "The robbers collective gem value is: $" << city.robbers[0].getCollectiveBagValue() << endl;

        //win conditions

        if(city.robbers[0].getCollectiveBagValue() > 2023){

            cout << "Robbers win by bribing all of the cops." << endl;

            anotherRound = false;
        }

        if(round >= 50){

            cout << "Max round reached, ending game." << endl;

            anotherRound = false;
        }

        if(city.numCopsBribed >= NUM_STARTING_POLICE){

            cout << "All of the cops have been bribed by the robbers, robbers win." << endl;

            anotherRound = false;
        }

        if(city.numRobbersArrested >= NUM_STARTING_ROBBERS){

            cout << "All of the robbers have been arrested by the cops, cops win." << endl;

            anotherRound = false;
        }

    }while(anotherRound);

    cout << "The final grid:" << endl;
    city.printGrid();

    return 0;
}







