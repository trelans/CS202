//
// Created by Kutay Şenyiğit on 18.04.2022.
//
/*
* Title: Heaps, Priority Queues
* Author: Kutay Şenyiğit
* ID: 21902377
* Section: 1
* Assignment: 3
* Description: computer.h
*/

#include "computer.h"



/*
computer::computer();
bool isComputerAvailable();
computer getAvailableComputer();

 */

computer::computer() {
    isAvailable = true;
}
computer::computer(int cid, int totalIn) {
    isAvailable = true;
    id = cid;
    isFinal = false;
    this->totalInst = totalIn;
    wait = 0;
}
bool computer::isComputerAvailable() {
    return  isAvailable;
}

bool computer::isLast() {
    return isFinal;
}

int computer::checkWillBeFree(int time){
    currentTime = time;
    if(!isAvailable) {
        if(freeTime == time) {
           return setComputerFree();
        }
    }
    return 0;
}

int computer::setComputerFree() {
    int  waitTime = currentTime - startProcessTime;
    // print the necessary values

    isAvailable = true;

    // returns waiting time
    return waitTime;

}
void computer::useComputer(int currentTime, int requestNo ,logln& currentReq) {
    wait = 0;
    isAvailable = false;
    this->currentTime = currentTime;
    startProcessTime = currentTime;
    // calculate the free time

    calculateFreeTime(currentReq.getProcessTime());
    this->requestNo = currentReq.getId();
    if(totalInst == requestNo) {
        isFinal = true;
    }

}

void computer::calculateFreeTime(int processTime) {
    freeTime = currentTime + processTime ;


}

int computer::getID() {
    return id;
}

