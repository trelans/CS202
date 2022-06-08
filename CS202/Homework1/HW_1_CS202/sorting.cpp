//
// Created by Trelans on 3/6/2022.
//

#include "sorting.h"


using namespace std;

void insertionSort(int *arr, const int size, int &compCount, int &moveCount) {
    for (int unsorted = 1; unsorted < size; ++unsorted) {

        int nextItem = arr[unsorted];
        moveCount++;

        int loc = unsorted;

        for (; (loc > 0) && (arr[loc - 1] > nextItem); --loc)
        {
            arr[loc] = arr[loc - 1];
            compCount++;
            moveCount++;
        }
        if (loc >0) {
            compCount++;
        }


        arr[loc] = nextItem;
        moveCount++;
    }
}
void bubbleSort(int *arr, const int size, int &compCount, int &moveCount) {
    bool sorted = false;
    int pass = 1;
    while (!sorted && (pass < size))
    {
        sorted = true;
        for ( int index = 0; index < size - pass; index++)
        {

            int nextIndex = index + 1;
            if (arr[index] > arr[nextIndex])
            {

                moveCount += 3;
                std::swap(arr[index], arr[nextIndex]);
                sorted = false;
            }
            compCount++;
        }

        pass++;
    }

}
void mergeSort(int *arr, const int size, int &compCount, int &moveCount) {
    int last = size - 1;
    int first = 0;

    mergeSort2(arr,first,last, compCount , moveCount);


}

void merge(int theArray[], int first, int mid, int last, int &compCount, int &moveCount)
{

    int tempArray[60000];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;

    for (; (first1 <= last1) && (first2 <= last2); ++index)
    {
        compCount++;
        if (theArray[first1] < theArray[first2])
        {
            moveCount++;
            tempArray[index] = theArray[first1];
            ++first1;
        } else
        {
            moveCount++;
            tempArray[index] = theArray[first2];
            ++first2;
        }
    }

    for (; first1 <= last1; ++first1, ++index)
    {
        tempArray[index] = theArray[first1];
        moveCount++;
    }


    for (; first2 <= last2; ++first2, ++index)
    {
        tempArray[index] = theArray[first2];
        moveCount++;
    }

    for (index = first; index <= last; ++index)
    {
        theArray[index] = tempArray[index];
        moveCount++;
    }
}
void quickSort(int *arr, const int size, int &compCount, int &moveCount) {
    int first = 0;
    int last = size - 1;
    quickSort(arr, first , last , compCount,moveCount );

}
int partition (int* arr, int first, int last , int& compCount, int& moveCount) {
   int pivotIndex = first;
    int pivot = arr[pivotIndex];
    moveCount++;
    int lastS1 = first;
    int firstUnknown = first + 1;
    for (; firstUnknown <= last; firstUnknown++)
    {
        compCount++;
        if (arr[firstUnknown] < pivot)
        {
            lastS1++;
            swap(arr[firstUnknown], arr[lastS1]);
            moveCount += 3;
        }
    }
    swap(arr[first], arr[lastS1]);
    pivotIndex = lastS1;
    moveCount += 3;

    return  pivotIndex;
}

void sortFirstMiddleLast(int* arr, int first, int mid ,int last , int& compCount, int& moveCount) {

    if (arr[first] > arr[mid]) {
        swap(arr,first , mid);
    }
    if (arr[mid] > arr[last]) {
        swap(arr,first , mid);
    }
    if (arr[first] > arr[mid]) {
        swap(arr,first , mid);
    }

}
void quickSort(int *arr, int first, int last, int &compCount, int &moveCount )
{

    if (first < last) {


        int pivotIndex = partition(arr, first, last, compCount , moveCount);

        quickSort(arr, first, pivotIndex - 1 , compCount , moveCount);
        quickSort(arr, pivotIndex + 1, last , compCount, moveCount);
    }

}

void mergeSort2(int* arr, int first, int last, int &compCount, int &moveCount)
{
    if (first < last) {
       int  mid = (first + last) / 2;

        mergeSort2(arr , first ,mid, compCount , moveCount);
        mergeSort2(arr , mid+1 ,last ,compCount ,moveCount);
        merge(arr , first ,mid ,last , compCount ,moveCount);
    }
}

