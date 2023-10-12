#include "ComplexNumbers.h"

// Credit: Joe Bryant & Erik Santana & Christian Hernandez

// Pre-Condition: no parameters.
// Post:Condition: no return. Initializer constructor
ComplexNumbers::ComplexNumbers()
{
	coefficientA = 0;
	coefficientB = 0;
}

// Pre-Condition: parameters: double a, double b
// Post:Condition: no return. Argument constructor
ComplexNumbers::ComplexNumbers(double a, double b)
{
	coefficientA = a;
	coefficientB = b;
}

// Pre-Condition: parameter: double newCoefficientA
// Post:Condition: no return. assigns newCoefficientA to coefficientA
void ComplexNumbers::setCoefficientA(double newCoefficientA)
{
	coefficientA = newCoefficientA;
}

// Pre-Condition: no parameters
// Post:Condition: returns coefficientA. Accesses coefficientA
double ComplexNumbers::getCoefficientA() const
{
	return coefficientA;
}

// Pre-Condition: parameter: double newCoefficientB
// Post:Condition: no return. assigns newCoefficientB to coefficientB
void ComplexNumbers::setCoefficientB(double newCoefficientB)
{
	coefficientB = newCoefficientB;
}

// Pre-Condition: no parameters
// Post:Condition: returns coefficientB. Accesses coefficientB
double ComplexNumbers::getCoefficientB() const
{
	return coefficientB;
}

// Pre-Condition: no parameters.
// Post:Condition: no return. Sub Menu - Complex Menu
void ComplexNumbers::complexMenu()
{
	char choice = '\0';

	do
	{
		system("cls");
		cout << "\n\t\tA complex number is a number that can be expressed in the form a + b i, where a and b are real\n";
		cout << "\t\tnumbers, and i represents the \"imaginary unit\", satisfying the equation i^2 = -1. Because no\n";
		cout << "\t\treal number satisfies this equation, i is called an imaginary number. For the complex number\n";
		cout << "\t\ta + b i, a is called the real part and b is called the imaginary part.\n\n";

		cout << "\t\t1> Complex Numbers\n";
		cout << "\t\t" << string(90, char(205)) << endl;
		cout << "\t\t\tA> A Complex Number\n";
		cout << "\t\t\tB> Multiple Complex Numbers\n";
		cout << "\t\t" << string(90, char(196)) << endl;
		cout << "\t\t\t0> return\n";
		cout << "\t\t" << string(90, char(205)) << endl;

		choice = inputChar("\t\t\tOption: ", "AB0");

		switch (choice)
		{
		case 'A':
			break;
		case 'B':
			system("cls");
			multipleComplexMenu();
			break;
		case '0': system("cls"); mainMenu();
		}
	} while (true);

	// new line
	cout << "\n";
	system("pause");
}

