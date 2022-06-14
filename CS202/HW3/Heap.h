/*
 * Title: Heaps, Priority Queues
 * Author: Berk Cakar
 * ID: 22003021
 * Section: 3
 * Assignment: 3
 * Description: Heap class header file for CS202's HW3 assignment.
 */

#ifndef __HEAP_H__
#define __HEAP_H__

#include "Request.h"

typedef Request HeapItemType;

class Heap {
public:
    Heap();
    Heap(const Heap& otherHeap);
    Heap& operator=(const Heap& otherHeap);
    ~Heap();

    bool heapIsEmpty() const;
    void heapInsert(const HeapItemType& newItem);
    void heapDelete(HeapItemType& rootItem);

private:
    void expandHeap();
    void heapRebuild(int root);

    HeapItemType* items;
    int capacity;
    int currentSize;
};

#endif // __HEAP_H__
