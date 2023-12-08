//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: main.cpp

//Other Author: Mason Bateman (mcbqrz, lab section 301, class section 101)

/*
Note to grader: You can turn on debug options in func.h, there is a lot of output though
all 30 points of extra credit are implemented, there is a comment in front and behind the section of code that implements the extra credit (robber.cpp -> robber::move())
*/

/*
note to mason: 
1. put your name, username, and sections at the top of every file
2. if you need to debug output do this:

if(DEBUG){

    cout << "DEBUG(main): initializing jewel #" << i << endl;
}

3. always use "g++ -Wall -W -s -pedantic-errors" when compiling, this is equivalent to fg++ on the school machines.
4. use a branch when making changes, dont commit directly to main
*/

/*
to do 
change random seed back to 100
make stuff happen when characters meet in the same square
add grid of inactive robbers and cops and such
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
    //*/




    return 0;
}







