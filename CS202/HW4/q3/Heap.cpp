/*
 * Title: CS202 Spring 2022
 * Author: Berk Çakar
 * ID: 22003021
 * Section: 3
 * Assignment: 4
 * Description: Heap class implementation file for CS202's HW4 assignment.
 */

#include "Heap.h"
#include <cstddef>

Heap::Heap() {
    this->items = NULL;
    this->capacity = 0;
    this->currentSize = 0;
}

Heap::Heap(const Heap& otherHeap) {
    if (otherHeap.items == NULL || otherHeap.capacity == 0 || otherHeap.currentSize == 0) {
        this->items = NULL;
        this->capacity = 0;
        this->currentSize = 0;
    }

    else {
        this->items = new HeapItemType[otherHeap.capacity];
        this->capacity = otherHeap.capacity;
        this->currentSize = otherHeap.currentSize;

        for (int i = 0; i < this->currentSize; i++) {
            this->items[i] = otherHeap.items[i];
        }
    }
}

Heap& Heap::operator=(const Heap& otherHeap) {
    if (this != &otherHeap) {
        if (this->items != NULL) {
            delete[] this->items;
            this->items = NULL;
        }

        this->items = new HeapItemType[otherHeap.capacity];
        this->capacity = otherHeap.capacity;
        this->currentSize = otherHeap.currentSize;

        for (int i = 0; i < this->currentSize; i++) {
            this->items[i] = otherHeap.items[i];
        }
    }

    return *this;
}

Heap::~Heap() {
    this->capacity = 0;
    this->currentSize = 0;
    if (this->items != NULL) {
        delete[] this->items;
        this->items = NULL;
    }
}

bool Heap::heapIsEmpty() const {
    if (this->items == NULL || this->capacity == 0 || this->currentSize == 0) {
        return true;
    }

    else {
        return false;
    }
}

void Heap::heapInsert(const HeapItemType& newItem) {
    if (heapIsEmpty()) {
        this->capacity = 1;
        this->items = new HeapItemType[this->capacity];
        this->items[0] = newItem;
        this->currentSize++;

        return;
    }

    else if (this->currentSize >= this->capacity) {
        expandHeap();
    }

    int place = this->currentSize;
    int parent = (place - 1) / 2;

    items[place] = newItem;

    while (place > 0 && items[parent].priority > items[place].priority) {
        HeapItemType temp = items[place];
        items[place] = items[parent];
        items[parent] = temp;

        place = parent;
        parent = (place - 1) / 2;
    }
    this->currentSize++;
}

void Heap::heapDelete(HeapItemType& rootItem) {
    if (heapIsEmpty()) {
        return;
    }

    else if (this->currentSize == 1) {
        rootItem = this->items[0];
        this->currentSize--;
        if (this->items != NULL) {
            delete[] this->items;
            this->items = NULL;
        }
        this->capacity = 0;
        return;
    }

    else {
        rootItem = items[0];
        items[0] = items[this->currentSize - 1];
        this->currentSize--;
        heapRebuild(0);

        if (this->currentSize > 0 && this->currentSize == this->capacity / 4) {
            int newCapacity = this->capacity / 2;
            HeapItemType* newItems = new HeapItemType[newCapacity];

            for (int i = 0; i < this->currentSize; i++) {
                newItems[i] = items[i];
            }

            if (this->items != NULL) {
                delete[] this->items;
                this->items = NULL;
            }
            this->capacity = newCapacity;
            this->items = newItems;
        }
    }
}

void Heap::decreaseKey(const int& key, const int& newPriority) {
    int index = 0;
    for (int i = 0; i < this->currentSize; i++) {
        if (this->items[i].key == key) {
            index = i;
            break;
        }
    }

    items[index].priority = newPriority;

    int parent = (index - 1) / 2;
    while (index > 0 && items[parent].priority > items[index].priority) {
        HeapItemType temp = items[index];
        items[index] = items[parent];
        items[parent] = temp;

        index = parent;
        parent = (index - 1) / 2;
    }
}

void Heap::expandHeap() {
    if (heapIsEmpty()) {
        return;
    }

    else {
        int newCapacity = 2 * this->capacity;
        HeapItemType* newItems = new HeapItemType[newCapacity];

        for (int i = 0; i < this->currentSize; i++) {
            newItems[i] = this->items[i];
        }

        if (this->items != NULL) {
            delete[] this->items;
            this->items = NULL;
        }
        this->capacity = newCapacity;
        this->items = newItems;
    }
}

void Heap::heapRebuild(int root) {
    int child = 2 * root + 1;
    if (child < this->currentSize) {
        int rightChild = child + 1;
        if ((rightChild < this->currentSize) && (items[rightChild].priority < items[child].priority)) {
            child = rightChild;
        }

        if (items[child].priority < items[root].priority) {
            HeapItemType temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            heapRebuild(child);
        }
    }
}
