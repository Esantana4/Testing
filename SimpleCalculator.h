#pragma once
#include<iostream>
#include <stack>
#include <cmath> // for pow
#include <cctype> // for isDigit
using namespace std;

string inputString(string prompt, bool spaces);
char inputChar(string prompt, string options);
void mainMenu();

class SimpleCalculator {
private:
    bool isOperator(char ch); // A private member function to check if a character is an operator.

public:
    double calculateExpression(const string& expression); // Function prototype for calculateExpression, calculates the result of an infix expression.
    void calculatorMenu(); // Displays a menu for the calculator.
    static int getOperatorPrecedence(char op); // Gets the precedence of an operator.

};

