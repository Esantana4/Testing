#include "SimpleCalculator.h"

// Implementation of a member function to determine the precedence of operators
int SimpleCalculator::getOperatorPrecedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0; // Lower precedence for non-operators
}

// Function to apply an operator to the operands on the stack
void applyOperator(stack<double>& numbers, char op) {

    // Check if there are at least two operands on the stack
    if (numbers.size() < 2) { 
        cerr << "Error: Insufficient operands for operator '" << op << "'\n"; // Print an error message if there are insufficient operands
        return;
    }
   
    double operand2 = numbers.top(); // Retrieve the top operand from the stack
    numbers.pop(); // Remove the top operand from the stack

    double operand1 = numbers.top(); // Retrieve the second top operand from the stack
    numbers.pop(); // Remove the second top operand from the stack

    switch (op) 
    {
    case '^':
        numbers.push(pow(operand1, operand2)); // Push the result of raising operand1 to the power of operand2 onto the stack
        break;
    case '*':
        numbers.push(operand1 * operand2); // Push the result of multiplying operand1 by operand2 onto the stack
        break;
    case '/':
        // Check for division by zero before performing the division
        if (operand2 != 0) {
            numbers.push(operand1 / operand2); // Push the result of dividing operand1 by operand2 onto the stack
        }
        else {
            cerr << "Error: Division by zero\n";
            return;
        }
        break;
    case '+':
        numbers.push(operand1 + operand2); // Push the result of adding operand1 and operand2 onto the stack
        break;
    case '-':
        numbers.push(operand1 - operand2); // Push the result of subtracting operand2 from operand1 onto the stack
        break;
    }
}

// Member function to calculate the result of an expression
double SimpleCalculator::calculateExpression(const string& expression) {

    // Stacks to hold operands and operators during expression evaluation
    stack<double> numbers;
    stack<char> operators;

    // Function pointer to get operator precedence
    auto precedence = getOperatorPrecedence;

    for (char ch : expression) {
        // If the character is a digit, push its integer value onto the stack
        if (isdigit(ch)) {
            numbers.push(ch - '0'); // Convert character to integer
        }
        // If the character is an operator
        else if (isOperator(ch)) {
            // Process operators based on their precedence
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                applyOperator(numbers, operators.top());
                operators.pop();
            }
            operators.push(ch); // Push the current operator onto the stack
        }
        // If the character is an opening parenthesis
        else if (ch == '(') {
            operators.push(ch); // Push '(' onto the stack
        }
        // If the character is a closing parenthesis
        else if (ch == ')') {
            // Process operators until the matching opening parenthesis is found
            while (!operators.empty() && operators.top() != '(') {
                applyOperator(numbers, operators.top());
                operators.pop();
            }
            // If '(' is at the top, pop it to match the closing parenthesis
            if (!operators.empty() && operators.top() == '(') {
                operators.pop(); // Pop '('
            }
            // If there is no matching opening parenthesis, print an error
            else {
                cerr << "Error: Unmatched ')'\n";
            }
        }
    }

    while (!operators.empty()) {
        applyOperator(numbers, operators.top());
        operators.pop();
    }

    if (!numbers.empty()) {
        return numbers.top();
    }
    else {
        cerr << "Error: Empty result\n";
        return 0.0;
    }
}

void SimpleCalculator::calculatorMenu() {
    string expression = inputString("Type a fully parenthesized arithmetic expression: ", true);
    double result = calculateExpression(expression);
    cout << "\nResult: " << result << endl;
}

bool SimpleCalculator::isOperator(char ch) {
    return ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-';
}
