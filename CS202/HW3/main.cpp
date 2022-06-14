/*
 * Title: Heaps, Priority Queues
 * Author: Berk Cakar
 * ID: 22003021
 * Section: 3
 * Assignment: 3
 * Description: Main file for CS202's HW3 assignment.
 */

#include "WebHostSim.h"
#include <iostream>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Usage: ./simulator <fileName> <avgWaitingTime>" << std::endl;
        return 1;
    } else {
        char** strtodPointer = NULL;
        std::string fileName(argv[1]);
        double avgWaitingTime = strtod(argv[2], strtodPointer);

        WebHostSim webHostSim(fileName, avgWaitingTime);
        webHostSim.simulate();

        return 0;
    }
}