/*
* Title: Trees
* Author: Kutay Şenyiğit
* ID: 21902377
* Section: 1
* Assignment: 2
* Description: BinaryNode.h
*/

#ifndef CSHW2_BINARYNODE_H
#define CSHW2_BINARYNODE_H

#include "cstdio"


class BinaryNode {
private:
    BinaryNode();
    BinaryNode(const int &nodeItem, BinaryNode *parent = NULL, BinaryNode *left = NULL, BinaryNode *right = NULL);
    ~BinaryNode();
    int size;
    int item;
    BinaryNode *leftChildPtr;
    BinaryNode *rightChildPtr;
    BinaryNode *parentPtr;

    void updateSizes(int numb);
    friend class BinarySearchTree;
};



#endif //CSHW2_BINARYNODE_H
