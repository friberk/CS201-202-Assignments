/**
 * ADT Stack implementation file for the CS201's HW4 assignment.
 * Author: Berk Cakar - 22003021
 */

#include "Stack.h"

template <class StackItemType>
Stack<StackItemType>::Stack() {
    this->top = NULL;
}
template Stack<double>::Stack();
template Stack<std::string>::Stack();

template <class StackItemType>
Stack<StackItemType>::~Stack() {
    while (!isEmpty()) {
        pop();
    }
    this->top = NULL;
}
template Stack<double>::~Stack();
template Stack<std::string>::~Stack();

template <class StackItemType>
Stack<StackItemType>::Stack(const Stack<StackItemType>& otherStack) {
    if (otherStack.isEmpty()) {
        this->top = NULL;
    }

    else {
        this->top = new Node;
        this->top->item = otherStack.top->item;
        Node* cur = this->top;
        Node* cur2 = otherStack.top->next;
        while (cur2 != NULL) {
            cur->next = new Node;
            cur->next->item = cur2->item;
            cur = cur->next;
            cur2 = cur2->next;
        }
        cur->next = NULL;
    }
}
template Stack<double>::Stack(const Stack<double>& otherStack);
template Stack<std::string>::Stack(const Stack<std::string>& otherStack);

template <class StackItemType>
Stack<StackItemType>& Stack<StackItemType>::operator=(const Stack<StackItemType>& otherStack) {
    if (this != &otherStack) {
        while (!isEmpty()) {
            pop();
        }
        if (otherStack.isEmpty()) {
            this->top = NULL;
        }

        else {
            this->top = new Node;
            this->top->item = otherStack.top->item;
            Node* cur = this->top;
            Node* cur2 = otherStack.top->next;
            while (cur2 != NULL) {
                cur->next = new Node;
                cur->next->item = cur2->item;
                cur = cur->next;
                cur2 = cur2->next;
            }
            cur->next = NULL;
        }
    }

    return *this;
}
template Stack<double>& Stack<double>::operator=(const Stack<double>& otherStack);
template Stack<std::string>& Stack<std::string>::operator=(const Stack<std::string>& otherStack);

template <class StackItemType>
bool Stack<StackItemType>::isEmpty() const {
    return this->top == NULL;
}
template bool Stack<double>::isEmpty() const;
template bool Stack<std::string>::isEmpty() const;

template <class StackItemType>
bool Stack<StackItemType>::push(const StackItemType& newItem) {
    if (isEmpty()) {
        this->top = new Node;
        this->top->item = newItem;
        this->top->next = NULL;
        return true;
    }

    else {
        Node* newTop = new Node;
        newTop->item = newItem;
        newTop->next = this->top;
        this->top = newTop;
        return true;
    }
}
template bool Stack<double>::push(const double& newItem);
template bool Stack<std::string>::push(const std::string& newItem);

template <class StackItemType>
bool Stack<StackItemType>::pop() {
    if (!isEmpty()) {
        Node* temp = this->top;
        this->top = top->next;
        temp->next = NULL;
        delete temp;
        return true;
    }

    else {
        return false;
    }
}
template bool Stack<double>::pop();
template bool Stack<std::string>::pop();

template <class StackItemType>
bool Stack<StackItemType>::pop(StackItemType& stackTop) {
    if (!isEmpty()) {
        Node* temp = this->top;
        this->top = top->next;
        stackTop = temp->item;
        temp->next = NULL;
        delete temp;
        return true;
    }

    else {
        return false;
    }
}
template bool Stack<double>::pop(double& stackTop);
template bool Stack<std::string>::pop(std::string& stackTop);

template <class StackItemType>
bool Stack<StackItemType>::getTop(StackItemType& stackTop) const {
    if (!isEmpty()) {
        stackTop = this->top->item;
        return true;
    }

    else {
        return false;
    }
}
template bool Stack<double>::getTop(double& stackTop) const;
template bool Stack<std::string>::getTop(std::string& stackTop) const;

template <class StackItemType>
void Stack<StackItemType>::printStack() const {
    if (isEmpty()) {
        std::cout << "The stack is empty." << std::endl;
    }

    else {
        Node* cur = this->top;
        while (cur != NULL) {
            std::cout << cur->item << " ";
            // printf("% ", cur->item);
            cur = cur->next;
        }
        std::cout << std::endl;
    }
}
template void Stack<double>::printStack() const;
template void Stack<std::string>::printStack() const;
