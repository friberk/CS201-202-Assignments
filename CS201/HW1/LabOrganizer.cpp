/**
 * LabOrganizer class implementation file for the CS201's HW1 assingment.
 * Author: Berk Cakar - 22003021
 */

#include "LabOrganizer.h"

LabOrganizer::LabOrganizer() {
    this->cabinetCount = 0;
    this->cabinetArr = NULL;

    this->letters = new char[9];
    this->letters[0] = 'A';
    this->letters[1] = 'B';
    this->letters[2] = 'C';
    this->letters[3] = 'D';
    this->letters[4] = 'E';
    this->letters[5] = 'F';
    this->letters[6] = 'G';
    this->letters[7] = 'H';
    this->letters[8] = 'I';
}

LabOrganizer::~LabOrganizer() {
    delete[] this->letters;
    delete[] this->cabinetArr;
}

void LabOrganizer::addCabinet(const int id, const int rows, const int columns) {
    if (rows > 9 || columns > 9) {
        std::cout << "Cannot add the cabinet: dimensions are out of bounds" << std::endl;
        return;
    }

    if (id == 0) {
        std::cout << "Cannot add the cabinet: ID 0 is reserved for default cabinets" << std::endl;
        return;
    }

    for (int i = 0; i < this->cabinetCount; i++) {
        if (this->cabinetArr[i].getId() == id) {
            std::cout << "Cannot add the cabinet: ID " << id << " already in the system"
                      << std::endl;
            return;
        }
    }

    // Declare the cabinet.
    this->cabinetArr = expandCabinetArr(this->cabinetArr, 1);
    this->cabinetArr[this->cabinetCount - 1] = Cabinet(id, rows, columns, this->letters);

    std::cout << "Added a cabinet: ID " << id << " and dimensions " << rows << " to " << columns
              << std::endl;
}

void LabOrganizer::removeCabinet(const int id) {
    bool exists = false;
    int foundIndex;

    if (this->cabinetCount != 0) {
        for (int i = 0; i < this->cabinetCount; i++) {
            if (this->cabinetArr[i].getId() == id) {
                exists = true;
                foundIndex = i;
                break;
            }
        }
    }

    else {
        std::cout << "Cannot remove the cabinet: There is no cabinet in the system" << std::endl;
        return;
    }

    if (exists == true) {
        for (int i = 0; i < this->cabinetArr[foundIndex].getRows(); i++) {
            for (int j = 0; j < this->cabinetArr[foundIndex].getColumns(); j++) {
                if (this->cabinetArr[foundIndex].getCabinet2D()[i][j].getChemType() != "+") {
                    std::cout << "Chemical "
                              << this->cabinetArr[foundIndex].getCabinet2D()[i][j].getChemId()
                              << " removed from cabinet " << id << std::endl;
                }

                // Remove all the chemicals from its shelves
                this->cabinetArr[foundIndex].getCabinet2D()[i][j] = Chemical();
            }
        }

        // Deallocate the whole cabinet
        dynamicRemoveHelper(this->cabinetArr, foundIndex);

        std::cout << "Cabinet " << id << " has been removed" << std::endl;
    }

    else {
        std::cout << "Cabinet " << id << " does not exist in the system" << std::endl;
    }
}

void LabOrganizer::listCabinets() {
    if (this->cabinetCount != 0) {
        std::cout << "List of all cabinets:" << std::endl;
        for (int i = 0; i < this->cabinetCount; i++) {
            std::cout << "ID: " << this->cabinetArr[i].getId()
                      << ", Dim: " << this->cabinetArr[i].getRows() << "x"
                      << this->cabinetArr[i].getColumns()
                      << ", Number of empty slots: " << this->cabinetArr[i].getEmptySlots()
                      << std::endl;
        }
    }

    else {
        std::cout << "There is no cabinet in the system to list" << std::endl;
    }
}

