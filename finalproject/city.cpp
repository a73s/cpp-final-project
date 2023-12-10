//Author: Adam Seals (agsgv4 lab section 306, class section 101)
//date: 11/29/23
//purpose: Final Project
//file: city.cpp

//Other Author: Mason Bateman (mcbqrz, lab section 301, class section 101)

#include "func.h"
#include "jewel.h"
#include "city.h"
#include "police.h"

#include <iostream>
#include <cstdlib>

using namespace std;


void city::updateLetterGrids(){

    //clear grids

    for(int i = 0; i < GRID_SIZE; i++){

        for(int j = 0; j < GRID_SIZE; j++){

            jewelGrid[i][j] = ' ';
        }
    }

    for(int i = 0; i < GRID_SIZE; i++){

        for(int j = 0; j < GRID_SIZE; j++){

            robberGrid1[i][j] = ' ';
        }
    }

    for(int i = 0; i < GRID_SIZE; i++){

        for(int j = 0; j < GRID_SIZE; j++){

            robberGrid2[i][j] = ' ';
        }
    }

    for(int i = 0; i < GRID_SIZE; i++){

        for(int j = 0; j < GRID_SIZE; j++){

            robberGridGreedy1[i][j] = ' ';
        }
    }

    for(int i = 0; i < GRID_SIZE; i++){

        for(int j = 0; j < GRID_SIZE; j++){

            robberGridGreedy2[i][j] = ' ';
        }
    }

   for(int i = 0; i < GRID_SIZE; i++){

        for(int j = 0; j < GRID_SIZE; j++){

            copGrid1[i][j] = ' ';
        }
    }

    for(int i = 0; i < GRID_SIZE; i++){

        for(int j = 0; j < GRID_SIZE; j++){

            copGrid2[i][j] = ' ';
        }
    }

    for(int i = 0; i < GRID_SIZE; i++){

        for(int j = 0; j < GRID_SIZE; j++){

            inactiveCopGrid[i][j] = ' ';
        }
    } 

    for(int i = 0; i < GRID_SIZE; i++){

        for(int j = 0; j < GRID_SIZE; j++){

            inactiveRobberGrid[i][j] = ' ';
        }
    }

    //put the jewels back on the grid
    for(int i = 0; i < NUM_STARTING_JEWELS; i++){

        if(!jewels[i].pickedUp() && jewels[i].initialized){

            jewelGrid[jewels[i].getX()][jewels[i].getY()] = 'j';
        }

    }

    //put robbers back on the grid
    for(int i = 0; i < NUM_STARTING_ROBBERS; i++){

        robber tempRobber = robbers[i];

        if(!tempRobber.isInitialized()){//if robber is not initialized or not active we skip that robber

            continue;
        }

        if(!tempRobber.isActive()){

            inactiveRobberGrid[tempRobber.getX()][tempRobber.getY()] = 'R';
            continue;
        }

        switch(i){
            case 0:{

                robberGrid1[tempRobber.getX()][tempRobber.getY()] = 'p';
                break;
            }
            case 1:{

                robberGrid2[tempRobber.getX()][tempRobber.getY()] = 'p';
                break;
            }
            case 2:{
                    
                robberGridGreedy1[tempRobber.getX()][tempRobber.getY()] = 'r';
                break;
            }
            case 3:{
                    
                robberGridGreedy2[tempRobber.getX()][tempRobber.getY()] = 'r';
                break;
            }
        }
    }

    //put cops back on the grid

    for(int i = 0; i < NUM_STARTING_POLICE; i++){

        police copCopy = polices[i];

        if(!copCopy.isInitialized()){

            continue;
        }

        if(!copCopy.isActive()){

            inactiveCopGrid[copCopy.getX()][copCopy.getY()] = 'C';
            continue;
        }

        switch(i){
            case 0:{

                copGrid1[copCopy.getX()][copCopy.getY()] = 'c';
                break;
            }
            case 1:{

                copGrid2[copCopy.getX()][copCopy.getY()] = 'c';
                break;
            }
        }
    }
}


void city::printGrid(){

    cout << " |0      |1      |2      |3      |4      |5      |6      |Y"<< endl;

    for(int i = 0; i < GRID_SIZE; i++){

        cout << "----------------------------------------------------------" << endl;

        cout << i;

        for(int j = 0; j < GRID_SIZE; j++){
            
            int tempNumThings = 0;
            cout << "|";

            if(jewelGrid[i][j] == 'j'){

                cout << 'j';
                tempNumThings++;
            }

            if(robberGrid1[i][j] == 'p'){

                cout << 'p';
                tempNumThings++;
            }

            if(robberGrid2[i][j] == 'p'){

                cout << 'p';
                tempNumThings++;
            }

            if(robberGridGreedy1[i][j] == 'r'){

                cout << 'r';
                tempNumThings++;
            }

            if(robberGridGreedy2[i][j] == 'r'){

                cout << 'r';
                tempNumThings++;
            }

            if(copGrid1[i][j] == 'c'){

                cout << 'c';
                tempNumThings++;
            }

            if(copGrid2[i][j] == 'c'){

                cout << 'c';
                tempNumThings++;
            }

            if(inactiveCopGrid[i][j] == 'C'){

                cout << 'B';
                tempNumThings++;
            }

            if(inactiveRobberGrid[i][j] == 'R'){

                cout << 'A';
                tempNumThings++;
            }

            for(int k = 0; k < 7 - tempNumThings; k++){//allows us to keep the spacing consistent

                cout << ' ';
            }
        }

        cout << '|' << endl;

    }

    cout << "----------------------------------------------------------" << endl;
    cout << "X" << endl;  
    cout << "Key: " << "                                               N" << endl;
    cout << "       robber: \'p\'" << "                                  |" << endl;
    cout << "greedy robber: \'r\'" << "                              W---|---E" << endl;
    cout << "        jewel: \'j\'" << "                                  |" << endl;
    cout << "          cop: \'c\'" << "                                  S" << endl;
    cout << "     Arrested: \'A\'" << endl;
    cout << "       Bribed: \'B\'" << endl;
    cout << endl;
}



bool city::isValidMove(const int & X, const int & Y) const{

    if(X < GRID_SIZE && X > -1 && Y < GRID_SIZE && Y > -1){

        return true;
    }

    return false;
}



