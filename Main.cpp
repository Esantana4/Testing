/*
 Erik Santana
 9/16/23
 CPMR 131 - Professor Q

 Description:

 Part 1: Tic-Tac-Toe game
 Part 2: Tower Of Hanoi
 Part 3: n-Queens

 Credit:
 Joe Bryant & Erik Santana - Tic-Tac-Toe game
 Saul Merino & John Kim - Tower Of Hanoi
 Otoniel Torres Bernal & Thanh Tran - n-Queens
 */

#include "input.h"
#include <iostream>
#include "TicTacToe.h"

using namespace std;

void mainMenu();

int main()
{

    mainMenu();

    return 0;
}

// Pre-Condition: NA
// Post-Condition: no return. Main menu
void mainMenu()
{
    int gamesPlayed = 1;

    // Main Menu

    cout << endl;
    cout << "\tCMPR131 - Chapter 3 Containers Assignment by Erik Santana (9 / 16 / 23)";
    cout << "\n\t" << string(80, char(205)) << endl;
    cout << "\t1> Tic-Tac-Toe" << endl;
    cout << "\t2> Tower Of Hanoi" << endl;
    cout << "\t3> n-Queens" << endl;
    cout << "\n\t" << string(80, char(169));
    cout << "\n\t0 > exit" << endl;
    cout << "\n\t" << string(80, char(205)) << endl;

    // get user input/option of main menu
    int option = inputInteger("\n\tOption: ", 0, 3);

    // loop through main menu until user exits
    do
    {
        switch (option)
        {
        case 0: exit(1); break;
        case 1: system("cls"); ticTacToe(); break;
        case 2: system("cls"); break;
        case 3: system("cls"); break;

        }

        // new line
        cout << "\n";

    } while (true);
}
