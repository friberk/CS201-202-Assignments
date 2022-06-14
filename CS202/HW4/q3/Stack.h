/*
 * Title: CS202 Spring 2022
 * Author: Berk Çakar
 * ID: 22003021
 * Section: 3
 * Assignment: 4
 * Description: Stack class header file for CS202's HW4 assignment.
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

    bool isEmpty() const;
    bool push(const StackItemType& newItem);
    bool pop();
    bool pop(StackItemType& stackTop);
    bool getTop(StackItemType& stackTop) const;

private:
    struct Node {
        StackItemType item;
        Node* next;
    };

    Node* top;
};

#endif // __STACK_H__