void LabOrganizer::cabinetContents(const int id) {
    int cabinetIndex;
    bool cabinetExists = false;

    for (int i = 0; i < this->cabinetCount; i++) {
        if (this->cabinetArr[i].getId() == id) {
            cabinetIndex = i;
            cabinetExists = true;
            break;
        }
    }

    if (cabinetExists == false) {
        std::cout << "Cabinet " << id << " is not in the system" << std::endl;
        return;
    }

    std::cout << "ID: " << id << ", " << this->cabinetArr[cabinetIndex].getRows() << "x"
              << this->cabinetArr[cabinetIndex].getColumns()
              << ", empty: " << this->cabinetArr[cabinetIndex].getEmptySlots() << ". Chemicals: ";

    listCabinetChemicals(cabinetIndex);

    for (int i = 0; i < this->cabinetArr[cabinetIndex].getRows() + 1; i++) {
        if (i == 0) {
            for (int j = 0; j < this->cabinetArr[cabinetIndex].getColumns() + 1; j++) {
                if (j == 0) {
                    std::cout << "  ";
                }

                else {
                    std::cout << j << " ";
                }
            }
        }

        else {
            for (int k = 0; k < this->cabinetArr[cabinetIndex].getColumns() + 1; k++) {
                if (k == 0) {
                    std::cout << this->letters[i - 1] << " ";
                }

                else {
                    std::cout << this->cabinetArr[cabinetIndex]
                                     .getCabinet2D()[i - 1][k - 1]
                                     .getChemType()[0]
                              << " ";
                }
            }
        }

        std::cout << std::endl;
    }
}

void LabOrganizer::placeChemical(const int cabinetId, const std::string location,
                                 const std::string chemType, const int chemID) {
    bool cabinetExists = false;
    int cabinetIndex = 0;

    int rowIndex = static_cast<int>(location[0]) - 65;
    int columnIndex = static_cast<int>(location[1]) - 49;

    if (chemType != "retardant" && chemType != "combustive" && chemType != "+") {
        std::cout << "Cannot place the chemical: Invalid chemical type" << std::endl;
        return;
    }

    if (chemID == 0) {
        std::cout << "Cannot place the chemical: Chemical ID 0 is reserved for empty slots"
                  << std::endl;
        return;
    }

    for (int i = 0; i < this->cabinetCount; i++) {
        for (int j = 0; j < this->cabinetArr[i].getRows(); j++) {
            for (int k = 0; k < this->cabinetArr[i].getColumns(); k++) {
                if (this->cabinetArr[i].getCabinet2D()[j][k].getChemId() == chemID) {
                    std::cout << "Chemical with ID " << chemID << " already exist in the system"
                              << std::endl;
                    return;
                };
            }
        }
    }

    for (int i = 0; i < this->cabinetCount; i++) {
        if (this->cabinetArr[i].getId() == cabinetId) {
            cabinetExists = true;
            cabinetIndex = i;
            break;
        }
    }

    if (cabinetExists == false) {
        std::cout << "Cabinet with ID " << cabinetId << " does not exist in the system"
                  << std::endl;
        return;
    }

    std::string nearestLocationsStr =
        nearestLocations(chemType, cabinetIndex, rowIndex, columnIndex);

    if (cabinetArr[cabinetIndex].getCabinet2D()[rowIndex][columnIndex].getChemType() != "+") {
        std::cout << "Location " << location << " in cabinet " << cabinetId
                  << " is already occupied. Nearest possible locations for this chemical: "
                  << (nearestLocationsStr.size()
                          ? nearestLocationsStr
                          : "There is not any suitable location to place this chemical")
                  << std::endl;
        return;
    }

    if (chemType == "retardant") {
        this->cabinetArr[cabinetIndex].getCabinet2D()[rowIndex][columnIndex] =
            Chemical(cabinetId, chemID, chemType, location);

        std::cout << "Retardant chemical with ID " << chemID << " has been placed at location "
                  << location << " in cabinet " << cabinetId << std::endl;
        this->cabinetArr[cabinetIndex].setEmptySlots(
            this->cabinetArr[cabinetIndex].getEmptySlots() - 1);
    }

    else {
        if (combustiveAvailabilityChecker(cabinetIndex, rowIndex, columnIndex) == true) {
            this->cabinetArr[cabinetIndex].getCabinet2D()[rowIndex][columnIndex] =
                Chemical(cabinetId, chemID, chemType, location);

            std::cout << "Combustive chemical with ID " << chemID << " has been placed at location "
                      << location << " in cabinet " << cabinetId << std::endl;
            this->cabinetArr[cabinetIndex].setEmptySlots(
                this->cabinetArr[cabinetIndex].getEmptySlots() - 1);
        }

        else {
            std::cout << "Location " << location << " in cabinet " << cabinetId
                      << " is not suitable for a combustive chemical. "
                      << "Nearest possible locations for this chemical: "
                      << (nearestLocationsStr.size()
                              ? nearestLocationsStr
                              : "There is not any suitable location to place this combustive")
                      << std::endl;
        }
    }
}

