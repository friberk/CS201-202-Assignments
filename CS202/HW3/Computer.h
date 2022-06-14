/*
 * Title: Heaps, Priority Queues
 * Author: Berk Cakar
 * ID: 22003021
 * Section: 3
 * Assignment: 3
 * Description: Computer class header file for CS202's HW3 assignment.
 */

#ifndef __COMPUTER_H__
#define __COMPUTER_H__

class Computer {
public:
    Computer();
    Computer(int id, int nextAvailableTime, bool availableStatus);
    Computer(const Computer& otherComputer);
    Computer& operator=(const Computer& otherComputer);

    void setId(const int& id);
    void setNextAvailableTime(const int& nextAvailableTime);
    void setAvailableStatus(const bool& availableStatus);

    int getId() const;
    int getNextAvailableTime() const;
    bool getAvailableStatus() const;

private:
    int id;
    int nextAvailableTime;
    bool availableStatus;
};

#endif // __COMPUTER_H__
