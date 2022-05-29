/**
 * FlowerLibrary class header file for the CS201's HW3 assignment.
 * Author: Berk Cakar - 22003021
 */

#ifndef __FLOWERLIBRARY_H__
#define __FLOWERLIBRARY_H__

#include "FlowerList.h"

class FlowerLibrary {
public:
    FlowerLibrary();
    ~FlowerLibrary();
    void addFlower(std::string name);
    void removeFlower(std::string name);
    void listFlowers() const;
    void listFeatures(std::string name) const;
    void addFeature(std::string name, std::string feature);
    void removeFeature(std::string name, std::string feature);
    void findFlowers(std::string feature) const;

private:
    FlowerList flowers;
    // ...
    // you may define additional member functions and data members, if necessary
    void toLower(std::string& str) const;
};

#endif // __FLOWERLIBRARY_H__
