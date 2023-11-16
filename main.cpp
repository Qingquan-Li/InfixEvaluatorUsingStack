/************************************************************************
* Demonstrates using linked stacks to evaluate an arithmetic expression *
* in infix notation without converting it into postfix notation.        *
************************************************************************/

#include <iostream>

#include "LinkedStack.cpp"

using namespace std;

// Function prototypes
int performOperation(int, int, char);
bool hasPrecedence(char, char);
int evaluateExpression(string);

int main()
{
    string expression;
    cout << "Enter an arithmetic expression: "; // e.g., 3 * (4-2) + 6
    getline(cin, expression);

    cout << "Result: " << evaluateExpression(expression) << endl;

    return 0;
}

int performOperation(int operand1, int operand2, char operatorType)
{
    switch (operatorType) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            return 0;
    }
}


bool hasPrecedence(char operator1, char operator2)
{
    if (operator2 == '(' || operator2 == ')')
        return false;
    if ((operator1 == '*' || operator1 == '/') && (operator2 == '+' || operator2 == '-'))
        return false;
    else // e.g., operator1 == '+' && operator2 == '*'
        return true;
}

/**
 * Function to evaluate an expression.
 * Steps:
 * 1. Scan the infix expression from left to right.
 * 2. If the scanned character is an operand, output it.
 * 3. Else,
 *     1. If the precedence of the scanned operator is greater than the precedence of the operator
 *        in the stack(or the stack is empty or the stack contains a ‘(‘ ), push it.
 *     2. Else, Pop all the operators from the stack which are greater than or equal to in precedence
 *        than that of the scanned operator. After doing that Push the scanned operator to the stack.
 *        (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.)
 *        Repeat this step until '(' is encountered in the stack or stack becomes empty.
 *        Push '(' in the stack.
 *        If the scanned character is an ‘)’, pop and output from the stack until an ‘(‘ is encountered.
 *        Repeat this step until ‘(‘ is encountered in the stack.
 *        Pop and output from the stack until it is not empty.
 */
int evaluateExpression(string expression)
{
    LinkedStack<int> operandStack;   // stack to store operands
    LinkedStack<char> operatorStack; // stack to store operators

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ')
            continue;

        if (isdigit(expression[i])) {
            int operand = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                operand = (operand * 10) + (expression[i] - '0');
                i++;
            }
            i--;
            operandStack.push(operand);
        } else if (expression[i] == '(') {
            operatorStack.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!operatorStack.isEmptyStack() && operatorStack.top() != '(') {
                int operand2 = operandStack.top();
                operandStack.pop();

                int operand1 = operandStack.top();
                operandStack.pop();

                char operatorType = operatorStack.top();
                operatorStack.pop();

                operandStack.push(performOperation(operand1, operand2, operatorType));
            }
            operatorStack.pop();
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (!operatorStack.isEmptyStack() && hasPrecedence(expression[i], operatorStack.top())) {
                int operand2 = operandStack.top();
                operandStack.pop();

                int operand1 = operandStack.top();
                operandStack.pop();

                char operatorType = operatorStack.top();
                operatorStack.pop();

                operandStack.push(performOperation(operand1, operand2, operatorType));
            }
            operatorStack.push(expression[i]);
        }
    }

    while (!operatorStack.isEmptyStack()) {
        int operand2 = operandStack.top();
        operandStack.pop();

        int operand1 = operandStack.top();
        operandStack.pop();

        char operatorType = operatorStack.top();
        operatorStack.pop();

        operandStack.push(performOperation(operand1, operand2, operatorType));
    }

    return operandStack.top();
}
