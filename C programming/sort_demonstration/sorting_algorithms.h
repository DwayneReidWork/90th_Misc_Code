#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H
// DECLARATIONS
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

#endif