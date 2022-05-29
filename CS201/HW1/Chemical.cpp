#include "Chemical.h"

/**
 * Chemical class implementation file for the CS201's HW1 assingment.
 * Author: Berk Cakar - 22003021
 */

Chemical::Chemical() {
    this->cabinetId = 0;
    this->chemId = 0;
    this->chemType = "+";
    this->location = "";
}

Chemical::Chemical(int cabinetId, int chemId, std::string chemType, std::string location) {
    this->cabinetId = cabinetId;
    this->chemId = chemId;
    this->chemType = chemType;
    this->location = location;
}

Chemical::Chemical(const Chemical& chemical)
    : cabinetId(chemical.cabinetId), chemId(chemical.chemId), chemType(chemical.chemType),
      location(chemical.location) {}

Chemical& Chemical::operator=(const Chemical& chemical) {
    this->cabinetId = chemical.cabinetId;
    this->chemId = chemical.chemId;
    this->chemType = chemical.chemType;
    this->location = chemical.location;

    return *this;
}

int Chemical::getCabinetId() const { return cabinetId; }

void Chemical::setCabinetId(int cabinetId) { this->cabinetId = cabinetId; }

int Chemical::getChemId() const { return chemId; }

void Chemical::setChemId(int chemId) { this->chemId = chemId; }

std::string Chemical::getChemType() const { return chemType; }

void Chemical::setChemType(std::string chemType) { this->chemType = chemType; }

std::string Chemical::getLocation() const { return location; }

void Chemical::setLocation(std::string location) { this->location = location; }
