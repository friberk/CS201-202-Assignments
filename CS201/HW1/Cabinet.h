/**
 * Cabinet class header file for the CS201's HW1 assingment.
 * Author: Berk Cakar - 22003021
 */

#ifndef __CABINET_H__
#define __CABINET_H__

#include "Chemical.h"

class Cabinet {
public:
    Cabinet();
    Cabinet(int id, int rows, int columns);
    Cabinet(int id, int rows, int columns, char* letters);
    Cabinet(const Cabinet& cabinet);
    ~Cabinet();
    Cabinet& operator=(const Cabinet& cabinet);
    int getId() const;
    void setId(const int id);
    int getRows() const;
    void setRows(int rows);
    int getColumns() const;
    void setColumns(int columns);
    int getEmptySlots() const;
    void setEmptySlots(int emptySlots);
    Chemical** getCabinet2D() const;
    void setCabinet2D(Chemical** cabinet2D);

private:
    int id;
    int rows;
    int columns;
    int emptySlots;
    Chemical** cabinet2D;
};

#endif // __CABINET_H__
