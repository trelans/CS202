//
// Created by Kutay Şenyiğit on 17.04.2022.
//
/*
* Title: Heaps, Priority Queues
* Author: Kutay Şenyiğit
* ID: 21902377
* Section: 1
* Assignment: 3
* Description: PriorityQueue.h
*/
#include "ArrayMaxHeap.h"
#ifndef CS202HW3_PRIORITYQUEUE_H
#define CS202HW3_PRIORITYQUEUE_H


class PriorityQueue {
public:

    PriorityQueue(int size ) ;
    ~PriorityQueue();
    bool pqIsEmpty() const;
    void pqInsert(const logln& newItem) ;
    void pqDelete(logln& priorityItem) ;

private:

    ArrayMaxHeap h;
    int size;
};


#endif //CS202HW3_PRIORITYQUEUE_H