void LabOrganizer::findChemical(const int id) {
    bool chemicalExist = false;

    for (int i = 0; i < this->cabinetCount; i++) {
        for (int j = 0; j < this->cabinetArr[i].getRows(); j++) {
            for (int k = 0; k < this->cabinetArr[i].getColumns(); k++) {
                if (this->cabinetArr[i].getCabinet2D()[j][k].getChemId() == id) {
                    chemicalExist = true;
                    std::cout << "Chemical " << id << " is at location "
                              << this->cabinetArr[i].getCabinet2D()[j][k].getLocation()
                              << " in cabinet "
                              << this->cabinetArr[i].getCabinet2D()[j][k].getCabinetId()
                              << std::endl;
                };
            }
        }
    }

    if (chemicalExist == false) {
        std::cout << "Chemical " << id << " is not in the system" << std::endl;
    }
}

void LabOrganizer::removeChemical(const int id) {
    bool chemicalExist = false;

    for (int i = 0; i < this->cabinetCount; i++) {
        for (int j = 0; j < this->cabinetArr[i].getRows(); j++) {
            for (int k = 0; k < cabinetArr[i].getColumns(); k++) {
                if (this->cabinetArr[i].getCabinet2D()[j][k].getChemId() == id) {
                    chemicalExist = true;
                    std::cout << "Chemical " << id << " removed from cabinet "
                              << this->cabinetArr[i].getCabinet2D()[j][k].getCabinetId()
                              << std::endl;
                    // Reset the deleted chemical's slot
                    this->cabinetArr[i].getCabinet2D()[j][k].setChemType("+");
                    this->cabinetArr[i].getCabinet2D()[j][k].setChemId(0);
                    this->cabinetArr[i].setEmptySlots(this->cabinetArr[i].getEmptySlots() + 1);
                };
            }
        }
    }

    if (chemicalExist == false) {
        std::cout << "Chemical " << id << " is not in the system " << std::endl;
    }
}

Cabinet* LabOrganizer::expandCabinetArr(const Cabinet* cabinetArr, const int expandSize) {
    const int newSize = this->cabinetCount + expandSize;

    if (this->cabinetCount == 0) {
        this->cabinetCount = newSize;
        return new Cabinet[newSize];
    }

    Cabinet* temp = new Cabinet[newSize];

    for (int i = 0; i < this->cabinetCount; i++) {
        temp[i] = cabinetArr[i];
    }

    this->cabinetCount = newSize;

    delete[] cabinetArr;
    return temp;
}

void LabOrganizer::dynamicRemoveHelper(Cabinet*& arr, const int removeIndex) {
    if (removeIndex < this->cabinetCount && removeIndex >= 0) {
        if (this->cabinetCount == 1) {
            delete[] arr;
            arr = NULL;
            this->cabinetCount--;
        }

        else {
            const int newSize = this->cabinetCount - 1;
            Cabinet* tempCabinet = new Cabinet[newSize];

            for (int i = 0; i < removeIndex; i++) {
                tempCabinet[i] = arr[i];
            }

            for (int i = removeIndex; i < this->cabinetCount - 1; i++) {
                tempCabinet[i] = arr[i + 1];
            }

            delete[] arr;
            arr = tempCabinet;
            this->cabinetCount--;
        }
    }

    else {
        std::cout << "Cannot resize down the dynamic array: Index out of bounds" << std::endl;
    }
}

