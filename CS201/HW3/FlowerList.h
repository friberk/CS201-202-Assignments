/**
 * FlowerList class header file for the CS201's HW3 assignment.
 * Author: Berk Cakar - 22003021
 */

#ifndef __FLOWERLIST_H__
#define __FLOWERLIST_H__

#include "Flower.h"

class FlowerList {
public:
    FlowerList();
    FlowerList(const FlowerList& aList);
    ~FlowerList();
    FlowerList& operator=(const FlowerList& aList);
    bool isEmpty() const;
    int getLength() const;
    bool retrieve(std::string flowerName, Flower& flower) const;
    bool retrieve(std::string flowerName, Flower** flower) const;
    bool add(std::string flowerName);
    bool remove(std::string flowerName);
    void listFlowers() const;
    void listFeatures(std::string flowerName) const;
    std::string findFlowers(std::string feature) const;

private:
    struct FlowerNode {
        Flower f;
        FlowerNode* next;
    };
    int size;
    FlowerNode* head; // the flowers are stored in a sorted singly linear linked list
    // ...
    // you may define additional member functions and data members, if necessary
};

#endif // __FLOWERLIST_H__