// Pre-Condition: no parameters.
// Post:Condition: no return. Sub-Sub Menu - Multiple Complex Menu
void ComplexNumbers::multipleComplexMenu()
{
	char choice = '\0';
	ComplexNumbers c1;
	ComplexNumbers c2;
	ComplexNumbers c3;

	do
	{
		system("cls");
		cout << "\n\t\tB> Multiple Complex Numbers\n";
		cout << "\t\t" << string(90, char(205)) << endl;
		cout << "\t\t\t1. Enter complex number C1\n";
		cout << "\t\t\t2. Enter complex number C2\n";
		cout << "\t\t\t3. Verify condition operators (== and !=) of C1 and C2\n";
		cout << "\t\t\t4. Evaluate arithmatic operators (+, - , * and /) of C1 and C2\n";
		cout << "\t\t\t5. Evaluate steps in (3 * (C1 + C2) / 7) / (C2 - C1 / 9) != (1.07109 + 0.120832i) ?\n";
		cout << "\t\t" << string(90, char(196)) << endl;
		cout << "\t\t\t0. return\n";
		cout << "\t\t" << string(90, char(205)) << endl;

		choice = inputInteger("\t\t\tOption: ", 0, 5);

		switch (choice)
		{
		case 1: cout << endl;
			c1.setCoefficientA(inputDouble("\t\t\tEnter a number (double value) for the real part of C1: "));
			c1.setCoefficientB(inputDouble("\t\t\tEnter a number (double value) for the imaginary part of C1: "));
			cout << endl;

			if (c1.coefficientA == 0 && c1.coefficientB == 0)
			{
				cout << "\t\t\tC1 = 0\n\n";
			}
			else if (c1.coefficientA == 0)
			{
				cout << "\t\t\tC1 = " << c1.coefficientB << "i" << endl << endl;
			}
			else if (c1.coefficientB == 0)
			{
				cout << "\t\t\tC1 = " << c1.coefficientA << endl << endl;
			}
			else if (c1.getCoefficientB() < 0)
			{
				cout << "\t\t\tC1 = " << c1.getCoefficientA() << " - " << -(c1.getCoefficientB()) << "i" << endl << endl;
			}
			else
			{
				cout << "\t\t\tC1 = " << c1.getCoefficientA() << " + " << c1.getCoefficientB() << "i" << endl << endl;
			}

			break;
		case 2:c2.setCoefficientA(inputDouble("\t\t\tEnter a number (double value) for the real part of C2: "));
			c2.setCoefficientB(inputDouble("\t\t\tEnter a number (double value) for the imaginary part of C2: "));

			cout << endl;

			if (c2.coefficientA == 0 && c2.coefficientB == 0)
			{
				cout << "\t\t\tC1 = 0\n\n";
			}
			else if (c2.coefficientA == 0)
			{
				cout << "\t\t\tC1 = " << c2.coefficientB << "i" << endl << endl;
			}
			else if (c2.coefficientB == 0)
			{
				cout << "\t\t\tC1 = " << c2.coefficientA << endl << endl;
			}
			else if (c2.getCoefficientB() < 0)
			{
				cout << "\t\t\tC2 = " << c2.getCoefficientA() << " - " << -(c2.getCoefficientB()) << "i" << endl << endl;
			}
			else
			{
				cout << "\t\t\tC2 = " << c2.getCoefficientA() << " + " << c2.getCoefficientB() << "i" << endl << endl;
			}
			break;
		case 3: cout << endl;
			displayEqual(c1, c2);
			displayNotEqual(c1, c2);
			system("pause");
			break;
		case 4: cout << endl;
			displayAddition(c1, c2, c3);
			displaySubtraction(c1, c2, c3);
			displayMultiplication(c1, c2, c3);
			displayDivision(c1, c2, c3);
			cout << endl << endl;
			system("pause");
			break;
		case 5:
			evaluateSteps(c1, c2);
			system("pause");
			break;
		case 0:
			system("cls");
			complexMenu();
			break;
		}
	} while (true);

	// new line
	cout << "\n";
	system("pause");
}

// Pre-Condition: parameters: ComplexNumbers& c1, ComplexNumbers& c2
// Post:Condition: no return. This function checks if complex numbers c1 & c2 are equal
void ComplexNumbers::displayEqual(ComplexNumbers& c1, ComplexNumbers& c2)
{

	if (c1.coefficientA == 0 && c1.coefficientB == 0)
	{
		cout << "\t\t\tC1 == C2 -> (" << c1.coefficientA << ") ";
	}
	else if (c1.coefficientA == 0)
	{
		cout << "\t\t\tC1 == C2 -> (" << c1.coefficientB << "i) ";
	}
	else if (c1.coefficientB == 0)
	{
		cout << "\t\t\tC1 == C2 -> (" << c1.coefficientA << ") ";
	}
	else if (c1.getCoefficientB() < 0)
	{
		cout << "\t\t\tC1 == C2 -> (" << c1.getCoefficientA() << " - " << -(c1.getCoefficientB()) << "i) ";
	}
	else
	{
		cout << "\t\t\tC1 == C2 -> (" << c1.getCoefficientA() << " + " << c1.getCoefficientB() << "i) ";
	}

	cout << "== ";

	if (c2.coefficientA == 0 && c2.coefficientB == 0)
	{
		cout << "(" << c2.coefficientA << ") ? ";
	}
	else if (c2.coefficientA == 0)
	{
		cout << "(" << c2.coefficientB << "i) ? ";
	}
	else if (c2.coefficientB == 0)
	{
		cout << "(" << c2.coefficientA << ") ? ";
	}
	else if (c2.getCoefficientB() < 0)
	{
		cout << "(" << c2.getCoefficientA() << " - " << -(c2.getCoefficientB()) << "i) ? ";
	}
	else
	{
		cout << "(" << c2.getCoefficientA() << " + " << c2.getCoefficientB() << "i) ? ";
	}

	if (c1 == c2)
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}
}

