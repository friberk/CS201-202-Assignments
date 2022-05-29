/**
 * Cabinet class implementation file for the CS201's HW1 assingment.
 * Author: Berk Cakar - 22003021
 */

#include "Cabinet.h"

Cabinet::Cabinet() {
    this->id = 0;
    this->rows = 0;
    this->columns = 0;
    this->emptySlots = 0;
    this->cabinet2D = NULL;
}

Cabinet::Cabinet(int id, int rows, int columns) {
    this->id = id;
    this->rows = rows;
    this->columns = columns;
    this->emptySlots = rows * columns;

    this->cabinet2D = new Chemical*[rows];
    for (int i = 0; i < rows; i++) {
        this->cabinet2D[i] = new Chemical[columns];
    }
}

Cabinet::Cabinet(int id, int rows, int columns, char* letters) {
    this->id = id;
    this->rows = rows;
    this->columns = columns;
    this->emptySlots = rows * columns;

    this->cabinet2D = new Chemical*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->cabinet2D[i] = new Chemical[this->columns];
    }

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns; j++) {
            std::string location = "";
            location.push_back(letters[i]);
            location.push_back('0' + (j + 1));
            this->cabinet2D[i][j].setLocation(location);
            this->cabinet2D[i][j].setCabinetId(id);
        }
    }
}

Cabinet::Cabinet(const Cabinet& cabinet)
    : id(cabinet.id), rows(cabinet.rows), columns(cabinet.columns), emptySlots(cabinet.emptySlots) {
    if (rows > 0 && columns > 0) {
        this->cabinet2D = new Chemical*[rows];
        for (int i = 0; i < rows; i++) {
            this->cabinet2D[i] = new Chemical[columns];
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                this->cabinet2D[i][j] = cabinet.cabinet2D[i][j];
            }
        }
    }

    else {
        this->cabinet2D = NULL;
    }
}

Cabinet& Cabinet::operator=(const Cabinet& cabinet) {
    if (&cabinet != this) {
        for (int i = 0; i < this->rows; i++) {
            delete[] this->cabinet2D[i];
        }
        delete[] this->cabinet2D;
        this->rows = cabinet.rows;
        this->columns = cabinet.columns;
        this->id = cabinet.id;
        this->emptySlots = cabinet.emptySlots;
        if (this->rows > 0 && this->columns > 0) {
            this->cabinet2D = new Chemical*[rows];
            for (int i = 0; i < this->rows; i++) {
                this->cabinet2D[i] = new Chemical[columns];
            }
        } else {
            this->cabinet2D = NULL;
        }
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->columns; j++) {
                this->cabinet2D[i][j] = cabinet.cabinet2D[i][j];
            }
        }
    }

    return *this;
}

Cabinet::~Cabinet() {
    if (this->cabinet2D == NULL) {
        return;
    }

    for (int i = 0; i < this->rows; i++) {
        delete[] this->cabinet2D[i];
    }
    delete[] this->cabinet2D;
}

int Cabinet::getId() const { return this->id; }

void Cabinet::setId(int id) { this->id = id; }

int Cabinet::getRows() const { return this->rows; }

void Cabinet::setRows(int rows) { this->rows = rows; }

int Cabinet::getColumns() const { return this->columns; }

void Cabinet::setColumns(int columns) { this->columns = columns; }

int Cabinet::getEmptySlots() const { return this->emptySlots; }

void Cabinet::setEmptySlots(int emptySlots) { this->emptySlots = emptySlots; }

Chemical** Cabinet::getCabinet2D() const { return this->cabinet2D; }

void Cabinet::setCabinet2D(Chemical** cabinet2D) { this->cabinet2D = cabinet2D; }
