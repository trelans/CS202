
/*
* Title: CS202 Spring 2022
* Author: Kutay Şenyiğit
* ID: 21902377
* Section: 1
* Assignment: 4
* Description: main.cpp
*/

#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Graph.h"
using namespace std;
int main() {


    // first line n = numberOfAirPorts
    // second line m = numberOfOperations

    const char* fileName = "input.txt";
    ifstream inFile;
    inFile.open(fileName);

    if (!inFile) {
        cout  << "Could not find the file " << fileName;

    }
    int numberOfAirPorts, numberOfOperations;
    string currentInstruction;

    inFile >> numberOfAirPorts ;
    inFile >> numberOfOperations;

    Graph graph(numberOfAirPorts);

    int firstN, secondN, thirdN;

    for (int i = 0; i < numberOfOperations; ++i) {

        inFile >> currentInstruction;
        if (currentInstruction == "I") {

            inFile >>  firstN ;
            inFile >>  secondN ;
            // weight
            inFile >>  thirdN ;

           graph.addEdges(firstN, secondN, thirdN);

        }
        else if (currentInstruction == "S") {

            inFile >>  firstN ;
            inFile >>  secondN ;
          //  int* weight;
        //   int* lPath ;
            graph.shortestPathCalculate(firstN,secondN);
//            graph.shortestPath(2, weight , lPath);



        }
        else if (currentInstruction == "L") {
            inFile >>  firstN ;

            graph.listFlights(firstN);
        }
        else if (currentInstruction == "M") {
        graph.findDuration();
        graph =  graph.Prims();
        }


    }
 //  graph.shortestPathCalculate(2,3);

    /*
      int* arr1;
      int* arr2;
      graph.shortestPath(2, arr1 , arr2);

      for (int i = 0; i < 5; ++i) {
          cout << arr1[i] << " ";
     }
      cout << endl;
      for (int i = 0; i < 5; ++i) {
          cout << arr2[i] << " ";
      }

      cout << endl; cout << endl;
      graph.shortestPath(1, arr1 , arr2);

      for (int i = 0; i < 5; ++i) {
          cout << arr1[i] << " ";
      }
      cout << endl;
      for (int i = 0; i < 5; ++i) {
          cout << arr2[i] << " ";
      }
      cout << endl; cout << endl;
      graph.shortestPath(2, arr1 , arr2);

      for (int i = 0; i < 5; ++i) {
          cout << arr1[i] << " ";
      }
      cout << endl;
      for (int i = 0; i < 5; ++i) {
          cout << arr2[i] << " ";
      }
      cout << endl; cout << endl;
      graph.shortestPath(3, arr1 , arr2);

      for (int i = 0; i < 5; ++i) {
          cout << arr1[i] << " ";
      }
      cout << endl;
      for (int i = 0; i < 5; ++i) {
          cout << arr2[i] << " ";
      }
      cout << endl; cout << endl;
      graph.shortestPath(4, arr1 , arr2);

      for (int i = 0; i < 5; ++i) {
          cout << arr1[i] << " ";
      }
      cout << endl;
      for (int i = 0; i < 5; ++i) {
          cout << arr2[i] << " ";
      }
      cout << endl; cout << endl;

      */


    return 0;
}


