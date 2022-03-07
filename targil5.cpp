/*
Name: Efraim Rahamim
T.Z. 315392621
Class: 09
*/

#include <iostream>
#include "targil5_dec.h"
#include<string.h>
using namespace std;


int main()
{
    //declaring on "Player" and "Team" array
    Player* ptrPlayer = NULL;
    Team* ptrTeam = NULL;
    //the size of the arrays
    int playerSize = 0;
    int teamSize = 0;
    //the choise of the user
    int choise;
    ptrPlayer = new Player[playerSize];
    ptrTeam = new Team[teamSize];
    //as long as the user did not put 11, the program will run
    do
    {
        printMenu();
        cin >> choise;
        //checking if the input is valid
        while (choise < 1 || choise>11)
        {
            cout << "Error: Try Again!" << endl << endl;
            printMenu();
            cin >> choise;
        }
        //operate the user choise
        sortOfChoise(choise, playerSize, teamSize, ptrPlayer, ptrTeam);
    } while (choise != 11);
}

