/*
* Title: Heaps, Priority Queues
* Author: Kutay Şenyiğit
* ID: 21902377
* Section: 1
* Assignment: 3
* Description: heap.h
*///
// Created by Kutay Şenyiğit on 17.04.2022.
//
#include "logln.h"
#ifndef CS202HW3_ARRAYMAXHEAP_H
#define CS202HW3_ARRAYMAXHEAP_H


class ArrayMaxHeap {
public:

    ArrayMaxHeap();
    ArrayMaxHeap(int size);
    ~ArrayMaxHeap();
    bool heapIsEmpty() const;
    void heapInsert(const logln& newItem) ;
    void heapDelete(logln& rootItem);
    void arrayInit(int size);

protected:
    void heapRebuild(int root);

private:
    logln* items;
    int size;
};

#endif //CS202HW3_ARRAYMAXHEAP_H