// Pre-Condition: parameters: ComplexNumbers& c1, ComplexNumbers& c2
// Post:Condition: no return. This function checks if 2 complex numbers(c1 & c2) are NOT equal.
void ComplexNumbers::displayNotEqual(ComplexNumbers& c1, ComplexNumbers& c2)
{
	cout << "\t\t\tC1 != C2 -> ";
	if (c1.getCoefficientB() < 0)
	{
		cout << "(" << c1.getCoefficientA() << " - " << -(c1.getCoefficientB()) << "i) ";
	}
	else
	{
		cout << "(" << c1.getCoefficientA() << " + " << c1.getCoefficientB() << "i) ";
	}

	cout << "!= ";

	if (c2.getCoefficientB() < 0)
	{
		cout << "(" << c2.getCoefficientA() << " - " << -(c2.getCoefficientB()) << "i) ? ";
	}
	else
	{
		cout << "(" << c2.getCoefficientA() << " + " << c2.getCoefficientB() << "i) ? ";
	}

	if (c1 != c2)
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}
}

// Pre-Condition: parameters: ComplexNumbers& c1, ComplexNumbers& c2, ComplexNumbers& c3
// Post:Condition: no return. Adds two complex numbers(c1 & c2) and stores the result in a third complex number(c3).
void ComplexNumbers::displayAddition(ComplexNumbers& c1, ComplexNumbers& c2, ComplexNumbers& c3)
{
	c3 = c1 + c2;

	cout << "\t\t\tAddition      : C1 + C2 -> ";
	if (c1.getCoefficientB() < 0)
	{
		cout << "(" << c1.getCoefficientA() << " - " << -(c1.getCoefficientB()) << "i) ";
	}
	else
	{
		cout << "(" << c1.getCoefficientA() << " + " << c1.getCoefficientB() << "i) ";
	}

	cout << "+ ";

	if (c2.getCoefficientB() < 0)
	{
		cout << "(" << c2.getCoefficientA() << " - " << -(c2.getCoefficientB()) << "i) = ";
	}
	else
	{
		cout << "(" << c2.getCoefficientA() << " + " << c2.getCoefficientB() << "i) = ";
	}

	if (c3.getCoefficientB() < 0)
	{
		cout << c3.getCoefficientA() << " - " << -(c3.getCoefficientB()) << "i";
	}
	else
	{
		cout << c3.getCoefficientA() << " + " << c3.getCoefficientB() << "i";
	}
}

void ComplexNumbers::displaySubtraction(ComplexNumbers& c1, ComplexNumbers& c2, ComplexNumbers& c3)
{
	c3 = c2 - c1;

	cout << endl;

	if (c2.coefficientA == 0 && c2.coefficientB == 0)
	{
		cout << "\t\t\tSubtraction   : C2 - C1 -> (" << c2.coefficientA << ") ";
	}
	else if (c2.coefficientA == 0)
	{
		cout << "\t\t\tSubtraction   : C2 - C1 -> (" << c2.coefficientB << "i) ";
	}
	else if (c2.coefficientB == 0)
	{
		cout << "\t\t\tSubtraction   : C2 - C1 -> (" << c2.coefficientA << ") ";
	}
	else if (c2.getCoefficientB() < 0)
	{
		cout << "\t\t\tSubtraction   : C2 - C1 -> (" << c2.getCoefficientA() << " - " << -(c2.getCoefficientB()) << "i) ";
	}
	else
	{
		cout << "\t\t\tSubtraction   : C2 - C1 -> (" << c2.getCoefficientA() << " + " << c2.getCoefficientB() << "i) ";
	}

	cout << "- ";

	if (c1.coefficientA == 0 && c1.coefficientB == 0)
	{
		cout << "(" << c1.coefficientA << ") = ";
	}
	else if (c1.coefficientA == 0)
	{
		cout << "(" << c1.coefficientB << "i) = ";
	}
	else if (c1.coefficientB == 0)
	{
		cout << "(" << c1.coefficientA << ") = ";
	}
	else if (c1.getCoefficientB() < 0)
	{
		cout << "(" << c1.getCoefficientA() << " - " << -(c1.getCoefficientB()) << "i) = ";
	}
	else
	{
		cout << "(" << c1.getCoefficientA() << " + " << c1.getCoefficientB() << "i) = ";
	}

	if (c3.coefficientA == 0 && c3.coefficientB == 0)
	{
		cout << c3.coefficientA << endl;
	}
	else if (c3.coefficientA == 0)
	{
		cout << c3.coefficientB << "i\n";
	}
	else if (c3.coefficientB == 0)
	{
		cout << c3.coefficientA << endl;
	}
	else if (c3.getCoefficientB() < 0)
	{
		cout << c3.getCoefficientA() << " - " << -(c3.getCoefficientB()) << "i\n";
	}
	else
	{
		cout << c3.getCoefficientA() << " + " << c3.getCoefficientB() << "i\n";
	}
}

