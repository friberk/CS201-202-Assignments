/*
 * Title: Trees
 * Author: Berk Çakar
 * ID: 22003021
 * Section: 3
 * Assignment: 2
 * Description: Implementation file for the binary search tree analyze program.
 */

#include "analyze.h"
#include "BinarySearchTree.h"
#include <cstdlib>
#include <iostream>
#include <time.h>

void analyzeBST() {
    int* arr = new int[10000];

    srand(time(0));
    for (int i = 0; i < 10000; i++) {
        arr[i] = rand();
    }

    BinarySearchTree T;

    std::cout << "Random BST size vs. height (Insertion)" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    for (int i = 0; i < 10000; i++) {
        T.add(arr[i]);

        if ((i + 1) % 100 == 0) {
            std::cout << T.getNumberOfNodes() << " " << T.getHeight() << std::endl;
        }
    }

    std::cout << std::endl;

    // Shuffle the array
    srand(time(0));
    for (int i = 9999; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    std::cout << "Random BST size vs. height (Deletion)" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    for (int i = 0; i < 10000; i++) {
        T.remove(arr[i]);

        if ((i + 1) % 100 == 0) {
            std::cout << T.getNumberOfNodes() << " " << T.getHeight() << std::endl;
        }
    }

    delete[] arr;
}
