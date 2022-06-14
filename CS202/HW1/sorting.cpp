/*
 * Title: Sorting and Algorithm Efficiency
 * Author: Berk Çakar
 * ID: 22003021
 * Section: 3
 * Assignment: 1
 * Description: This C++ file contains the implementation for the sorting algorithms
 *              as well as for some auxiliary functions.
 */

#include "sorting.h"
#include <climits>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>

void insertionSort(int* arr, const int size, int& compCount, int& moveCount) {
    for (int unsorted = 1; unsorted < size; unsorted++) {
        int nextItem = arr[unsorted];
        moveCount++;
        int loc = unsorted;

        while (++compCount && arr[loc - 1] > nextItem) {
            arr[loc] = arr[loc - 1];
            moveCount++;
            loc--;

            if (loc == 0) { // Do not count loc comparisons as a key comparison
                break;
            }
        }

        arr[loc] = nextItem;
        moveCount++;
    }
}

void bubbleSort(int* arr, const int size, int& compCount, int& moveCount) {
    bool sorted = false;
    for (int pass = 1; pass < size && !sorted; pass++) {
        sorted = true;
        for (int index = 0; index < size - pass; index++) {
            if (arr[index] > arr[index + 1]) {
                swap(arr[index], arr[index + 1]);
                moveCount = moveCount + 3; // Each swap has 3 moves
                sorted = false;
            }
            compCount++;
        }
    }
}

void mergeSort(int* arr, const int size, int& compCount, int& moveCount) {
    mergeSort(arr, 0, size - 1, compCount, moveCount);
}

void mergeSort(int* arr, int first, int last, int& compCount, int& moveCount) {
    if (first < last) {
        int mid = (first + last) / 2;

        mergeSort(arr, first, mid, compCount, moveCount);
        mergeSort(arr, mid + 1, last, compCount, moveCount);
        merge(arr, first, mid, last, compCount, moveCount);
    }
}

void merge(int* arr, int first, int mid, int last, int& compCount, int& moveCount) {
    int tempArray[last + 1];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;

    for (; (first1 <= last1) && (first2 <= last2); index++) {
        if (arr[first1] < arr[first2]) {
            tempArray[index] = arr[first1];
            first1++;
        } else {
            tempArray[index] = arr[first2];
            first2++;
        }
        compCount++;
        moveCount++;
    }

    for (; first1 <= last1; first1++, index++) {
        tempArray[index] = arr[first1];
        moveCount++;
    }

    for (; first2 <= last2; first2++, index++) {
        tempArray[index] = arr[first2];
        moveCount++;
    }

    for (index = first; index <= last; index++) {
        arr[index] = tempArray[index];
        moveCount++;
    }
}

void quickSort(int* arr, const int size, int& compCount, int& moveCount) {
    quickSort(arr, 0, size - 1, compCount, moveCount);
}

void quickSort(int* arr, int first, int last, int& compCount, int& moveCount) {
    int pivotIndex;

    if (first < last) {
        partition(arr, first, last, pivotIndex, compCount, moveCount);
        quickSort(arr, first, pivotIndex - 1, compCount, moveCount);
        quickSort(arr, pivotIndex + 1, last, compCount, moveCount);
    }
}

void partition(int* arr, int first, int last, int& pivotIndex, int& compCount, int& moveCount) {
    int pivot = arr[first]; // Take the first element of the array as pivot
    moveCount++;

    int lastS1 = first;
    int firstUnknown = first + 1;

    for (; firstUnknown <= last; firstUnknown++) {
        if (arr[firstUnknown] < pivot) {
            lastS1++;
            swap(arr[firstUnknown], arr[lastS1]);
            moveCount = moveCount + 3; // Each swap has 3 moves
        }
        compCount++;
    }

    swap(arr[first], arr[lastS1]);
    moveCount = moveCount + 3; // Each swap has 3 moves
    pivotIndex = lastS1;
}

void displayArray(const int* arr, const int size) {
    if (arr == NULL || size == 0) {
        std::cout << "Empty array" << std::endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void createRandomArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size) {
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];

    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr1[i] = arr2[i] = arr3[i] = arr4[i] = (rand() % size) + 1;
    }
}

void createAlmostSortedArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size) {
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];

    // Create the sorted array first
    for (int i = 0; i < size; i++) {
        arr1[i] = arr2[i] = arr3[i] = arr4[i] = i;
    }

    // Perturb the sorted array
    srand(time(0));
    for (int i = 0; i < (size / 20); i++) {
        int randIdx1 = (rand() % size);
        int randIdx2 = (rand() % size);

        swap(arr1[randIdx1], arr1[randIdx2]);
        swap(arr2[randIdx1], arr2[randIdx2]);
        swap(arr3[randIdx1], arr3[randIdx2]);
        swap(arr4[randIdx1], arr4[randIdx2]);
    }
}

