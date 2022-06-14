/*
 * Title: CS202 Spring 2022
 * Author: Berk Çakar
 * ID: 22003021
 * Section: 3
 * Assignment: 4
 * Description: List class header file for CS202's HW4 assignment.
 */

#ifndef __LIST_H__
#define __LIST_H__

template <class ListItemType>
class List {
public:
    List();
    List(const List& aList);
    List& operator=(const List& aList);
    ~List();

    bool isEmpty() const;
    int getLength() const;
    bool insert(int index, ListItemType newItem);
    bool remove(int index);
    bool retrieve(int index, ListItemType& dataItem) const;

private:
    struct ListNode {
        ListItemType item;
        ListNode* next;
    };

    int size;
    ListNode* head;

    ListNode* find(int index) const;
};

#endif // __LIST_H__