void ComplexNumbers::displayMultiplication(ComplexNumbers& c1, ComplexNumbers& c2, ComplexNumbers& c3)
{
	c3 = c1 * c2;

	if (c1.coefficientA == 0 && c1.coefficientB == 0)
	{
		cout << "\t\t\tMultiplication: C2 * C1 -> (" << c1.coefficientA << ") ";
	}
	else if (c1.coefficientA == 0)
	{
		cout << "\t\t\tMultiplication: C2 * C1 -> (" << c1.coefficientB << "i) ";
	}
	else if (c1.coefficientB == 0)
	{
		cout << "\t\t\tMultiplication: C2 * C1 -> (" << c1.coefficientA << ") ";
	}
	else if (c1.getCoefficientB() < 0)
	{
		cout << "\t\t\tMultiplication: C2 * C1 -> (" << c1.getCoefficientA() << " - " << -(c1.getCoefficientB()) << "i) ";
	}
	else
	{
		cout << "\t\t\tMultiplication: C2 * C1 -> (" << c1.getCoefficientA() << " + " << c1.getCoefficientB() << "i) ";
	}

	cout << "* ";

	if (c2.coefficientA == 0 && c2.coefficientB == 0)
	{
		cout << "(" << c2.coefficientA << ") = ";
	}
	else if (c2.coefficientA == 0)
	{
		cout << "(" << c2.coefficientB << "i) = ";
	}
	else if (c2.coefficientB == 0)
	{
		cout << "(" << c2.coefficientA << ") = ";
	}
	else if (c2.getCoefficientB() < 0)
	{
		cout << "(" << c2.getCoefficientA() << " - " << -(c2.getCoefficientB()) << "i) = ";
	}
	else
	{
		cout << "(" << c2.getCoefficientA() << " + " << c2.getCoefficientB() << "i) = ";
	}

	if (c3.coefficientA == 0 && c3.coefficientB == 0)
	{
		cout << c3.coefficientA << endl;
	}
	else if (c3.coefficientA == 0)
	{
		cout << c3.coefficientB << "i\n";
	}
	else if (c3.coefficientB == 0)
	{
		cout << c3.coefficientA << endl;
	}
	else if (c3.getCoefficientB() < 0)
	{
		cout << c3.getCoefficientA() << " - " << -(c3.getCoefficientB()) << "i\n";
	}
	else
	{
		cout << c3.getCoefficientA() << " + " << c3.getCoefficientB() << "i\n";
	}
}

void ComplexNumbers::displayDivision(ComplexNumbers& c1, ComplexNumbers& c2, ComplexNumbers& c3)
{
	c3 = c2 / c1;

	if (c2.coefficientA == 0 && c2.coefficientB == 0)
	{
		cout << "\t\t\tDivision      : C2 / C1 -> (" << c2.coefficientA << ") ";
	}
	else if (c2.coefficientA == 0)
	{
		cout << "\t\t\tDivision      : C2 / C1 -> (" << c2.coefficientB << "i) ";
	}
	else if (c2.coefficientB == 0)
	{
		cout << "\t\t\tDivision      : C2 / C1 -> (" << c2.coefficientA << ") ";
	}
	else if (c2.getCoefficientB() < 0)
	{
		cout << "\t\t\tDivision      : C2 / C1 -> (" << c2.getCoefficientA() << " - " << -(c2.getCoefficientB()) << "i) ";
	}
	else
	{
		cout << "\t\t\tDivision      : C2 / C1 -> (" << c2.getCoefficientA() << " + " << c2.getCoefficientB() << "i) ";
	}

	cout << "/ ";

	if (c1.coefficientA == 0 && c1.coefficientB == 0)
	{
		cout << "(" << c1.coefficientA << ") = ";
	}
	else if (c1.coefficientA == 0)
	{
		cout << "(" << c1.coefficientB << "i) = ";
	}
	else if (c1.coefficientB == 0)
	{
		cout << "(" << c1.coefficientA << ") = ";
	}
	else if (c1.getCoefficientB() < 0)
	{
		cout << "(" << c1.getCoefficientA() << " - " << -(c1.getCoefficientB()) << "i) = ";
	}
	else
	{
		cout << "(" << c1.getCoefficientA() << " + " << c1.getCoefficientB() << "i) = ";
	}

	if (c3.coefficientA == 0 && c3.coefficientB == 0)
	{
		cout << c3.coefficientA << endl;
	}
	else if (c3.coefficientA == 0)
	{
		cout << c3.coefficientB << "i\n";
	}
	else if (c3.coefficientB == 0)
	{
		cout << c3.coefficientA << endl;
	}
	else if (c3.getCoefficientB() < 0)
	{
		cout << c3.getCoefficientA() << " - " << -(c3.getCoefficientB()) << "i\n";
	}
	else
	{
		cout << c3.getCoefficientA() << " + " << c3.getCoefficientB() << "i\n";
	}

}

