/*
 * Title: Heaps, Priority Queues
 * Author: Berk Cakar
 * ID: 22003021
 * Section: 3
 * Assignment: 3
 * Description: WebHostSim class header file for CS202's HW3 assignment.
 */

#ifndef __WEBHOSTSIM_H__
#define __WEBHOSTSIM_H__

#include "Computer.h"
#include "PriorityQueue.h"
#include <string>

class WebHostSim {
public:
    WebHostSim();
    WebHostSim(std::string fileName, double avgWaitingTime);
    WebHostSim(const WebHostSim& otherWebHostSim);
    WebHostSim& operator=(const WebHostSim& otherWebHostSim);
    ~WebHostSim();

    void simulate();

private:
    void parseLog();
    int bruteForceOptimalComputerCount();
    double calculateWaitingTime(const int computerCount, std::string* messages);

    std::string fileName;
    double avgWaitingTime;
    int requestsSize;
    PQueueItemType* requestsArr;
    PriorityQueue pq;
};

#endif // __WEBHOSTSIM_H__
