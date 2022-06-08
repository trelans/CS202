#include <iostream>
#include "sorting.h"

using namespace std;
int main() {

    int comparisons = 0;
    int moves = 0;
    int size = 16;

    int* arr= new int [16];

    arr[0] = 9;
    arr[1] = 6;
    arr[2] = 7;
    arr[3] = 16;
    arr[4] = 18;
    arr[5] = 5;
    arr[6] = 2;
    arr[7] = 12;
    arr[8] = 20;
    arr[9] = 1;
    arr[10] = 16;
    arr[11] = 17;
    arr[12] = 4;
    arr[13] = 11;
    arr[14] = 13;
    arr[15] = 8;

    cout << "Insertion Sort " << endl;
    insertionSort(arr , size, comparisons ,moves);
    displayArray(arr,16);

    cout << endl;
    cout << "Key Comparison: " << comparisons << endl;
    cout << "Move Count: " << moves;



    comparisons = 0 ;
    moves = 0;

    cout << endl << endl;

    arr[0] = 9;
    arr[1] = 6;
    arr[2] = 7;
    arr[3] = 16;
    arr[4] = 18;
    arr[5] = 5;
    arr[6] = 2;
    arr[7] = 12;
    arr[8] = 20;
    arr[9] = 1;
    arr[10] = 16;
    arr[11] = 17;
    arr[12] = 4;
    arr[13] = 11;
    arr[14] = 13;
    arr[15] = 8;

    cout << "Bubble Sort " << endl;
    bubbleSort(arr , size, comparisons ,moves);
    displayArray(arr,16);

    cout << endl ;
    cout << "Key Comparison: " << comparisons << endl;
    cout << "Move Count: " << moves;



    comparisons = 0 ;
    moves = 0;

    cout << endl << endl;


    arr[0] = 9;
    arr[1] = 6;
    arr[2] = 7;
    arr[3] = 16;
    arr[4] = 18;
    arr[5] = 5;
    arr[6] = 2;
    arr[7] = 12;
    arr[8] = 20;
    arr[9] = 1;
    arr[10] = 16;
    arr[11] = 17;
    arr[12] = 4;
    arr[13] = 11;
    arr[14] = 13;
    arr[15] = 8;


    cout << "Merge Sort " << endl;
    mergeSort(arr , size, comparisons ,moves);
    displayArray(arr,16);

    cout << endl;
    cout << "Key Comparison: " << comparisons << endl;
    cout << "Move Count: " << moves;



    comparisons = 0 ;
    moves = 0;

    cout << endl << endl;


    arr[0] = 9;
    arr[1] = 6;
    arr[2] = 7;
    arr[3] = 16;
    arr[4] = 18;
    arr[5] = 5;
    arr[6] = 2;
    arr[7] = 12;
    arr[8] = 20;
    arr[9] = 1;
    arr[10] = 16;
    arr[11] = 17;
    arr[12] = 4;
    arr[13] = 11;
    arr[14] = 13;
    arr[15] = 8;

    cout << "Quick Sort " << endl;
    quickSort(arr , size, comparisons ,moves);
    displayArray(arr,16);

    cout << endl;
    cout << "Key Comparison: " << comparisons << endl;
    cout << "Move Count: " << moves;

    delete[] arr;

    comparisons = 0 ;
    moves = 0;

    cout << endl;
   // performanceAnalysis();

    return 0;



}
