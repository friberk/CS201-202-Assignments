/**
 * Flower class header file for the CS201's HW3 assignment.
 * Author: Berk Cakar - 22003021
 */

#ifndef __FLOWER_H__
#define __FLOWER_H__

#include <iostream>
#include <string>

class Flower {
public:
    Flower();
    Flower(std::string flowerName);
    Flower(const Flower& aFlower);
    ~Flower();
    Flower& operator=(const Flower& aFlower);
    bool isEmpty() const;
    int getLength() const;
    bool add(std::string feature);
    bool remove(std::string feature);
    std::string printFlower() const;
    std::string getFlowerName() const;
    void setFlowerName(std::string flowerName);
    bool findFeature(std::string feature) const;

private:
    struct FeatureNode {
        std::string feature;
        FeatureNode* next;
    };
    int size;
    std::string flowerName;
    FeatureNode* head; // the features are stored in a sorted singly linear linked list
    // ...
    // you may define additional member functions and data members, if necessary
};

#endif // __FLOWER_H__
