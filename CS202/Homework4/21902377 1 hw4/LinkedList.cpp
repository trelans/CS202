/*
* Title: CS202 Spring 2022
* Author: Kutay Şenyiğit
* ID: 21902377
* Section: 1
* Assignment: 4
* Description: Linkedlist.cpp
*/
#include "LinkedList.h"
#include <cstddef>     // for NULL

// Constructors
LinkedList::LinkedList(): size(0), head(NULL){

}

LinkedList::LinkedList(const LinkedList& aList): size(aList.size){
    if (aList.head == NULL)
        head = NULL;  // original list is empty
    else {
        // copy first node
        head = new Node;
        head->item = aList.head->item;
        // copy rest of list
        Node *newPtr = head;  // new list ptr

        for (Node *origPtr = aList.head->next;
             origPtr != NULL;
             origPtr = origPtr->next){
            newPtr->next = new Node;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = NULL;
    }
}  // end copy constructor

LinkedList::~LinkedList(){

    while (!isEmpty())
        remove(1);

} // end destructor


bool LinkedList::isEmpty() const{

    return size == 0;

}  // end isEmpty

int LinkedList::getLength() const{

    return size;

}  // end getLength

LinkedList::Node *LinkedList::find(int index) const{
// Locates a specified node in a linked list.
// Precondition: index is the number of the
// desired node.
// Postcondition: Returns a pointer to the
// desired node. If index < 1 or index > the
// number of nodes in the list, returns NULL.

    if ( (index < 1) || (index > getLength()) )
        return NULL;

    else{ // count from the beginning of the list
        Node *cur = head;
        for (int skip = 1; skip < index; ++skip)
            cur = cur->next;
        return cur;
    }
}  // end find

bool LinkedList::insert(int index, int newItem, int weight) {

    int newLength = getLength() + 1;

    if ((index < 1) || (index > newLength))
        return false;

    Node *newPtr = new Node;
    size = newLength;
    newPtr->item = newItem;
    newPtr->weight = weight;

    // head
    if (index == 1){
        newPtr->next = head;
        head = newPtr;
        head->weight = -1;
    }
    else{
        Node *prev = find(index-1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;

} // end insert

bool LinkedList::remove(int index) {

    Node *cur;

    if ((index < 1) || (index > getLength()))
        return false;

    --size;
    if (index == 1){
        cur = head;
        head = head->next;
    }
    else{
        Node *prev = find(index-1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = NULL;
    delete cur;
    cur = NULL;

    return true;

}  // end remove

bool LinkedList::retrieve(int index, int &airPort, int &weight) const {

    if ((index < 1) || (index > getLength()))
        return false;

    // get pointer to node, then data in node
    Node *cur = find(index);
    airPort = cur->item;
    weight = cur->weight;
    return true;
}
bool LinkedList::retrieve(int index, int &airPort) const {

    if ((index < 1) || (index > getLength()))
        return false;

    // get pointer to node, then data in node
    Node *cur = find(index);
    airPort = cur->item;

    return true;
}
int LinkedList::print() {
    Node* current = head->next;
    int count = 0;
    while (current != NULL) {
        count++;
        cout << head->item << " to " << current->item << " with a duration of " << current->weight << "." << endl;

        current = current->next;

    }
    return count;
}

void LinkedList::addWeightsToArray(int *&weights, int& vertexSetSize ,  int*& vertexSet, int *&previousVisited, int& go ) {

  //Initially current node is head-next if

    Node* currentMin = NULL;
    Node* current = head->next;
    int priv = head->item;

    while (current != NULL) {

        // Finds minimum possible way
        if (currentMin != NULL ) {
            if(vertexSet[current->item] == 0 && currentMin->item > current->item) {
                currentMin = current;
            }
        } else {
            if (vertexSet[current->item] == 0 ) {
                currentMin = current;
            }
        }
        // if currentNode is not visited and
        if (vertexSet[current->item] == 0) {
int a = (current->weight);
int b = weights[head->item];
            if( weights[current->item] > ((current->weight)  + weights[head->item]) ) {
                weights[current->item] =   ((current->weight)  + weights[head->item]);
                previousVisited[current->item] = head->item;
            }

        }
        priv = current->item;
        current = current->next;

    }
    if (currentMin != NULL) {
        vertexSet[currentMin->item] = 1;
        go = currentMin->item ;
    }


}

int LinkedList:: initDijkstra(int *&weights, int *&previousVisited, int& totalAirPortSize, int*&  vertexSet) {

    Node* current;
    if (head->next != NULL) {
        current = head->next;
    }



    while (current != NULL) {

        weights[current->item] = current->weight;
        previousVisited[current->item] = head->item;
        current = current->next;
    }
        int min = 99999;
    for (int i = 0; i < totalAirPortSize; ++i) {
        if (weights[i] < min && vertexSet[i] == 0 ) {
            min = weights[i];
        }
    }
    vertexSet[min] = 1;

    return min;


}
/*
int LinkedList::countFlights(int targetAirportNumber) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {

        if (  current->item == targetAirportNumber) {
            count++;
        }

        current = current->next;

    }
    return count;
}
 */

int LinkedList::sumWeight() {
    int sum = 0;
    Node* current = head->next;

    while (current != NULL) {

        sum+= current->weight;
        current = current->next;

    }
    return sum;
}

bool LinkedList::primsAlgo(int &sum, int *&vertexSet , int &minIndex , int& minEdge) {
    Node* current = head->next;
    Node* currentMin = NULL;

    while (current != NULL) {

        // Finds minimum possible way
        if (currentMin != NULL ) {
            if(vertexSet[current->item] == 0 && currentMin->weight > current->weight) {
                currentMin = current;
            }
        } else {
            if (vertexSet[current->item] == 0 ) {
                currentMin = current;
            }
        }
        current = current->next;

    }

    if (currentMin != NULL && (minEdge > currentMin->weight)) {
      //  vertexSet[currentMin->item] = 1;
        minEdge = currentMin->weight;

        minIndex = currentMin->item;

        return true;
    }
    return false;



}