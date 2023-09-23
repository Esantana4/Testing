#pragma once
#include<iostream>
using namespace std;

// Credit: Joe Bryant& Erik Santana & Christian Hernandez

char inputChar(string prompt, string options);
int inputInteger(string prompt, int startRange, int endRange);
double inputDouble(string prompt);
void mainMenu();

// Pre-Condition: private members: double coefficientA & double coefficientB;
// Post-Condition: This class multiplies, divides, adds, subtracts 2 complex numbers. This class also checks if 2 complex numbers are equal or not.
class ComplexNumbers
{
private:
	double coefficientA;
	double coefficientB;

public:
	//default constructor
	ComplexNumbers();

	// Argument Constructor
	ComplexNumbers(double a, double b);

	//sets coefficientA
	void setCoefficientA(double newCoefficientA);

	//gets coefficientA
	double getCoefficientA() const;

	//sets coefficientB
	void setCoefficientB(double newCoefficientB);

	//gets coefficientB
	double getCoefficientB() const;

	// Complex Menu
	void complexMenu();

	// B> Multiple Complex Menu
	void multipleComplexMenu();

	// + overloaded
	friend ComplexNumbers operator+(ComplexNumbers& c1, ComplexNumbers& c2);

	// - overloaded
	friend ComplexNumbers operator-(ComplexNumbers& c1, ComplexNumbers& c2);

	// == overloaded
	friend bool operator==(ComplexNumbers& c1, ComplexNumbers& c2);

	// !+ overloaded
	friend bool operator!=(ComplexNumbers& c1, ComplexNumbers& c2);

	// Displays true if c1 & c2 are equal
	void displayEqual(ComplexNumbers& c1, ComplexNumbers& c2);

	// Displays true if c1 & c2 are NOT equal
	void displayNotEqual(ComplexNumbers& c1, ComplexNumbers& c2);

	// Displays the sum of two complex numbers(c1 & c2) and stores them in a new complex number(c3)
	void displayAddition(ComplexNumbers& c1, ComplexNumbers& c2, ComplexNumbers& c3);
};