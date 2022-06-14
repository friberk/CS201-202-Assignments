/*
 * Title: Heaps, Priority Queues
 * Author: Berk Cakar
 * ID: 22003021
 * Section: 3
 * Assignment: 3
 * Description: Computer class implementation file for CS202's HW3 assignment.
 */

#include "Computer.h"

Computer::Computer() {
    this->id = 0;
    this->nextAvailableTime = 0;
    this->availableStatus = true;
}

Computer::Computer(int id, int nextAvailableTime, bool availableStatus) {
    this->id = id;
    this->nextAvailableTime = nextAvailableTime;
    this->availableStatus = availableStatus;
}

Computer::Computer(const Computer& otherComputer)
    : id(otherComputer.id), nextAvailableTime(otherComputer.nextAvailableTime),
      availableStatus(otherComputer.availableStatus) {}

Computer& Computer::operator=(const Computer& otherComputer) {
    if (this != &otherComputer) {
        this->id = otherComputer.id;
        this->nextAvailableTime = otherComputer.nextAvailableTime;
        this->availableStatus = otherComputer.availableStatus;
    }

    return *this;
}

void Computer::setId(const int& id) { this->id = id; }

void Computer::setNextAvailableTime(const int& nextAvailableTime) {
    this->nextAvailableTime = nextAvailableTime;
}

void Computer::setAvailableStatus(const bool& availableStatus) {
    this->availableStatus = availableStatus;
}

int Computer::getId() const { return this->id; }

int Computer::getNextAvailableTime() const { return this->nextAvailableTime; }

bool Computer::getAvailableStatus() const { return this->availableStatus; }
