#include "SimpleCalculator.h"

//precondition: going to call the ZeroDenominator class
//postcondition: going to put it as a default constructor
SimpleCalculator::DivisionByZero::DivisionByZero() {}
//precondition: going to pass in the SimleCalculator class to give you access to the toString() function
//postcondition: going to then now set the rational which is the ZeroDenominator private = to the toString()
SimpleCalculator::DivisionByZero::DivisionByZero(SimpleCalculator r) {
	checking = r.toString();
}
//precondition: going to call the toString() function
//postcondition: going to return the rational (string)
string SimpleCalculator::DivisionByZero::toString() {
	return checking;
}

//Default Constructor
//Precondition: NA
//PostCondition: NA
SimpleCalculator::SimpleCalculator() {}

//precondition: going to turn the variables to a string since they are int
//postcondition: going to return a double checking if its 0
string SimpleCalculator::toString() {
	// Initialize a variable to hold the result (defaulted to 0.0).
	double num2 = 0.0;

	// Convert the result to a string and return it.
	return to_string(num2);
}
//Precondition: NA
//Postcondition: Displays Calculator Menu
void SimpleCalculator::calculatorMenu() {

	// Create stacks to store numbers and operators.
	stack<double> numbers;
	double answer;

	// Clear the console screen.
	system("cls");
	// Display menu information.
	cout << "\n\t1> Simple Calculator\n";
	cout << string(100, char(196)) << endl;

	try {
		cout << "Type a parenthesized or non-parenthesized arithmetic expression with positive integers or doubles:\n\n";

		// Clear the input buffer.
		cin.clear();
		// Specifies the maximum number of characters to ignore. It  provides the maximum value representable by the streamsize type.
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // '\n': This is the delimiter.The ignore function will stop ignoring characters once it encounters the specified delimiter

		// Call the displayCalculation function to process the input expression.
		displayCalculation(numbers, cin, answer);
	}
	// Catch the DivisionByZero exception.
	catch (DivisionByZero) {
		cout << "\n\tERROR: Division by zero cannot be done.\n";
	}
}

//Precondition: A stack of doubles, user input with numbers that are positive, a double answer
//Postcondition: Displays expression result
void SimpleCalculator::displayCalculation(stack<double>& numbers, istream& ins, double& answer) {
	const char RIGHT_PARENTHESIS = ')';
	const char LEFT_PARENTHESIS = '(';
	const char DECIMAL = '.';
	double number;
	char operation;
	char parenthesis;
	stack<char> convert;
	stack<double> storage;
	ofstream outFile;
	int errorCtr = 0;
	int specialError = 0;

	// Open an output file stream to write to "Store.txt".
	outFile.open("Store.txt");

	// Loop through the input stream until a newline character is encountered.
	while (ins && ins.peek() != '\n') {
		// Check if the next character is a left parenthesis.
		if (ins.peek() == LEFT_PARENTHESIS) {
			ins >> parenthesis;
			// Push the left parenthesis onto the 'convert' stack.
			convert.push(parenthesis);
		}
		// Check if the next character is a space.
		else if (ins.peek() == ' ') {
			ins.ignore();
		}
		// Check if the next character is a digit or a decimal point.
		else if (isdigit(ins.peek()) || ins.peek() == DECIMAL) {
			ins >> number;
			// Push the number onto the 'storage' stack.
			storage.push(number);
			// Write the number to the output file.
			outFile << number << endl;
		}
		// Check if the next character is an arithmetic operation.
		else if (ins.peek() == '+' || ins.peek() == '-' || ins.peek() == '*' || ins.peek() == '/' || ins.peek() == '^') {
			ins >> operation;
			// Pop operators from 'convert' stack and write to the output file based on precedence.
			while (!convert.empty() && convert.top() != LEFT_PARENTHESIS && getPrecendence(convert.top()) >= getPrecendence(operation)) {
				outFile << convert.top() << endl;
				convert.pop();
			}
			// Push the current operation onto the 'convert' stack.
			convert.push(operation);
		}
		// Check if the next character is a right parenthesis.
		else if (ins.peek() == RIGHT_PARENTHESIS && !convert.empty()) {
			ins.ignore();
			// Pop operators from 'convert' stack and write to the output file until a left parenthesis is encountered.
			while (!convert.empty() && convert.top() != LEFT_PARENTHESIS) {
				operation = convert.top();
				outFile << operation << endl;
				convert.pop();
			}
			// Check if there is a matching left parenthesis.
			if (convert.empty()) {
				cout << "ERROR: Unbalanced Parenthesis\n";
				++errorCtr;
			}
			else {
				// Pop the left parenthesis.
				convert.pop();
			}
		}
		// Handle other cases (invalid characters).
		else {
			cout << "ERROR: Incorrect Expression Input\n";
			++errorCtr;
			++specialError;
			// Ignore the rest of the line.
			while (ins.peek() != '\n') {
				ins.ignore();
			}
			break;
		}
	}

	// Pop any remaining operators from 'convert' stack and write to the output file.
	while (!convert.empty() && convert.top() != LEFT_PARENTHESIS && specialError == 0) {
		operation = convert.top();
		outFile << operation << endl;
		convert.pop();
	}

	// Check for errors related to unbalanced parentheses.
	if (!convert.empty() && specialError == 0) {
		cout << "ERROR: Unbalanced Parenthesis\n";
		++errorCtr;
	}

	// Check for errors related to incorrect expression input.
	if (storage.size() <= 1 && specialError == 0) {
		cout << "ERROR: Incorrect Expression Input\n";
		++errorCtr;
	}

	// If no errors occurred, evaluate the expression and display the result.
	if (errorCtr >= 1) {
		// Do nothing if there are errors.
	}
	else {
		// Evaluate the expression.
		evaluateExpression(numbers);

		// Get the result from the top of the 'numbers' stack.
		answer = numbers.top();

		// Display the result of the expression.
		cout << "\nThe Expression Evaluates to: " << answer << endl;
	}

	// Close the output file.
	outFile.close();
}

