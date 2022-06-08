/*
* Title: Heaps, Priority Queues
* Author: Kutay Şenyiğit
* ID: 21902377
* Section: 1
* Assignment: 3
* Description: login cpp
*///
// Created by Kutay Şenyiğit on 18.04.2022.
//

#include "logln.h"
/*
log();
int getKey();
int getId();
int getRequestTime();
int getProcessTime();
 -*/

logln::logln() : requestTime(-1) , processTime(-1) , id(-1), priority(-1){}

logln::logln(int id , int priority = -1, int requestTime = -1, int processTime = -1 ){

    this->id = id;
    this->requestTime = requestTime;
    this->processTime = processTime;
    this->priority = priority;

}
int logln::getKey() {return  priority;}
int logln::getRequestTime() {return  requestTime;}
int logln::getProcessTime() {return  processTime;}
int logln::getId() {return id;}
int logln::getPriority() {return priority;}