bool LabOrganizer::combustiveAvailabilityChecker(const int cabinetIndex, const int rowIndex,
                                                 const int columnIndex) {
    for (int r = -1; r <= 1; r++) {
        for (int c = -1; c <= 1; c++) {
            if (rowIndex + r >= 0 && rowIndex + r < cabinetArr[cabinetIndex].getRows() &&
                columnIndex + c >= 0 && columnIndex + c < cabinetArr[cabinetIndex].getColumns()) {
                if (!(r == 0 && c == 0)) {
                    if (this->cabinetArr[cabinetIndex]
                            .getCabinet2D()[rowIndex + r][columnIndex + c]
                            .getChemType() == "combustive") {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

std::string LabOrganizer::nearestLocations(const std::string chemType, const int cabinetIndex,
                                           const int rowIndex, const int columnIndex) {
    std::string returnStr = "";
    int factor = 1;

    if (chemType != "retardant" && chemType != "combustive") {
        return "Cannot search nearest locations: Chemical type should be \"retardant\" or "
               "\"combustive\"";
    }

    while (factor >= 1 && factor < std::max(this->cabinetArr[cabinetIndex].getRows(),
                                            this->cabinetArr[cabinetIndex].getColumns())) {
        for (int r = -1 * factor; r <= factor; r++) {
            for (int c = -factor; c <= factor; c++) {
                if (rowIndex + r >= 0 && rowIndex + r < cabinetArr[cabinetIndex].getRows() &&
                    columnIndex + c >= 0 &&
                    columnIndex + c < cabinetArr[cabinetIndex].getColumns()) {
                    if (!(r == 0 && c == 0)) {
                        if (chemType == "combustive") {
                            if (this->cabinetArr[cabinetIndex]
                                        .getCabinet2D()[rowIndex + r][columnIndex + c]
                                        .getChemType() == "+" &&
                                combustiveAvailabilityChecker(cabinetIndex, rowIndex + r,
                                                              columnIndex + c) == true) {
                                goto search;
                            }
                        }

                        else {
                            if (this->cabinetArr[cabinetIndex]
                                    .getCabinet2D()[rowIndex + r][columnIndex + c]
                                    .getChemType() == "+") {
                                goto search;
                            }
                        }
                    }
                }
            }
        }
        factor++;
    }

    return returnStr;

search:
    for (int r = -1 * factor; r <= factor; r++) {
        for (int c = -1 * factor; c <= factor; c++) {
            if (rowIndex + r >= 0 && rowIndex + r < cabinetArr[cabinetIndex].getRows() &&
                columnIndex + c >= 0 && columnIndex + c < cabinetArr[cabinetIndex].getColumns()) {
                if (!(r == 0 && c == 0)) {
                    if (chemType == "combustive") {
                        if (this->cabinetArr[cabinetIndex]
                                    .getCabinet2D()[rowIndex + r][columnIndex + c]
                                    .getChemType() == "+" &&
                            combustiveAvailabilityChecker(cabinetIndex, rowIndex + r,
                                                          columnIndex + c) == true) {
                            returnStr += this->cabinetArr[cabinetIndex]
                                             .getCabinet2D()[rowIndex + r][columnIndex + c]
                                             .getLocation() +
                                         ", ";
                        }
                    }

                    else {
                        if (this->cabinetArr[cabinetIndex]
                                .getCabinet2D()[rowIndex + r][columnIndex + c]
                                .getChemType() == "+") {
                            returnStr += this->cabinetArr[cabinetIndex]
                                             .getCabinet2D()[rowIndex + r][columnIndex + c]
                                             .getLocation() +
                                         ", ";
                        }
                    }
                }
            }
        }
    }

    returnStr.erase(returnStr.end() - 2, returnStr.end());
    return returnStr;
}

void LabOrganizer::listCabinetChemicals(const int cabinetIndex) {
    if (cabinetIndex < 0 || cabinetIndex >= this->cabinetCount) {
        std::cout << "Cabinet index out of bounds" << std::endl;
        return;
    }

    int counter = (cabinetArr[cabinetIndex].getRows() * cabinetArr[cabinetIndex].getColumns()) -
                  cabinetArr[cabinetIndex].getEmptySlots();

    if (counter != 0) {
        for (int i = 0; i < cabinetArr[cabinetIndex].getRows(); i++) {
            for (int j = 0; j < cabinetArr[cabinetIndex].getColumns(); j++) {
                if (cabinetArr[cabinetIndex].getCabinet2D()[i][j].getChemType() != "+") {
                    if (counter > 1) {
                        std::cout << cabinetArr[cabinetIndex].getCabinet2D()[i][j].getLocation()
                                  << ": "
                                  << cabinetArr[cabinetIndex].getCabinet2D()[i][j].getChemId()
                                  << ", ";
                        counter--;
                    }

                    else {
                        std::cout << cabinetArr[cabinetIndex].getCabinet2D()[i][j].getLocation()
                                  << ": "
                                  << cabinetArr[cabinetIndex].getCabinet2D()[i][j].getChemId()
                                  << std::endl;
                    }
                }
            }
        }
    }

    else {
        std::cout << "No chemicals in the cabinet" << std::endl;
    }
}
