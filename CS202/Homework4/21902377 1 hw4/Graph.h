/*
* Title: CS202 Spring 2022
* Author: Kutay Şenyiğit
* ID: 21902377
* Section: 1
* Assignment: 4
* Description: Graph.h
*/
#include "LinkedList.h"

#ifndef CS202HW4_GRAPH_H
#define CS202HW4_GRAPH_H


class Graph {


public:
    Graph();
    Graph(int airPortCount);
    Graph( const Graph& aGraph);
    ~Graph();

    LinkedList* addVertex(int airport);
    void addEdges(int airport1, int intAirport2, int weight);
    void addEdgesWithoutPrint(int airport1, int intAirport2, int weight);
    LinkedList* getVertex(int airport);



    void findDuration();
    Graph Prims();
    void printGraph();
    void listFlights(int airPortNo );
    bool shortestPath(int startingVertexIndex ,int*& weights, int *&previousVertex);
    void shortestPathCalculate(int firstNumb , int secondNumb);
private:
    LinkedList** airports;
    int size;
    int totalAirPortSize;
};


#endif //CS202HW4_GRAPH_H
