/*
 * Title: Heaps, Priority Queues
 * Author: Berk Cakar
 * ID: 22003021
 * Section: 3
 * Assignment: 3
 * Description: PriorityQueue class implementation file for CS202's HW3 assignment.
 */

#include "PriorityQueue.h"
#include <iostream>

PriorityQueue::PriorityQueue() {} // An empty constructor for making g++ happy...

PriorityQueue::PriorityQueue(const PriorityQueue& otherPriorityQueue) {
    this->heap = otherPriorityQueue.heap;
}

PriorityQueue& PriorityQueue::operator=(const PriorityQueue& otherPriorityQueue) {
    if (this != &otherPriorityQueue) {
        this->heap = otherPriorityQueue.heap;
    }

    return *this;
}

bool PriorityQueue::pqIsEmpty() const { return heap.heapIsEmpty(); }

void PriorityQueue::pqInsert(const PQueueItemType& newItem) { heap.heapInsert(newItem); }

void PriorityQueue::pqDelete(PQueueItemType& priorityItem) { heap.heapDelete(priorityItem); }
