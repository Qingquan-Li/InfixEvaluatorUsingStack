/*******************************************
* Linked Stack class - Implementation file *
********************************************/

#include <iostream>
#include <cassert>

#include "LinkedStack.h"

using namespace std;

/*
 * Default constructor
 * Initializes the stack to an empty state when a stack object is declared.
 */
template <class T>
LinkedStack<T>::LinkedStack()
{
    stackTop = NULL;
}

/*
 * Copy constructor
 * Makes a copy of otherStack.
 */
template <class T>
LinkedStack<T>::LinkedStack(const LinkedStack<T> & otherStack)
{
    stackTop = NULL;
    copyStack(otherStack);
}

/*
 * Destructor
 * Removes all the elements from the stack.
 */
template <class T>
LinkedStack<T>::~LinkedStack()
{
    initializeStack();
}

/*
 * Overloaded assignment operator
 * Copies otherStack into this stack.
 */
template <class T>
const LinkedStack<T> & LinkedStack<T>::operator=
        (const LinkedStack<T> & otherStack)
{
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);

    return *this;
}

/*
 * Function to determine whether the stack is empty.
 * Postcondition: Returns true if the stack is empty,
 *                otherwise returns false.
 */
template <class T>
bool LinkedStack<T>::isEmptyStack() const
{
    return (stackTop == NULL);
}

/*
 * Function to initialize the stack to an empty state.
 * Postcondition: The stack elements are removed; stackTop = NULL.
 */
template <class T>
void LinkedStack<T>::initializeStack()
{
    node<T> *temp; //pointer to delete the node

    while (stackTop != NULL) //while there are elements in the stack
    {
        temp = stackTop; //set temp to point to the current node
        stackTop = stackTop->link; //advance stackTop to the next node
        delete temp; //deallocate memory occupied by temp
    }
}

/*
 * Function to add newItem to the stack.
 * Precondition: The stack exists and is not full.
 * Postcondition: The stack is changed and newItem is added
 *                to the top of the stack.
 */
template <class T>
void LinkedStack<T>::push(const T & newItem)
{
    node<T> *newNode; //pointer to create the new node

    newNode = new node<T>; //create the node

    newNode->info = newItem; //store newItem in the node
    newNode->link = stackTop; //insert newNode before stackTop
    stackTop = newNode; //set stackTop to point to the top node
}

/*
 * Function to return the top element of the stack.
 * Precondition: The stack exists and is not empty.
 * Postcondition: If the stack is empty, the program
 *                terminates; otherwise, the top element
 *                of the stack is returned.
 */
template <class T>
T LinkedStack<T>::top() const
{
    assert(stackTop != NULL); //if stack is empty, terminate the program
    return stackTop->info; //return the top element
}

/*
 * Function to remove the top element of the stack.
 * Precondition: The stack exists and is not empty.
 * Postcondition: The stack is changed and the top
 *                element is removed from the stack.
 */
template <class T>
void LinkedStack<T>::pop()
{
    node<T> *temp; //pointer to deallocate memory

    if (stackTop != NULL)
    {
        temp = stackTop; //set temp to point to the top node

        stackTop = stackTop->link; //advance stackTop to the next node
        delete temp; //delete the top node
    }
    else
        cout << "Cannot remove from an empty stack." << endl;
}

/*
 * Copy stack
 * Makes an identical copy of otherStack.
 */
template <class T>
void LinkedStack<T>::copyStack(const LinkedStack<T> & otherStack)
{
    node<T> *newNode, *current, *last;

    if (stackTop != NULL) //if stack is nonempty, make it empty
        initializeStack();

    if (otherStack.stackTop == NULL)
        stackTop = NULL;
    else
    {
        current = otherStack.stackTop; //set current to point to the stack to be copied

        //copy the stackTop element of the stack
        stackTop = new node<T>; //create the node

        stackTop->info = current->info; //copy the info
        stackTop->link = NULL; //set the link field of the node to NULL
        last = stackTop; //set last to point to the node
        current = current->link; //set current to point to the next node

        //copy the remaining stack
        while (current != NULL)
        {
            newNode = new node<T>;

            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }//end while
    }//end else
}//end copyStack
