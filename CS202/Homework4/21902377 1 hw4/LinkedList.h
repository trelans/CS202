/*
* Title: CS202 Spring 2022
* Author: Kutay Şenyiğit
* ID: 21902377
* Section: 1
* Assignment: 4
* Description: Linkedlist.h
*/
#ifndef CS202HW4_LINKEDLIST_H
#define CS202HW4_LINKEDLIST_H
#include <iostream>

using namespace std;

class LinkedList {
public :

    LinkedList();
    LinkedList( const LinkedList& aList);
    ~LinkedList();

    bool isEmpty() const ;
    int getLength() const ;
    bool insert( int newPosition, int newItem, int weight);
    bool remove( int position);
    bool retrieve( int index,
                   int &airPort, int &weight) const;
    bool retrieve(int index, int &airPort) const;

    bool primsAlgo(int& sum , int*& vertexSet , int& minIndex, int& minEdge);
    int print();
    int countFlights(int targetAirportNumber);
    void addWeightsToArray(int *&weights, int& vertexSetSize , int*& vertexSet , int *&previousVisited , int& go);
    int initDijkstra(int*& weights, int*& previousVisited,int &totalAirPortSize , int* & vertexSet);
    int sumWeight();
private:
    struct Node{
        int item;
        int weight;
        Node *next;
    };

    int size;
    Node *head;

    Node *find(int index) const;
};


#endif //CS202HW4_LINKEDLIST_H
