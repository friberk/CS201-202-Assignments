/**
 * Chemical class header file for the CS201's HW1 assingment.
 * Author: Berk Cakar - 22003021
 */

#ifndef __CHEMICAL_H__
#define __CHEMICAL_H__

#include <string>

class Chemical {
public:
    Chemical();
    Chemical(int cabinetId, int chemId, std::string chemType, std::string location);
    Chemical(const Chemical& chemical);
    Chemical& operator=(const Chemical& chemical);
    int getCabinetId() const;
    void setCabinetId(int cabinetId);
    int getChemId() const;
    void setChemId(int chemId);
    std::string getChemType() const;
    void setChemType(std::string chemType);
    std::string getLocation() const;
    void setLocation(std::string location);

private:
    int cabinetId;
    int chemId;
    std::string chemType;
    std::string location;
};

#endif // __CHEMICAL_H__
