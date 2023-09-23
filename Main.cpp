/*
 Erik Santana
 9/21/23
 CPMR 131 - Professor Q

 Description:
 Part 1: Complex Numbers - This class multiplies, divides, adds, subtracts 2 complex numbers. This class also checks if 2 complex numbers are equal or not.
 Part 2: Rational Numbers - 
 Part 3: Polynomials - 

 Credit:
 Part 1: Complex Numbers - Joe Bryant & Erik Santana & Christian Hernandez
 Part 2: Rational Numbers - Thanh Tran & John Kim
 Part 3: Polynomials - Otoniel Torres Bernal & Saul Merino
 */

#include "ComplexNumbers.h"
#include "input.h"

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
    ComplexNumbers complexNumbersObject;

    cout << endl;
    cout << "\tCMPR131 - Chapter 4: Complex Numbers, Rational Numbers, Polynomials by Erik Santana (9 / 21 / 23)";
    cout << "\n\t" << string(80, char(205)) << endl;
    cout << "\t1> Complex Numbers" << endl;
    cout << "\t2> Rational Numbers" << endl;
    cout << "\t3> Polynomials" << endl;
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
        case 1: system("cls"); complexNumbersObject.complexMenu(); break;
        case 2: system("cls"); ; break;
        case 3: system("cls"); ; break;

        }

        // new line
        cout << "\n";

    } while (true);
}