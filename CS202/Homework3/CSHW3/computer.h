/*
* Title: Heaps, Priority Queues
* Author: Kutay Şenyiğit
* ID: 21902377
* Section: 1
* Assignment: 3
* Description: computer
*///
// Created by Kutay Şenyiğit on 18.04.2022.
//
#include "logln.h"
#include <iostream>

using namespace std;
#ifndef CS202HW3_COMPUTER_H
#define CS202HW3_COMPUTER_H


class computer {

public:
    computer();
    computer(int id , int totalIn);
    bool isComputerAvailable();
    int checkWillBeFree(int time);
    void calculateFreeTime(int processTime );
    void useComputer( int currentTime, int requestNo ,logln& currentReq);
    int setComputerFree(); // returns wait
    bool isLast();
    void increaseWait();
    int getID();

private:

    int id;
    bool isAvailable;
    int freeTime;
    int currentTime;
    int startProcessTime;
    int requestNo;
    int isFinal;
    int totalInst;
    int wait;
    logln currentInst;

};


#endif //CS202HW3_COMPUTER_H
