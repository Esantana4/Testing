#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>  // for std::setw and std::right
#include <cmath>
using namespace std;

char inputChar(string prompt, string lookup);
int inputInteger(string prompt, int start, bool greater);
int inputInteger(string prompt);
double inputDouble(string prompt);
void mainMenu();

void mainMenu();

class Polynomial {
private:
    vector<double> coefficients;
    bool termsEntered = false;
    bool coefficientsSpecified = false;

public:
    Polynomial();

    void enterTerms();
    void specifyCoefficients();
    double evaluateExpression(double x);
    Polynomial derivative();
    Polynomial integral();
    void printPolynomial(const Polynomial& poly);

    void main();
    void runSinglePolynomialMenu();

    Polynomial add(const Polynomial& p) const;
    Polynomial subtract(const Polynomial& p) const;
    Polynomial multiply(const Polynomial& p) const;
    Polynomial scalarMultiply(double scalar) const;
    void runMultiplePolynomialsMenu();
};
