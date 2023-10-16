#pragma once
#include<iostream>
#include<stack>
#include<string>
#include<fstream>
using namespace std;

// Used to input the mathematical expression inside the calculatorMenu()
string inputString(string prompt, bool spaces);

class SimpleCalculator
{
public:

	//Class that checks if its divison by 0 0
	class DivisionByZero {
	private:
		string checking;
	public:
		DivisionByZero(); // Defualt Constructor
		DivisionByZero(SimpleCalculator r); // Argument constructor - takes in a string that was converted from a double in toString().
		string toString(); // returns the result of toString() from the SimpleCalculator class into the variable checking.
	};

	SimpleCalculator(); //defualt constructor 
	string toString(); // Converts a variable to a string to easily check for zero in the DivisionByZero class by turning 0.0 into "0"
	void calculatorMenu(); // Stores numbers and operators into stacks and displayCalculation(numbers, cin, answer); does the process.
	void displayCalculation(stack<double>& numbers, istream& ins, double& answer); // Checks for parentheses while also pushes & pops numbers and operators until an answer can be evaluated here: evaluateExpression(numbers)
	void evaluateExpression(stack<double>& numbers); // Evaluates and calculates the numbers through mathematical operations(^,*,/,+,-). Then pushes the answer to stack<double>numbers 
	int getPrecendence(char operation); // Returns the precedence of the operations. (lowest to Highest) 1. +, -  2. *, / 3. ^
};


