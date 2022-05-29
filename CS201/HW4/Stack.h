/**
 * ADT Stack header file for the CS201's HW4 assignment.
 * Author: Berk Cakar - 22003021
 */

#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <string>

template <class StackItemType>
class Stack {
public:
    Stack();
    ~Stack();
    Stack(const Stack<StackItemType>& otherStack);
    Stack<StackItemType>& operator=(const Stack<StackItemType>& otherStack);

    // Stack operations:
    bool isEmpty() const;
    bool push(const StackItemType& newItem);
    bool pop();
    bool pop(StackItemType& stackTop);
    bool getTop(StackItemType& stackTop) const;

    void printStack() const;

private:
    struct Node {
        StackItemType item;
        Node* next;
    };

    Node* top;
};

#endif // __STACK_H__
