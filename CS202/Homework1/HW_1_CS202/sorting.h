//
// Created by Trelans on 3/6/2022.
//

#ifndef CS202HW1_SORTING_H
#define CS202HW1_SORTING_H

#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <cstring>

void insertionSort(int *arr, const int size, int &compCount, int &moveCount);
void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSort2(int* arr, int first, int last, int &compCount, int &moveCount);
void merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount);
void quickSort(int *arr, const int size, int &compCount, int &moveCount);
void quickSort(int *arr, int first, int last, int &compCount, int &moveCount);
void sortFirstMiddleLast(int* arr, int first, int mid ,int last , int& compCount, int& moveCount);
int partition (int* arr, int first, int last , int& compCount, int& moveCount);
void displayArray(const int *arr, const int size);
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAlmostSortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAlmostUnsortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void performanceAnalysis();
void swap(int *&arr, const int index1, const int index2);




#endif //CS202HW1_SORTING_H
