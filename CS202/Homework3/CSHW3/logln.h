/*
* Title: Heaps, Priority Queues
* Author: Kutay Şenyiğit
* ID: 21902377
* Section: 1
* Assignment: 3
* Description: login.h
*///
// Created by Kutay Şenyiğit on 18.04.2022.
//

#ifndef CS202HW3_LOGLN_H
#define CS202HW3_LOGLN_H


class logln {

public:
    logln();
    logln(int id , int priority, int requestTime, int processTime);
    int getKey();
    int getPriority();
    int getId();
    int getRequestTime();
    int getProcessTime();

private:
    int id;
    int priority;
    int requestTime;
    int processTime;

};


#endif //CS202HW3_LOGLN_H
