/*
 * Title: Sorting and Algorithm Efficiency
 * Author: Berk Çakar
 * ID: 22003021
 * Section: 3
 * Assignment: 1
 * Description: This C++ file contains the main function which executes
 *              the sorting algorithms and performance analysis.
 */

#include "sorting.h"
#include <cstring>
#include <iostream>

int main() {
    std::cout << "QUESTION 2 - C" << std::endl;
    std::cout << std::endl;

    int origArr[] = {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};
    const int size = 16;
    int arr[size];
    int compCount = 0, moveCount = 0;

    memcpy(arr, origArr, sizeof(origArr));

    std::cout << "Array before sorting: ";
    displayArray(arr, size);

    std::cout << std::endl;

    std::cout << "Sorting the array using insertion sort" << std::endl;
    insertionSort(arr, size, compCount, moveCount);
    std::cout << "Array after insertion sort: ";
    displayArray(arr, size);
    std::cout << "Number of key comparisons: " << compCount << std::endl;
    std::cout << "Number of data moves: " << moveCount << std::endl;

    // Reset the array and counters
    memcpy(arr, origArr, sizeof(origArr));
    compCount = 0, moveCount = 0;

    std::cout << std::endl;

    std::cout << "Sorting the array using bubble sort" << std::endl;
    bubbleSort(arr, size, compCount, moveCount);
    std::cout << "Array after bubble sort: ";
    displayArray(arr, size);
    std::cout << "Number of key comparisons: " << compCount << std::endl;
    std::cout << "Number of data moves: " << moveCount << std::endl;

    // Reset the array and counters
    memcpy(arr, origArr, sizeof(origArr));
    compCount = 0, moveCount = 0;

    std::cout << std::endl;

    std::cout << "Sorting the array using merge sort" << std::endl;
    mergeSort(arr, size, compCount, moveCount);
    std::cout << "Array after merge sort: ";
    displayArray(arr, size);
    std::cout << "Number of key comparisons: " << compCount << std::endl;
    std::cout << "Number of data moves: " << moveCount << std::endl;

    // Reset the array and counters
    memcpy(arr, origArr, sizeof(origArr));
    compCount = 0, moveCount = 0;

    std::cout << std::endl;

    std::cout << "Sorting the array using quick sort" << std::endl;
    quickSort(arr, size, compCount, moveCount);
    std::cout << "Array after quick sort: ";
    displayArray(arr, size);
    std::cout << "Number of key comparisons: " << compCount << std::endl;
    std::cout << "Number of data moves: " << moveCount << std::endl;

    std::cout << std::endl;

    std::cout << "QUESTION 2 - D" << std::endl;
    std::cout << std::endl;
    performanceAnalysis();
}
