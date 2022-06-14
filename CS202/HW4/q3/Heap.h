/*
 * Title: CS202 Spring 2022
 * Author: Berk Çakar
 * ID: 22003021
 * Section: 3
 * Assignment: 4
 * Description: Heap class header file for CS202's HW4 assignment.
 */

#ifndef __HEAP_H__
#define __HEAP_H__

struct priorityNode {
    int priority;
    int key;
};

typedef priorityNode HeapItemType;

class Heap {
public:
    Heap();
    Heap(const Heap& otherHeap);
    Heap& operator=(const Heap& otherHeap);
    ~Heap();

    bool heapIsEmpty() const;
    void heapInsert(const HeapItemType& newItem);
    void heapDelete(HeapItemType& rootItem);
    void decreaseKey(const int& key, const int& newPriority);

private:
    void expandHeap();
    void heapRebuild(int root);

    HeapItemType* items;
    int capacity;
    int currentSize;
};

#endif // __HEAP_H__
