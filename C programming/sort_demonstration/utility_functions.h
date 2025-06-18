#ifndef UTILITY_FUNCTIONS_H
#define UTILITY_FUNCTIONS_H

void mergeSortWrapper(int arr[], int n);
void quickSortWrapper(int arr[], int n);
int* generateRandomArray(const int size);
double measureExecutionTime(int *arr, int size, void (*operation)(int *, int));
void printWrapper(const char* type_of_sort, long double duration);

#endif