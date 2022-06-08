//
// Created by Kutay Şenyiğit on 17.04.2022.
//
/*
* Title: Heaps, Priority Queues
* Author: Kutay Şenyiğit
* ID: 21902377
* Section: 1
* Assignment: 3
* Description: priorityqueue.h
*/
#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int size) {
    this->size = size;
    h.arrayInit(size);
}
PriorityQueue::~PriorityQueue() {

}
bool PriorityQueue::pqIsEmpty() const {
    return h.heapIsEmpty();
}

void PriorityQueue::pqInsert(const logln& newItem) {
        h.heapInsert(newItem);
}

void PriorityQueue::pqDelete(logln& priorityItem)  {
        h.heapDelete(priorityItem);


}