void displayArray(const int *arr, const int size) {
    cout << "Array: ";
    for (int i = 0; i < size; ++i) {
        if (i != size-1)
                cout << arr[i] << ", ";
        else {
            cout << arr[i];
        }

    }

}
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {
    for (int i = 0; i < size; ++i) {
        int curr = rand();

        arr1[i] = curr;
        arr2[i] = curr;
        arr3[i] = curr;
        arr4[i] = curr;
    }
}
void createAlmostSortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {

    for (int i = 0; i < size; ++i) {

        arr1[i] = i;
        arr2[i] = i;
        arr3[i] = i;
        arr4[i] = i;

    }

    for (int i = 0; i < (size/20); ++i) {

        int index1 = rand() % size;
        int index2 = rand() % size;

        swap(arr1,index1 ,index2);
        swap(arr2,index1 ,index2);
        swap(arr3,index1 ,index2);
        swap(arr4,index1 ,index2);
    }

}

void performanceAnalysis()
{
     int DIVISOR = 1000;
    const int sizes[] = {5000, 10000, 10000, 15000, 20000, 25000, 30000, 35000, 40000};
    const string line = "----------------------------------------------------------------------------------";

// Start random
    cout << line << endl;
    cout << "Random Arrays" << endl;
    cout << line << endl;


    cout << endl;
    cout << "Insertion  Sort" << endl;
    cout << endl;

    printf("%-20s\t%-20s\t%-20s\t%-20s\n", "Array Size", "TimeElapsed(ms)", "compCount", "moveCount");


    for (int i = 0; 9 > i; i++) {
        int currentSize = sizes[i];

        int *arr1 = new int[currentSize];
        int *arr2 = new int[currentSize];
        int *arr3 = new int[currentSize];
        int *arr4 = new int[currentSize];

        int m1 = 0;
        int c1 = 0;


        createRandomArrays(arr1, arr2, arr3, arr4, currentSize);

        double timeElapsed = 0.0;
        clock_t startTime = clock();

            insertionSort(arr1, sizes[i], c1, m1);

        timeElapsed = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        timeElapsed /= 3;
        printf("%-20d\t%-20.10f\t%-20d\t%-20d\n", currentSize, timeElapsed, c1, m1);

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
    }
    cout << line << endl;


    cout << endl;
    cout << "Bubble  Sort" << endl;
    cout << endl;

    printf("%-20s\t%-20s\t%-20s\t%-20s\n", "Array Size", "TimeElapsed(ms)", "compCount", "moveCount");


    for (int i = 0; i < 9 ; i++)
    {
        int currentSize = sizes[i];
        int *arr1 = new int[currentSize];
        int *arr2 = new int[currentSize];
        int *arr3 = new int[currentSize];
        int *arr4 = new int[currentSize];

        int m2 = 0;
        int c2 = 0;
        double timeElapsed = 0.0;

        createRandomArrays(arr1, arr2, arr3, arr4, currentSize);

        clock_t startTime = clock();

        bubbleSort(arr2, currentSize, c2, m2);

        timeElapsed = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        timeElapsed /= DIVISOR;
        printf("%-20d\t%-20.10f\t%-20d\t%-20d\n", sizes[i], timeElapsed, c2, m2);

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
    }

    cout << line << endl;



    cout << endl;
    cout << "Merge  Sort" << endl;
    cout << endl;

    printf("%-20s\t%-20s\t%-20s\t%-20s\n", "Array Size", "TimeElapsed(ms)", "compCount", "moveCount");


    for (int i = 0; i < 9; i++)
    {
        int currentSize = sizes[i];

        int *arr1 = new int[currentSize];
        int *arr2 = new int[currentSize];
        int *arr3 = new int[currentSize];
        int *arr4 = new int[currentSize];

        double timeElapsed = 0.0;

        int m3 = 0;
        int c3= 0;

        clock_t startTime = clock();


            createRandomArrays(arr1, arr2, arr3, arr4, currentSize);
            mergeSort(arr3, currentSize , c3, m3);

        timeElapsed = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        timeElapsed /= DIVISOR;

        printf("%-20d\t%-20.10f\t%-20d\t%-20d\n", sizes[i], timeElapsed, c3, m3);


        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
    }
    cout << line << endl;



    cout << endl;
    cout << "Quick  Sort" << endl;
    cout << endl;

    printf("%-20s\t%-20s\t%-20s\t%-20s\n", "Array Size", "TimeElapsed(ms)", "compCount", "moveCount");


    for (int i = 0; i < 9; i++)
    {
        int currentSize = sizes[i];

        int *arr1 = new int[currentSize];
        int *arr2 = new int[currentSize];
        int *arr3 = new int[currentSize];
        int *arr4 = new int[currentSize];

        double timeElapsed = 0.0;

        int c4= 0;
        int m4 = 0;


        clock_t startTime = clock();


        createRandomArrays(arr1, arr2, arr3, arr4, currentSize);
        quickSort(arr4, currentSize , c4, m4);

        timeElapsed = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        timeElapsed /= DIVISOR;

        printf("%-20d\t%-20.10f\t%-20d\t%-20d\n", sizes[i], timeElapsed, c4, m4);


        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
    }
    cout << line << endl;

// end of random



// Start almost sorted
    cout << line << endl;
    cout << "Almost  Sorted" << endl;
    cout << line << endl;


    cout << endl;
    cout << "Insertion  Sort" << endl;
    cout << endl;

    printf("%-20s\t%-20s\t%-20s\t%-20s\n", "Array Size", "TimeElapsed(ms)", "compCount", "moveCount");


    for (int i = 0; 9 > i; i++) {
        int currentSize = sizes[i];

        int *arr1 = new int[currentSize];
        int *arr2 = new int[currentSize];
        int *arr3 = new int[currentSize];
        int *arr4 = new int[currentSize];

        int m1 = 0;
        int c1 = 0;


        createAlmostSortedArrays(arr1, arr2, arr3, arr4, currentSize);

        double timeElapsed = 0.0;
        clock_t startTime = clock();

        insertionSort(arr1, sizes[i], c1, m1);

        timeElapsed = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        timeElapsed /= 3;
        printf("%-20d\t%-20.10f\t%-20d\t%-20d\n", currentSize, timeElapsed, c1, m1);

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
    }
    cout << line << endl;


    cout << endl;
    cout << "Bubble  Sort" << endl;
    cout << endl;

    printf("%-20s\t%-20s\t%-20s\t%-20s\n", "Array Size", "TimeElapsed(ms)", "compCount", "moveCount");


    for (int i = 0; i < 9 ; i++)
    {
        int currentSize = sizes[i];
        int *arr1 = new int[currentSize];
        int *arr2 = new int[currentSize];
        int *arr3 = new int[currentSize];
        int *arr4 = new int[currentSize];

        int m2 = 0;
        int c2 = 0;
        double timeElapsed = 0.0;

        createAlmostSortedArrays(arr1, arr2, arr3, arr4, currentSize);

        clock_t startTime = clock();

        bubbleSort(arr2, currentSize, c2, m2);

        timeElapsed = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        timeElapsed /= DIVISOR;
        printf("%-20d\t%-20.10f\t%-20d\t%-20d\n", sizes[i], timeElapsed, c2, m2);

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
    }

    cout << line << endl;



    cout << endl;
    cout << "Merge  Sort" << endl;
    cout << endl;

    printf("%-20s\t%-20s\t%-20s\t%-20s\n", "Array Size", "TimeElapsed(ms)", "compCount", "moveCount");


    for (int i = 0; i < 9; i++)
    {
        int currentSize = sizes[i];

        int *arr1 = new int[currentSize];
        int *arr2 = new int[currentSize];
        int *arr3 = new int[currentSize];
        int *arr4 = new int[currentSize];

        double timeElapsed = 0.0;

        int m3 = 0;
        int c3= 0;

        clock_t startTime = clock();


        createAlmostSortedArrays(arr1, arr2, arr3, arr4, currentSize);
        mergeSort(arr3, currentSize , c3, m3);

        timeElapsed = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        timeElapsed /= DIVISOR;

        printf("%-20d\t%-20.10f\t%-20d\t%-20d\n", sizes[i], timeElapsed, c3, m3);


        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
    }
    cout << line << endl;



    cout << endl;
    cout << "Quick  Sort" << endl;
    cout << endl;

    printf("%-20s\t%-20s\t%-20s\t%-20s\n", "Array Size", "TimeElapsed(ms)", "compCount", "moveCount");


    for (int i = 0; i < 9; i++)
    {
        int currentSize = sizes[i];

        int *arr1 = new int[currentSize];
        int *arr2 = new int[currentSize];
        int *arr3 = new int[currentSize];
        int *arr4 = new int[currentSize];

        double timeElapsed = 0.0;

        int c4= 0;
        int m4 = 0;


        clock_t startTime = clock();


        createAlmostSortedArrays(arr1, arr2, arr3, arr4, currentSize);
        quickSort(arr4, currentSize , c4, m4);

        timeElapsed = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        timeElapsed /= DIVISOR;

        printf("%-20d\t%-20.10f\t%-20d\t%-20d\n", sizes[i], timeElapsed, c4, m4);


        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
    }
    cout << line << endl;

// end of almost sorted

// Start almost unsorted
    cout << line << endl;
    cout << "Almost  Unsorted" << endl;
    cout << line << endl;


    cout << endl;
    cout << "Insertion  Sort" << endl;
    cout << endl;

    printf("%-20s\t%-20s\t%-20s\t%-20s\n", "Array Size", "TimeElapsed(ms)", "compCount", "moveCount");


    for (int i = 0; 9 > i; i++) {
        int currentSize = sizes[i];

        int *arr1 = new int[currentSize];
        int *arr2 = new int[currentSize];
        int *arr3 = new int[currentSize];
        int *arr4 = new int[currentSize];

        int m1 = 0;
        int c1 = 0;


        createAlmostUnsortedArrays(arr1, arr2, arr3, arr4, currentSize);

        double timeElapsed = 0.0;
        clock_t startTime = clock();

        insertionSort(arr1, sizes[i], c1, m1);

        timeElapsed = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        timeElapsed /= 3;
        printf("%-20d\t%-20.10f\t%-20d\t%-20d\n", currentSize, timeElapsed, c1, m1);

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
    }
    cout << line << endl;


    cout << endl;
    cout << "Bubble  Sort" << endl;
    cout << endl;

    printf("%-20s\t%-20s\t%-20s\t%-20s\n", "Array Size", "TimeElapsed(ms)", "compCount", "moveCount");


    for (int i = 0; i < 9 ; i++)
    {
        int currentSize = sizes[i];
        int *arr1 = new int[currentSize];
        int *arr2 = new int[currentSize];
        int *arr3 = new int[currentSize];
        int *arr4 = new int[currentSize];

        int m2 = 0;
        int c2 = 0;
        double timeElapsed = 0.0;

        createAlmostUnsortedArrays(arr1, arr2, arr3, arr4, currentSize);

        clock_t startTime = clock();

        bubbleSort(arr2, currentSize, c2, m2);

        timeElapsed = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        timeElapsed /= DIVISOR;
        printf("%-20d\t%-20.10f\t%-20d\t%-20d\n", sizes[i], timeElapsed, c2, m2);

        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
    }

    cout << line << endl;



    cout << endl;
    cout << "Merge  Sort" << endl;
    cout << endl;

    printf("%-20s\t%-20s\t%-20s\t%-20s\n", "Array Size", "TimeElapsed(ms)", "compCount", "moveCount");


    for (int i = 0; i < 9; i++)
    {
        int currentSize = sizes[i];

        int *arr1 = new int[currentSize];
        int *arr2 = new int[currentSize];
        int *arr3 = new int[currentSize];
        int *arr4 = new int[currentSize];

        double timeElapsed = 0.0;

        int m3 = 0;
        int c3= 0;

        clock_t startTime = clock();


        createAlmostUnsortedArrays(arr1, arr2, arr3, arr4, currentSize);
        mergeSort(arr3, currentSize , c3, m3);

        timeElapsed = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        timeElapsed /= DIVISOR;

        printf("%-20d\t%-20.10f\t%-20d\t%-20d\n", sizes[i], timeElapsed, c3, m3);


        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
    }
    cout << line << endl;



    cout << endl;
    cout << "Quick  Sort" << endl;
    cout << endl;

    printf("%-20s\t%-20s\t%-20s\t%-20s\n", "Array Size", "TimeElapsed(ms)", "compCount", "moveCount");


    for (int i = 0; i < 9; i++)
    {
        int currentSize = sizes[i];

        int *arr1 = new int[currentSize];
        int *arr2 = new int[currentSize];
        int *arr3 = new int[currentSize];
        int *arr4 = new int[currentSize];

        double timeElapsed = 0.0;

        int c4= 0;
        int m4 = 0;


        clock_t startTime = clock();


        createAlmostUnsortedArrays(arr1, arr2, arr3, arr4, currentSize);
        quickSort(arr4, currentSize , c4, m4);

        timeElapsed = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
        timeElapsed /= DIVISOR;

        printf("%-20d\t%-20.10f\t%-20d\t%-20d\n", sizes[i], timeElapsed, c4, m4);


        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
    }
    cout << line << endl;

// end of almost unsorted

}


void createAlmostUnsortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {

    for (int i = size-1; i <=0; ++i) {

        arr1[i] = i;
        arr2[i] = i;
        arr3[i] = i;
        arr4[i] = i;

    }

    for (int i = 0; i < (size/20); ++i) {

        int index1 = rand() % size;
        int index2 = rand() % size;

        swap(arr1,index1 ,index2);
        swap(arr2,index1 ,index2);
        swap(arr3,index1 ,index2);
        swap(arr4,index1 ,index2);
    }

}

void swap(int *&arr, const int index1, const int index2) {

    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}
