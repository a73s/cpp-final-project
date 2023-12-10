//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: main.cpp

//Other Author: Mason Bateman (mcbqrz, lab section 301, class section 101)

/*
Notes to grader:
1. You can turn on debug options in func.h, there is a lot of output though
2. all of extra credit are implemented, there is a comment in front and behind the section of code that implements the extra credit (robber.cpp -> robber::move())
3. I was getting errors in several placed where one class contained the second class but the second class also reference the first
and the best solution I could find is to use pointers to refer back to the first class. I know we havent covered these in class and I kinda had to learn them on my own
but this was the only way to make it work the way I wanted without too much pain
*/

/*
to do 
change random seed back to 100
write function documentation
implement bribery for greedy robbers
implement dropping jewels when a greedy robber meets another robber
make outputs throught the game
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

    srand(time(NULL));
    
    //-----===== Welcome message =====-----
    
    cout << "-----===== The Urban Jewel Heist =====-----" << endl;

    city city;

    generateStartingBoard(city);

    //Print the starting grid
    cout << "The starting grid: " << endl;
    city.printGrid();

    /*
    bool moveAgain;
    //some test code
    do{

        city.polices[0].move(&city);
        city.robbers[2].move(&city);
        city.printGrid();

        cout << "Move again?(1/0) ";
        cin >> moveAgain;

    }while(moveAgain);
    */

    int round = 0;
    bool anotherRound = true;
    do{

        round++;
        cout << "It is round #" << round << " of 50." << endl;

        for(int i = 0; i < NUM_STARTING_POLICE; i++){//move police

            city.polices[i].move(&city);
        }

        for(int i = 0; i < NUM_STARTING_ROBBERS; i++){//move robbers

            city.robbers[i].move(&city);
        }

        
        for(int i = 0; i < NUM_STARTING_ROBBERS; i++){//greedy robber attempt to bribe the cops, this will check if they are in the same spot

            if(city.robbers[i].isGreedy){

                city.robbers[i].tryBribe(&city);
            }
        }
        

        for(int i = 0; i < NUM_STARTING_POLICE; i++){//police arrest any robbers in their squares

            city.polices[i].tryArrest(&city);
        }

        city.printGrid();

        cout << "The robbers collective gem value is: $" << city.robbers[0].getCollectiveBagValue() << endl;

        if(city.robbers[0].getCollectiveBagValue() > 2023){

            cout << "Robbers win by bribing all of the cops." << endl;

            anotherRound = false;
        }

        for(int i = 0; i < NUM_STARTING_ROBBERS; i++){//move robbers

            city.robbers[i].move(&city);
        }

        if(round >= 50){

            cout << "Max round reached, ending game." << endl;

            anotherRound = false;
        }

    }while(anotherRound);

    cout << "The final grid:" << endl;
    city.printGrid();

    return 0;
}