//Precondition:A stack of doubles for numbers
//Postcondition: evaluates expression
void SimpleCalculator::evaluateExpression(stack<double>& numbers) {
	// Declare variables to store numbers, answer, and operators.
	double num1;
	double num2;
	double storeNum;
	char storeOp;

	// Create an input file stream to read from "Store.txt".
	ifstream inFile;
	inFile.open("Store.txt");

	// Continue reading until the end of the file (EOF) is reached.
	while (!inFile.eof()) {
		// Check if the next character in the file is a digit.
		if (isdigit(inFile.peek())) {
			inFile >> storeNum;
			// Push the number onto the 'numbers' stack.
			numbers.push(storeNum);
		}
		// Check if the next character in the file is a newline character.
		else if (inFile.peek() == '\n') {
			inFile.ignore();
		}
		// Check if the next character in the file is an addition operator ('+').
		else if (inFile.peek() == '+' && numbers.size() >= 2) {
			inFile >> storeOp;
			// Pop the top two numbers from the 'numbers' stack.
			num2 = numbers.top();
			numbers.pop();
			num1 = numbers.top();
			numbers.pop();
			// Calculate the sum and push it onto the stack.
			numbers.push(num1 + num2);
		}
		// Check if the next character in the file is a subtraction operator ('-').
		else if (inFile.peek() == '-' && numbers.size() >= 2) {
			inFile >> storeOp;
			num2 = numbers.top();
			numbers.pop();
			num1 = numbers.top();
			numbers.pop();
			// Calculate the difference and push it onto the stack.
			numbers.push(num1 - num2);
		}
		// Check if the next character in the file is a multiplication operator ('*').
		else if (inFile.peek() == '*' && numbers.size() >= 2) {
			inFile >> storeOp;
			num2 = numbers.top();
			numbers.pop();
			num1 = numbers.top();
			numbers.pop();
			// Calculate the product and push it onto the stack.
			numbers.push(num1 * num2);
		}
		// Check if the next character in the file is a division operator ('/').
		else if (inFile.peek() == '/' && numbers.size() >= 2) {
			inFile >> storeOp;
			num2 = numbers.top();
			numbers.pop();
			num1 = numbers.top();
			numbers.pop();
			// Check if division by zero is attempted.
			if (num2 != 0) {
				// Calculate the division and push it onto the stack.
				numbers.push(num1 / num2);
			}
			// If division by zero is attempted, throw a DivisionByZero exception.
			else {
				throw DivisionByZero(*this);
			}
		}
		// Check if the next character in the file is an exponentiation operator ('^').
		else if (inFile.peek() == '^' && numbers.size() >= 2) {
			inFile >> storeOp;
			num2 = numbers.top();
			numbers.pop();
			num1 = numbers.top();
			numbers.pop();
			// Calculate the result of exponentiation and push it onto the stack.
			numbers.push(pow(num1, num2));
		}
		// Check if there are less than two numbers on the stack while the file is not at the end.
		else if (numbers.size() < 2 && !inFile.eof()) {
			// Print an error message indicating incorrect input.
			cout << "ERROR: Incorrect input must be positive numbers\n\n";
			// Return early from the function.
			return;
		}
	}

	// Close the input file.
	inFile.close();
}

//Precondition: a char operator
//Postcondition: returns precendence value;
int SimpleCalculator::getPrecendence(char operation) {
	// Switch statement to determine the precedence of the given operation.
	switch (operation) {
	case '+': // Addition and subtraction have the same precedence (1).
	case '-':
		return 1;
	case '*': // Multiplication and division have the same precedence (2).
	case '/':
		return 2;
	case '^': // Exponentiation has the highest precedence (3).
		return 3;
	default:
		// Handle any other characters.
		return 0;
	}
}
