/********************************************************
* Generic linked stack class declaration.               *
* This class specifies that basic operations of a stack *
* as a linked list.                                     *
*********************************************************/

// This class specifies that basic operations on a stack
// as a linked list.

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

// Defination of the node
template <class T>
struct node
{
    T info;
    node<T> *link;
};

template <class T>
class LinkedStack
{
private:
    // stackTop gives the address of the top element of the stack.
    node<T> *stackTop; //Pointer to the stack

    void copyStack(const LinkedStack<T> & otherStack);
    //Function to make a copy of otherStack.
    //Postcondition: A copy of otherStack is created and assigned to this stack.

public:
    LinkedStack();
    //Default constructor
    //Postcondition: stackTop = NULL;

    LinkedStack(const LinkedStack<T> & otherStack);
    //Copy constructor

    ~LinkedStack();
    //Destructor
    //Postcondition: All the elements of the stack are removed from the stack.

    const LinkedStack<T> & operator=
            (const LinkedStack<T> & otherStack);
    //Overloaded assignment operator

    bool isEmptyStack() const;
    //Function to determine whether the stack is empty.
    //Postcondition: Returns true if the stack is empty,
    //               otherwise returns false.

    //In this linked implementation of stacks, the memory to store the stack
    //elements is allocated dynamically. Logically, the stack is never full.
    //bool isFullStack() const;
    //Function to determine whether the stack is full.
    //Postcondition: Returns false.

    void initializeStack();
    //Function to initialize the stack to an empty state.
    //Postcondition: The stack elements are removed; stackTop = NULL.

    void push(const T & newItem);
    //Function to add newItem to the stack.
    //Precondition: The stack exists and is not full.
    //Postcondition: The stack is changed and newItem is added
    //               to the top of the stack.

    T top() const;
    //Function to return the top element of the stack.
    //Precondition: The stack exists and is not empty.
    //Postcondition: If the stack is empty, the program
    //               terminates; otherwise, the top element
    //               of the stack is returned.

    void pop();
    //Function to remove the top element of the stack.
    //Precondition: The stack exists and is not empty.
    //Postcondition: The stack is changed and the top element
    //               is removed from the stack.
};

#endif //LINKEDSTACK_H