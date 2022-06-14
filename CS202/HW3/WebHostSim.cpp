/*
 * Title: Heaps, Priority Queues
 * Author: Berk Cakar
 * ID: 22003021
 * Section: 3
 * Assignment: 3
 * Description: WebHostSim class implementation file for CS202's HW3 assignment.
 */

#include "WebHostSim.h"
#include <fstream>
#include <iostream>
#include <sstream>

WebHostSim::WebHostSim() {
    this->fileName = "";
    this->avgWaitingTime = 0;
    this->requestsSize = 0;
    this->requestsArr = NULL;
}

WebHostSim::WebHostSim(std::string fileName, double avgWaitingTime) {
    this->fileName = fileName;
    this->avgWaitingTime = avgWaitingTime;
    this->requestsSize = 0;
    this->requestsArr = NULL;
}

WebHostSim::WebHostSim(const WebHostSim& otherWebHostSim)
    : fileName(otherWebHostSim.fileName), avgWaitingTime(otherWebHostSim.avgWaitingTime),
      requestsSize(otherWebHostSim.requestsSize), requestsArr(NULL), pq(otherWebHostSim.pq) {
    if (otherWebHostSim.requestsArr != NULL) {
        this->requestsArr = new PQueueItemType[otherWebHostSim.requestsSize];
        for (int i = 0; i < this->requestsSize; i++) {
            this->requestsArr[i] = otherWebHostSim.requestsArr[i];
        }
    }
}

WebHostSim& WebHostSim::operator=(const WebHostSim& otherWebHostSim) {
    if (this != &otherWebHostSim) {
        if (this->requestsArr != NULL) {
            delete[] this->requestsArr;
            this->requestsArr = NULL;
        }

        this->fileName = otherWebHostSim.fileName;
        this->avgWaitingTime = otherWebHostSim.avgWaitingTime;
        this->requestsSize = otherWebHostSim.requestsSize;
        this->pq = otherWebHostSim.pq;

        if (otherWebHostSim.requestsArr != NULL) {
            this->requestsArr = new PQueueItemType[otherWebHostSim.requestsSize];
            for (int i = 0; i < this->requestsSize; i++) {
                this->requestsArr[i] = otherWebHostSim.requestsArr[i];
            }
        }
    }

    return *this;
}

WebHostSim::~WebHostSim() {
    this->fileName = "";
    this->avgWaitingTime = 0;
    this->requestsSize = 0;
    if (this->requestsArr != NULL) {
        delete[] this->requestsArr;
        this->requestsArr = NULL;
    }
}

void WebHostSim::parseLog() {
    std::ifstream inputFile;
    inputFile.open(this->fileName.c_str(), std::ios_base::in);

    if (!inputFile) {
        std::cout << "Error opening file" << std::endl;
        inputFile.close();
        return;
    }

    inputFile >> this->requestsSize;

    if (this->requestsSize == 0) {
        inputFile.close();
        return;
    }

    int index = 0, id = 0, priority = 0, requestTime = 0, processTime = 0;

    this->requestsArr = new PQueueItemType[this->requestsSize];

    for (std::string line; getline(inputFile, line);) {
        inputFile >> id >> priority >> requestTime >> processTime;
        this->requestsArr[index] = PQueueItemType(id, priority, requestTime, processTime, false);
        index++;
    }

    inputFile.close();
}

int WebHostSim::bruteForceOptimalComputerCount() {
    int computerCount = 1;
    while (true) {
        double optimalTime = calculateWaitingTime(computerCount, NULL);
        if (optimalTime <= this->avgWaitingTime) {
            break;
        }

        computerCount++;
    }

    return computerCount;
}

void WebHostSim::simulate() {
    parseLog();

    if (this->requestsArr == NULL || this->requestsSize == 0) {
        std::cout << "No requests to process" << std::endl;
        return;
    }

    int computerCount = bruteForceOptimalComputerCount();

    std::cout << std::endl;
    std::cout << "Minimum number of computers required: " << computerCount << std::endl;
    std::cout << std::endl;
    std::cout << "Simulation with " << computerCount << " computers:" << std::endl;

    std::string* messages = new std::string[this->requestsSize];
    double avg = calculateWaitingTime(computerCount, messages);
    std::cout << std::endl;
    for (int i = 0; i < this->requestsSize; i++) {
        std::cout << messages[i];
    }

    std::cout << std::endl;
    std::cout << "Average waiting time: " << avg << " ms" << std::endl;

    if (messages != NULL) {
        delete[] messages;
        messages = NULL;
    }
}

double WebHostSim::calculateWaitingTime(const int computerCount, std::string* messages) {
    Computer* computersArr = new Computer[computerCount];

    for (int i = 0; i < computerCount; i++) {
        computersArr[i].setId(i);
    }

    int simulatedTime = 0, processedRequests = 0, waitingTime = 0;

    while (true) {
        for (int i = 0; i < this->requestsSize; i++) {
            if (simulatedTime >= this->requestsArr[i].getRequestTime() &&
                this->requestsArr[i].getIsQueued() == false) {
                this->requestsArr[i].setIsQueued(true);
                pq.pqInsert(this->requestsArr[i]);
            }
        }

        for (int i = 0; i < computerCount; i++) {
            if (computersArr[i].getNextAvailableTime() <= simulatedTime) {
                computersArr[i].setAvailableStatus(true);
            }

            if (pq.pqIsEmpty() == false) {
                if (computersArr[i].getAvailableStatus() == true) {
                    PQueueItemType request;
                    pq.pqDelete(request);

                    computersArr[i].setNextAvailableTime(simulatedTime + request.getProcessTime());
                    computersArr[i].setAvailableStatus(false);

                    if (messages != NULL) {
                        std::stringstream ss;
                        ss << "Computer " << computersArr[i].getId() << " takes request "
                           << request.getId() << " at ms " << simulatedTime
                           << " (wait: " << (simulatedTime - request.getRequestTime()) << " ms)"
                           << std::endl;
                        messages[processedRequests] = ss.str();
                    }

                    waitingTime = waitingTime + (simulatedTime - request.getRequestTime());
                    processedRequests++;
                }
            }
        }

        if (processedRequests >= this->requestsSize) {
            break;
        }

        simulatedTime++;
    }

    for (int i = 0; i < this->requestsSize; i++) {
        this->requestsArr[i].setIsQueued(false);
    }

    if (computersArr != NULL) {
        delete[] computersArr;
        computersArr = NULL;
    }

    return static_cast<double>(waitingTime) / this->requestsSize;
}
