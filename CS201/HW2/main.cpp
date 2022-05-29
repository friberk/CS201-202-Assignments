/**
 * Algorithm analysis main file for the CS201's HW2 assignment.
 * Author: Berk Cakar - 22003021
 */

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#define RANGE_MIN 0
#define RANGE_MAX 15000000

void randomizeArr(int* arr, const int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = RANGE_MIN + rand() / (RAND_MAX / (RANGE_MAX - RANGE_MIN + 1) + 1);
    }
}

int algorithm1(const int* arr1, const int* arr2, const int size1, const int size2) {
    int j = 0;
    for (int i = 0; i < size2; i++) {
        for (j = 0; j < size1; j++) {
            if (arr2[i] == arr1[j]) {
                break;
            }
        }

        if (j == size1) {
            return 0;
        }
    }

    return 1;
}

int algorithm2(const int* arr1, const int* arr2, const int size1, const int size2) {
    for (int i = 0; i < size2; i++) {
        if (std::binary_search(arr1, arr1 + size1, arr2[i]) == false) {
            return 0;
        }
    }

    return 1;
}

int algorithm3(const int* arr1, const int* arr2, const int size1, const int size2, int* freqTable,
               const int max) {
    for (int i = 0; i < size1; i++) {
        freqTable[arr1[i]] = freqTable[arr1[i]] + 1;
    }

    for (int i = 0; i < size2; i++) {
        if (freqTable[arr2[i]]) {
            freqTable[arr2[i]] = freqTable[arr2[i]] - 1;
        }

        else {
            return 0;
        }
    }

    return 1;
}

void timeTrackHelper(const int algorithmNo, const int mPower, const int nCoeff, const int* arr1,
                     const int* arr2, const int size1, const int size2, int* freqTable = NULL,
                     const int max = 0) {
    double elapsedTime;
    clock_t startTime = clock();

    if (algorithmNo == 1) {
        std::cout << "[Is a subset: " << algorithm1(arr1, arr2, size1, size2) << "]";
    } else if (algorithmNo == 2) {
        std::cout << "[Is a subset: " << algorithm2(arr1, arr2, size1, size2) << "]";
    } else if (algorithmNo == 3) {
        std::cout << "[Is a subset: " << algorithm3(arr1, arr2, size1, size2, freqTable, max)
                  << "]";
    } else {
        std::cout << "Invalid algorithm number" << std::endl;
        return;
    }

    elapsedTime = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;

    std::cout << " [Algorithm " << algorithmNo << "] Execution took " << std::setw(7) << elapsedTime
              << " milliseconds for m=10^" << mPower << " and n=" << nCoeff << "*10^6."
              << std::endl;
}

int main() {
    int* arr2;
    int* arr1;
    int* freqTable;
    int max = 0;

    for (int j = 1; j <= 2; j++) {
        for (int i = 1; i <= 15; i++) {
            const int size1 = i * 1000000;
            const int size2 = pow(10, j + 2);

            arr1 = new int[size1];
            randomizeArr(arr1, size1);
            std::sort(arr1, arr1 + size1);

            arr2 = new int[size2];
            randomizeArr(arr2, size2);

            max = *std::max_element(arr1, arr1 + size1);
            freqTable = new int[max + 1];
            std::fill(freqTable, freqTable + max + 1, 0);

            timeTrackHelper(1, j + 2, i, arr1, arr2, size1, size2);
            timeTrackHelper(2, j + 2, i, arr1, arr2, size1, size2);
            timeTrackHelper(3, j + 2, i, arr1, arr2, size1, size2, freqTable, max);

            delete[] arr1;
            delete[] arr2;
            delete[] freqTable;
        }

        std::cout << std::endl;
    }
}
