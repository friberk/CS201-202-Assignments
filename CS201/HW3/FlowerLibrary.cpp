/**
 * FlowerLibrary class implementation file for the CS201's HW3 assignment.
 * Author: Berk Cakar - 22003021
 */

#include "FlowerLibrary.h"

FlowerLibrary::FlowerLibrary() : flowers() {}

FlowerLibrary::~FlowerLibrary() {}

void FlowerLibrary::addFlower(std::string name) {
    toLower(name);
    flowers.add(name);
}

void FlowerLibrary::removeFlower(std::string name) {
    toLower(name);
    flowers.remove(name);
}

void FlowerLibrary::listFlowers() const { flowers.listFlowers(); }

void FlowerLibrary::listFeatures(std::string name) const {
    toLower(name);
    flowers.listFeatures(name);
}

void FlowerLibrary::addFeature(std::string name, std::string feature) {
    toLower(name);
    toLower(feature);
    Flower* flower;

    if (flowers.retrieve(name, &flower) == true) {
        flower->add(feature);
    } else {
        std::cout << name << " isn't found in library." << std::endl;
    }
}

void FlowerLibrary::removeFeature(std::string name, std::string feature) {
    toLower(name);
    toLower(feature);
    Flower* flower;

    if (flowers.retrieve(name, &flower) == true) {
        flower->remove(feature);
    } else {
        std::cout << name << " isn't found in library." << std::endl;
    }
}

void FlowerLibrary::findFlowers(std::string feature) const {
    toLower(feature);
    std::cout << flowers.findFlowers(feature) << std::endl;
}

void FlowerLibrary::toLower(std::string& str) const {
    for (size_t i = 0; i < str.length(); i++) {
        str[i] = std::tolower(str[i]);
    }
}
