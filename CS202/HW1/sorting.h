/*
 * Title: Sorting and Algorithm Efficiency
 * Author: Berk Çakar
 * ID: 22003021
 * Section: 3
 * Assignment: 1
 * Description: This header file contains the prototypes for the sorting algorithms
 *              as well as for some auxiliary functions.
 */

void insertionSort(int* arr, const int size, int& compCount, int& moveCount);

void bubbleSort(int* arr, const int size, int& compCount, int& moveCount);

void mergeSort(int* arr, const int size, int& compCount, int& moveCount);
void mergeSort(int* arr, int first, int last, int& compCount, int& moveCount);
void merge(int* arr, int first, int mid, int last, int& compCount, int& moveCount);

void quickSort(int* arr, const int size, int& compCount, int& moveCount);
void quickSort(int* arr, int first, int last, int& compCount, int& moveCount);
void partition(int* arr, int first, int last, int& pivotIndex, int& compCount, int& moveCount);

// Helper functions
void displayArray(const int *arr, const int size);

void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAlmostSortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAlmostUnsortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);

void performanceAnalysis();

void swap(int& x, int& y);
