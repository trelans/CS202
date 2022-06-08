/*
* Title: Trees
* Author: Kutay Şenyiğit
* ID: 21902377
* Section: 1
* Assignment: 2
* Description: BinaryNode.cpp
*/
#include "BinaryNode.h"


BinaryNode::BinaryNode() {

}
BinaryNode::BinaryNode( const int &nodeItem, BinaryNode *parent, BinaryNode *left, BinaryNode *right ) : size(0), item(nodeItem), parentPtr(parent) , leftChildPtr(left), rightChildPtr(right){
    updateSizes(1);
}

BinaryNode::~BinaryNode() {

    updateSizes(-1);
    leftChildPtr = NULL;
    rightChildPtr = NULL;
    parentPtr = NULL;
}

void BinaryNode::updateSizes(int numb) {

    BinaryNode* point = parentPtr;

    while(point != NULL){
        point->size = point->size + numb;
        point = point->parentPtr;
    }
}