void createAlmostUnsortedArrays(int*& arr1, int*& arr2, int*& arr3, int*& arr4, const int size) {
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];

    // Create the unsorted array first
    for (int i = size - 1; i >= 0; i--) {
        arr1[size - 1 - i] = arr2[size - 1 - i] = arr3[size - 1 - i] = arr4[size - 1 - i] = i;
    }

    // Perturb the unsorted array
    srand(time(0));
    for (int i = 0; i < (size / 20); i++) {
        int randIdx1 = (rand() % size);
        int randIdx2 = (rand() % size);

        swap(arr1[randIdx1], arr1[randIdx2]);
        swap(arr2[randIdx1], arr2[randIdx2]);
        swap(arr3[randIdx1], arr3[randIdx2]);
        swap(arr4[randIdx1], arr4[randIdx2]);
    }
}

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void performanceAnalysis() {
    int *arr1_5k  = NULL, *arr2_5k  = NULL, *arr3_5k  = NULL, *arr4_5k  = NULL,
        *arr1_10k = NULL, *arr2_10k = NULL, *arr3_10k = NULL, *arr4_10k = NULL,
        *arr1_15k = NULL, *arr2_15k = NULL, *arr3_15k = NULL, *arr4_15k = NULL,
        *arr1_20k = NULL, *arr2_20k = NULL, *arr3_20k = NULL, *arr4_20k = NULL,
        *arr1_25k = NULL, *arr2_25k = NULL, *arr3_25k = NULL, *arr4_25k = NULL,
        *arr1_30k = NULL, *arr2_30k = NULL, *arr3_30k = NULL, *arr4_30k = NULL,
        *arr1_35k = NULL, *arr2_35k = NULL, *arr3_35k = NULL, *arr4_35k = NULL,
        *arr1_40k = NULL, *arr2_40k = NULL, *arr3_40k = NULL, *arr4_40k = NULL;

    int* arrays[][4] = {{arr1_5k,  arr2_5k,  arr3_5k,  arr4_5k},
                        {arr1_10k, arr2_10k, arr3_10k, arr4_10k},
                        {arr1_15k, arr2_15k, arr3_15k, arr4_15k},
                        {arr1_20k, arr2_20k, arr3_20k, arr4_20k},
                        {arr1_25k, arr2_25k, arr3_25k, arr4_25k},
                        {arr1_30k, arr2_30k, arr3_30k, arr4_30k},
                        {arr1_35k, arr2_35k, arr3_35k, arr4_35k},
                        {arr1_40k, arr2_40k, arr3_40k, arr4_40k},
                        };

    std::string algorithmNames[] = {"Insertion Sort", "Bubble Sort", "Merge Sort", "Quick Sort"};
    std::string scenarioDesc[]   = {"Using arrays filled with randomly generated integers:",
                                    "Using almost sorted arrays:",
                                    "Using almost unsorted arrays:"};


    for (int s = 0; s < 3; s++) {
        for (int i = 0; i < 8; i++) {
            switch (s) {
                case 0: createRandomArrays(arrays[i][0], arrays[i][1], arrays[i][2], arrays[i][3], (i + 1) * 5000 ); break;
                case 1: createAlmostSortedArrays(arrays[i][0], arrays[i][1], arrays[i][2], arrays[i][3], (i + 1) * 5000 ); break;
                case 2: createAlmostUnsortedArrays(arrays[i][0], arrays[i][1], arrays[i][2], arrays[i][3], (i + 1) * 5000 ); break;
            }
        }

        std::cout << scenarioDesc[s] << std::endl;
        for (int a = 0; a < 4; a++) {
            std::cout << "-------------------------------------------------------" << std::endl;
            std::cout << "Analysis of " << algorithmNames[a] << std::endl;
            std::cout << "Array Size" << std::setw(15) << "Elapsed Time" << std::setw(15) << "compCount" << std::setw(15) << "moveCount" << std::endl;
            for (int i = 0; i < 8; i++) {
                int arraySize = (i + 1) * 5000;
                double elapsedTime = 0;
                int compCount = 0, moveCount = 0;

                clock_t startTime = clock();

                switch (a) {
                    case 0: insertionSort(arrays[i][a], arraySize, compCount, moveCount); break;
                    case 1: bubbleSort(arrays[i][a], arraySize, compCount, moveCount); break;
                    case 2: mergeSort(arrays[i][a], arraySize, compCount, moveCount); break;
                    case 3: quickSort(arrays[i][a], arraySize, compCount, moveCount); break;
                }

                elapsedTime = 1000 * static_cast<double>(clock() - startTime) / CLOCKS_PER_SEC;

                if (moveCount < 0) {
                    moveCount = INT_MAX; // In case of getting an overflow
                }                        // That usually happens in bubble sort after size > 35000
                std::cout << arraySize << std::setw(15) << elapsedTime << " ms" << std::setw(17) << compCount << std::setw(15) << moveCount << std::endl;
            }
        }

        std::cout << std::endl;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 4; j++) {
                delete[] arrays[i][j];
            }
        }
    }
}
