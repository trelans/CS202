/*
* Title: Heaps, Priority Queues
* Author: Kutay Şenyiğit
* ID: 21902377
* Section: 1
* Assignment: 3
* Description: main class
*/
#include "logln.h"
#include "PriorityQueue.h"
#include "computer.h"
#include <fstream>
#include <sstream>
#include <list>
#include <iostream>
using namespace std;

double stringToDouble(string string);
void increaseComputerCount( computer*& computers, int& computerCount, int instCount);

int main(int argc, char* argv []) { //
//
    string  currentOutput;

    string t = "/Users/kutaysenyigit/CLionProjects/CS202HW3/input.txt";
    int waitingTimeSum = 0;
    int currentWait = 0;
    int currentCompCount = 1;

    int requestNo = 0;

    string avgTimeStr;
    string fileName;
    // Getting the file name
   /* if (argc > 1) {
        string fileName = argv[1];
        string avgTimeStr = argv[2];
    }
*/
   /* char c[fileName.size()];
    for (int i = 0; i < fileName.size(); ++i) {
        c[i] = fileName[i];
    }
    */
    // Getting the average time

     fileName = argv[1];
     avgTimeStr = argv[2];

    // Cast avgTime string argument to double
    double avgTime = stringToDouble(avgTimeStr);
    const char *str = fileName.c_str();
    ifstream inFile;
    inFile.open(str);

    if (!inFile) {
        cout  << "Could not find the file " << fileName;

    }

    int lineCount;
    inFile >> lineCount ;

    int currentId;
    int currentPriority;
    int currentRequestTime;
    int currentProcessTime;

    PriorityQueue priorityQueue(lineCount) ;

    logln logs[lineCount];

    for(int i = 0 ; i < lineCount; i++)
    {
        inFile >> currentId;
        inFile >> currentPriority;
        inFile >> currentRequestTime;
        inFile >> currentProcessTime;


       // priorityQueue.pqInsert(logln (currentId, currentPriority, currentRequestTime, currentProcessTime ));
        logs[i] = logln (currentId, currentPriority, currentRequestTime, currentProcessTime);


    }



    bool isOver = false;
    bool isFound = false;
    for (int currentComputerCount  = 1 ; !isFound;  ) {
        computer *computers = new computer[currentCompCount];

        for (int i = 0; i < currentCompCount; ++i) {
            computers[i] = computer(i, lineCount);
        }

        for (int time = 0; !isOver ; ++time) {

            for (int i = 0; i < currentComputerCount; ++i) {
              computers[i].checkWillBeFree(time); // prints etc
                if (computers[i].isLast()) {
                   isOver = true;

                }

            }
        // All instructions are added to priorityQueue when time came
            for (int i = 0; i < lineCount; ++i) {
                if (logs[i].getRequestTime() == time) {
                    priorityQueue.pqInsert(logs[i]);

                }
            }
            if (!priorityQueue.pqIsEmpty()) {
                //check for available computer
                for (int i = 0; (i < currentComputerCount) && !priorityQueue.pqIsEmpty(); ++i) {
                    if (computers[i].isComputerAvailable() ) {

                        requestNo++;
                        logln currentRequest;
                        priorityQueue.pqDelete(currentRequest) ;
                        currentWait = time - currentRequest.getRequestTime();
                        waitingTimeSum += currentWait;
                        std::stringstream sstm;
                        sstm << "Computer " << computers[i].getID() << " takes request " << currentRequest.getId() << " at ms " << time << " (wait: " << currentWait <<"ms)" << endl;
                        currentOutput += sstm.str();
                        computers[i].useComputer(  time,requestNo, currentRequest ); //process current

                    }

                }
            }

            if (isOver) {
                break;
            }

        }

        double avgWait = (double) waitingTimeSum / lineCount;
     //   cout << "Avg waiting:" << avgWait;

        if (avgTime >= avgWait ) {
            cout << "Minimum number of computers required: " << currentComputerCount << endl;
            cout << endl << "Simulation with " << currentComputerCount << " computers" << ": \n\n";
            cout << currentOutput;
            cout << endl << "Average waiting time: " << avgWait << "ms";
            isFound = true;
            delete [] computers;
            break;
        }
        else {
            currentCompCount++;
            currentComputerCount++;
            delete [] computers;

            isOver = false;
            requestNo = 0;
            waitingTimeSum = 0;
            currentOutput = "";
        }

        // increasepc
     //   increaseComputerCount(computers, currentComputerCount, lineCount);



    }


    return 0;
    }


double stringToDouble(string string) {
    double db;
    stringstream ss(string);
    ss >> db;
    return db;
}

void increaseComputerCount( computer*& computers, int& computerCount, int instCount) {

    computerCount++;
    delete [] computers;

    computers = new computer[computerCount];

    for (int i = 0; i < computerCount; ++i) {

        computers[i] =  computer(i, instCount);
    }

}