#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
using namespace std;

template<class T>
class StackUtils {
public:
    StackUtils(int size = 128); /* Constructor with default value */
    StackUtils(const StackUtils&); /* Copy Constructor */
    ~StackUtils(); /* Destructor */

    /* Member Functions */
    void push(T);

    void pop(T&);

    void stackTop(T&) const; /* retrieve top value */
    bool stackIsEmpty() const; /* checker for Empty stack */
    bool stackIsFull() const; /* checker for Full stack */
    int stackSize();

    void sorting_stack(StackUtils<T>&); /* sorting the stack */
    void sorting_stack(); /* sorting the stack */
    void printStack(StackUtils<T>&stack, const std::string&message);
    T getMin();

private:
    T* stack; /* pointer to dynamic array */
    int top; /* holds the index of the top of the stack insert and pop from it */
    int stack_size;
    int count;
};

#include "StackUtils.tpp"

#endif /* STACK_H */
