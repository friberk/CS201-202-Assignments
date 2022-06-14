/*
 * Title: CS202 Spring 2022
 * Author: Berk Çakar
 * ID: 22003021
 * Section: 3
 * Assignment: 4
 * Description: List class implementation file for CS202's HW4 assignment.
 */

#include "Edge.h"
#include "List.h"
#include <cstddef>

template <class ListItemType>
List<ListItemType>::List() : size(0), head(NULL) {}
template List<Edge>::List();

template <class ListItemType>
List<ListItemType>::List(const List& aList) : size(aList.size) {
    if (aList.head == NULL || aList.size == 0) {
        this->head = NULL;
        this->size = 0;
    }

    else {
        this->head = new ListNode;
        this->head->item = aList.head->item;

        ListNode* cur = this->head;
        ListNode* cur2 = aList.head->next;
        while (cur2 != NULL) {
            cur->next = new ListNode;
            cur->next->item = cur2->item;
            cur = cur->next;
            cur2 = cur2->next;
        }
        cur->next = NULL;
    }
}
template List<Edge>::List(const List& aList);

template <class ListItemType>
List<ListItemType>& List<ListItemType>::operator=(const List& aList) {
    if (this != &aList) {
        if (this->head != NULL || this->size != 0) {
            while (this->head != NULL) {
                remove(1);
            }
            this->head = NULL;
        }

        if (aList.head == NULL || aList.size == 0) {
            this->head = NULL;
            this->size = 0;
        }

        else {
            this->head = new ListNode;
            this->head->item = aList.head->item;

            ListNode* cur = this->head;
            ListNode* cur2 = aList.head->next;
            while (cur2 != NULL) {
                cur->next = new ListNode;
                cur->next->item = cur2->item;
                cur = cur->next;
                cur2 = cur2->next;
            }
            cur->next = NULL;
            this->size = aList.size;
        }
    }

    return *this;
}
template List<Edge>& List<Edge>::operator=(const List& aList);

template <class ListItemType>
List<ListItemType>::~List() {
    while (this->head != NULL) {
        remove(1);
    }
    this->head = NULL;
}
template List<Edge>::~List();

template <class ListItemType>
bool List<ListItemType>::isEmpty() const {
    if (this->size > 0) {
        return false;
    }

    return true;
}
template bool List<Edge>::isEmpty() const;

template <class ListItemType>
int List<ListItemType>::getLength() const {
    return this->size;
}
template int List<Edge>::getLength() const;

template <class ListItemType>
bool List<ListItemType>::insert(int index, ListItemType newItem) {
    if (index < 1 || index > getLength() + 1) {
        return false;
    }

    ListNode* newNode = new ListNode;
    newNode->item = newItem;
    newNode->next = NULL;

    if (this->head == NULL || this->size == 0) {
        this->head = newNode;
        this->size++;
        return true;
    }

    else if (index == 1) {
        newNode->next = this->head;
        this->head = newNode;
        this->size++;
        return true;
    }

    else {
        ListNode* target = find(index - 1);
        ListNode* temp = target->next;
        target->next = newNode;
        newNode->next = temp;
        this->size++;
        return true;
    }
}
template bool List<Edge>::insert(int index, Edge newItem);

template <class ListItemType>
bool List<ListItemType>::remove(int index) {
    if (index < 1 || index > getLength()) {
        return false;
    }

    if (index == 1) {
        ListNode* temp = head;
        this->head = head->next;
        this->size--;
        if (temp != NULL) {
            delete temp;
            temp = NULL;
        }
        return true;
    }

    else {
        ListNode* target = find(index - 1);
        ListNode* cur = target->next;
        target->next = cur->next;
        this->size--;
        if (cur != NULL) {
            delete cur;
            cur = NULL;
        }
        return true;
    }
}
template bool List<Edge>::remove(int index);

template <class ListItemType>
bool List<ListItemType>::retrieve(int index, ListItemType& dataItem) const {
    if (index < 1 || index > getLength()) {
        return false;
    }

    ListNode* node = find(index);
    dataItem = node->item;
    return true;
}
template bool List<Edge>::retrieve(int index, Edge& dataItem) const;

template <class ListItemType>
typename List<ListItemType>::ListNode* List<ListItemType>::find(int index) const {
    if (index < 1 || index > getLength()) {
        return NULL;
    }

    else {
        ListNode* cur = head;
        for (int i = 0; i < index - 1; i++) {
            cur = cur->next;
        }
        return cur;
    }
}
template List<Edge>::ListNode* List<Edge>::find(int index) const;