void ComplexNumbers::evaluateSteps(ComplexNumbers& c1, ComplexNumbers& c2)
{
	// (3 * (C1 + C2) / 7) / (C2 - C1 / 9) != (1.07109 + 0.120832i) ?

	double resultComplexNumber = c1.coefficientA + c2.coefficientA;
	double resultComplexNumber2 = c1.coefficientB + c2.coefficientB;
	double resultComplexNumber3 = c2.coefficientA - c2.coefficientB;
	double resultComplexNumber4 = c1.coefficientA - c1.coefficientB;

	if (3 * ((resultComplexNumber + resultComplexNumber2) / 7) / ((resultComplexNumber3 - resultComplexNumber4) / 9) != (1.07109 + 0.120832))
	{
		cout << endl;
		cout << "\t\t\tTrue\n";
		cout << "\t\t\t(3 * (" << c1.getCoefficientA() + c2.getCoefficientA() << "+" << c1.getCoefficientB() + c2.getCoefficientB() << "i) / 7) / (" << resultComplexNumber3 << "-" << resultComplexNumber2 << "i / 9) != (1.07109 + 0.120832i)\n\n";
	}
	else
	{
		cout << endl;
		cout << "\t\t\tFalse\n";
		cout << "\t\t\t(3 * (" << c1.getCoefficientA() + c2.getCoefficientA() << "+" << c1.getCoefficientB() + c2.getCoefficientB() << ") / 7) / (" << resultComplexNumber3 << "-" << resultComplexNumber2 << " / 9) != (1.07109 + 0.120832i)\n\n";
	}

}

// Pre-Condition: parameters: ComplexNumbers& c1, ComplexNumbers& c2
// Post:Condition: returns ComplexNumbers(sumA, sumB). This overloaded operator adds two coefficients and returns them.
ComplexNumbers operator+(ComplexNumbers& c1, ComplexNumbers& c2)
{
	double sumA;
	double sumB;

	sumA = c1.coefficientA + c2.coefficientA;
	sumB = c1.coefficientB + c2.coefficientB;

	return ComplexNumbers(sumA, sumB);
}

// Pre-Condition: parameters: ComplexNumbers& c1, ComplexNumbers& c2
// Post:Condition: returns ComplexNumbers(sumA, sumB). This overloaded operator subtracts two coefficients and returns them.
ComplexNumbers operator-(ComplexNumbers& c1, ComplexNumbers& c2)
{
	double sumA;
	double sumB;

	sumA = c2.coefficientA - c1.coefficientA;
	sumB = c2.coefficientB - c1.coefficientB;

	return ComplexNumbers(sumA, sumB);
}

ComplexNumbers operator*(ComplexNumbers& c1, ComplexNumbers& c2)
{
	double productA;
	double productB;

	productA = (c1.coefficientA * c2.coefficientA) + (-(c1.coefficientB * c2.coefficientB));
	productB = (c1.coefficientA * c2.coefficientB) + (c1.coefficientB * c2.coefficientA);

	return ComplexNumbers(productA, productB);
}

ComplexNumbers operator/(ComplexNumbers& c2, ComplexNumbers& c1)
{
	double a;
	double b;
	double denominator;

	denominator = pow(c1.coefficientA, 2) + pow(c1.coefficientB, 2);

	a = (c1.coefficientA * c2.coefficientA) + (-(-c1.coefficientB * c2.coefficientB));
	b = (c1.coefficientA * c2.coefficientB) + (-c1.coefficientB * c2.coefficientA);

	a /= denominator;
	b /= denominator;

	return ComplexNumbers(a, b);
}

// Pre-Condition: parameters: ComplexNumbers& c1, ComplexNumbers& c2
// Post:Condition: returns true or false. This overloaded operator checks if 2 coefficients from 2 different complex numbers are equal and returns true if they are, else false.
bool operator==(ComplexNumbers& c1, ComplexNumbers& c2)
{
	if (c1.coefficientA == c2.coefficientA && c1.coefficientB == c2.coefficientB)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Pre-Condition: parameters: ComplexNumbers& c1, ComplexNumbers& c2
// Post:Condition: returns true or false. This overloaded operator checks if 2 coefficients from 2 different complex numbers are NOT equal and returns true if they are, else false.
bool operator!=(ComplexNumbers& c1, ComplexNumbers& c2)
{
	if (c1.coefficientA != c2.coefficientA || c1.coefficientB != c2.coefficientB)
	{
		return true;
	}
	else
	{
		return false;
	}
}