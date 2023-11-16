# Infix Evaluator Using Stack

## Requirements

Write a program that uses stacks to evaluate an arithmetic expression in infix notation without converting it into postfix notation.

The program takes as input a numeric expression in infix notation, such as 3+4*2, and outputs the result.

1) Operators are +, -, *, /
2) Assume that the expression is formed correctly so that each operation has two arguments.
3) The expression can have parenthesis, for example: 3*(4-2)+6.
4) The expression can have negative numbers.
5) The expression can have spaces in it, for example: 3  *  (4-2)  +6 .

Here are some useful functions that you may need:

char cin.peek(); -- returns the next character of the cin input stream ( without reading it)
bool isdigit(char c); -- returns true if c is one of the digits ‘0’ through ‘9’, false otherwise
cin.ignore(); -- reads and discards the next character from the cin input stream
cin.get(char &c); -- reads a character in c ( could be a space or the new line )


## Solution

Evaluating an arithmetic expression that's in infix notation directly (without converting it to postfix) typically requires two stacks: one for operators and another for operands.
Here's why using a stack (or stacks) can be useful for this process:

1. **Operator Precedence and Parentheses Handling:** Stacks can help manage the precedence of operators and handle parentheses properly. When an operator is encountered, it can be compared with the operator at the top of the operator stack for precedence. If it is of higher precedence, it is pushed onto the stack; if not, the stack is popped and the operation is evaluated until the correct position for the new operator is found. Parentheses are handled by pushing them onto the operator stack and popping them when the corresponding closing parenthesis is encountered, which triggers the evaluation of the expression within the parentheses.

2. **Maintain Order of Evaluation:** By using stacks, the order of operations is maintained correctly. When a closing parenthesis is found, for example, the stack enables the evaluation of the most recent complete expression enclosed by that set of parentheses.

3. **Reversibility:** Infix expressions require that operations be performed in a specific order, which is not necessarily the order in which they are read from left to right. The stack's Last-In-First-Out (LIFO) property allows operators and operands to be stored and then retrieved in an order that respects both operator precedence and the associativity rules.

4. **No Need for Conversion:** While converting infix to postfix (or prefix) can simplify the computation process since it removes the need for precedence rules and parentheses, the conversion process itself can be complex. By using stacks to evaluate the expression directly, you can skip the conversion step and evaluate as you parse the expression.

5. **Simplicity in Implementation:** For some applications, particularly simple or once-off calculations, it may be more straightforward to implement a direct infix evaluation rather than dealing with the overhead of converting to another form.

For example, `3 * (4 - 2) + 6`, using stacks allows for the direct computation as follows:

- Push 3 onto the operand stack.
- Push * onto the operator stack.
- Encounter (, push onto the operator stack.
- Push 4 onto the operand stack.
- Push - onto the operator stack.
- Push 2 onto the operand stack.
- Upon encountering ), resolve the expression within the parenthesis by popping the operands and the operator to compute `4 - 2`.
- Push the result (2) onto the operand stack.
- Multiply the top of the operand stack by 3 when * is encountered and resolved.
- Finally, add 6 to the result.

By managing the stacks appropriately, you can directly evaluate the infix expression while respecting the proper order of operations.


## Run the code
```bash
$ g++ -std=c++11 main.cpp -o InfixEvaluatorUsingStack
$ ./InfixEvaluatorUsingStack
Enter an arithmetic expression: 3 * (4-2) +6       
Result: 12
```
