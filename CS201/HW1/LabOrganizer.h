/**
 * LabOrganizer class header file for the CS201's HW1 assingment.
 * Author: Berk Cakar - 22003021
 */

#ifndef __LABORGANIZER_H__
#define __LABORGANIZER_H__

#include "Cabinet.h"
#include <iostream>

class LabOrganizer {
public:
    LabOrganizer();
    ~LabOrganizer();

    void addCabinet(int id, int rows, int columns);
    void removeCabinet(int id);
    void listCabinets();
    void cabinetContents(int id);
    void placeChemical(int cabinetId, std::string location, std::string chemType, int chemID);
    void findChemical(int id);
    void removeChemical(int id);
    // ...
    // you may define additional member functions and data members, if necessary
    Cabinet* expandCabinetArr(const Cabinet* arr, int expandSize);
    void dynamicRemoveHelper(Cabinet*& arr, int removeIndex);
    bool combustiveAvailabilityChecker(int cabinetIndex, int rowIndex, int columnIndex);
    std::string nearestLocations(std::string chemType, int cabinetIndex, int rowIndex,
                                 int columnIndex);
    void listCabinetChemicals(int cabinetIndex);

private:
    int cabinetCount;
    Cabinet* cabinetArr;
    char* letters;
};

#endif // __LABORGANIZER_H__
