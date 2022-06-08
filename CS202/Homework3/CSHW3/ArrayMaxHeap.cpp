/*
* Title: Heaps, Priority Queues
* Author: Kutay Şenyiğit
* ID: 21902377
* Section: 1
* Assignment: 3
* Description: heap
*///
// Created by Kutay Şenyiğit on 17.04.2022.
//

#include "ArrayMaxHeap.h"

ArrayMaxHeap::ArrayMaxHeap() : size(0) {

}
ArrayMaxHeap::~ArrayMaxHeap() {
   delete [] items;
}
bool ArrayMaxHeap::heapIsEmpty() const {
    return (size == 0);
}
void ArrayMaxHeap::heapInsert(const logln &newItem)  {

   // if (size >= MAX_HEAP)
        //throw HeapException("HeapException: Heap full");

    // Place the new item at the end of the heap
    items[size] = newItem;

    // Trickle new item up to its proper position
    int place = size;
    int parent = (place - 1)/2;
    while ( (place > 0) && (items[place].getKey() > items[parent].getKey() ||
    items[place].getKey() == items[parent].getKey() &&
    items[place].getRequestTime() < items[parent].getRequestTime()  ) ) {
        logln temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1)/2;
    }
    ++size;
}


void ArrayMaxHeap::heapDelete(logln&rootItem)  {
    if (heapIsEmpty()){

        //throwHeapException("HeapException: Heap empty");
    }
    else {
        rootItem = items[0];
        items[0] = items[--size];
        heapRebuild(0);
    }
}
void ArrayMaxHeap::heapRebuild(int root) {
    int child = 2 * root + 1;    // index of root's left child, if any
    if (child < size) {
        // root is not a leaf so that it has a left child
        int rightChild = child + 1;    // index of a right child, if any
        // If root has right child, find larger child
        if ((rightChild < size) &&
            (items[rightChild].getKey() > items[child].getKey() ||
            ( items[rightChild].getKey() == items[child].getKey() &&
            items[rightChild].getRequestTime() < items[child].getRequestTime() ) ))
            child = rightChild;    // index of larger child

        // If root’s item is smaller than larger child, swap values
        if (items[root].getKey() < items[child].getKey() ||
        (items[root].getKey() == items[child].getKey() &&
        items[root].getRequestTime() > items[child].getRequestTime())  ) {
            logln temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            // transform the new subtree into a heap
            heapRebuild(child);
        }
    }
}

void ArrayMaxHeap::arrayInit(int size) {
    items = new logln[size];
}