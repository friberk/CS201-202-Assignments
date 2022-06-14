/*
 * Title: Heaps, Priority Queues
 * Author: Berk Cakar
 * ID: 22003021
 * Section: 3
 * Assignment: 3
 * Description: PriorityQueue class header file for CS202's HW3 assignment.
 */

#ifndef __PRIORITYQUEUE_H__
#define __PRIORITYQUEUE_H__

#include "Heap.h"

typedef HeapItemType PQueueItemType;

class PriorityQueue {
public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue& otherPriorityQueue);
    PriorityQueue& operator=(const PriorityQueue& otherPriorityQueue);

    bool pqIsEmpty() const;
    void pqInsert(const PQueueItemType& newItem);
    void pqDelete(PQueueItemType& priorityItem);

private:
    Heap heap;
};

#endif // __PRIORITYQUEUE_H__
