/*
 Erik Santana
 10/11/23
 CPMR 131 - Professor Q

 Credit:
 Part 1: Simple Calculator - Erik Santana
 Part 2: Translation of arithmetic expression - Thanh Tran
 Part 3: n-Queens - Otoniel Torres Bernal
 */

#include<iostream>
#include<string>
#include"input.h"
#include"SimpleCalculator.h"
using namespace std;

void mainMenu();

int main()
{
	mainMenu();

	return 0;
}

void mainMenu()
{
	SimpleCalculator calculator;

	do {
		cout << "\n\t CMPR131 Chapter 7: Applications using Stacks by Erik Santana (10 / 11 / 23)\n";
		cout << "\t" << string(70, char(205)) << endl;
		cout << "\t  1> Simple Calculator\n";
		cout << "\t  2> Translation of arithmetic expression\n";
		cout << "\t  3> n-Queens\n";
		cout << "\t" << string(70, char(196)) << endl;
		cout << "\t  0> Exit\n";
		cout << "\t" << string(70, char(205)) << endl;

		switch (inputInteger("\t  Option: ", 0, 3))
		{
		case 0: exit(1);
			break;
		case 1: system("cls"); calculator.calculatorMenu();
			break;
		case 2:
			break;
		case 3:
			break;
		}

	} while (true);
	cout << endl;
}
