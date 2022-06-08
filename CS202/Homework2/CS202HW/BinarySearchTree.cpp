/*
* Title: Trees
* Author: Kutay Şenyiğit
* ID: 21902377
* Section: 1
* Assignment: 2
* Description: BinarySearchTree.cpp
*/

#include "BinarySearchTree.h"

//
BinarySearchTree::BinarySearchTree(): root(NULL) {}
//
BinarySearchTree::BinarySearchTree (const BinarySearchTree &tree) {
    copyTree(tree.root, root);
}
//
BinarySearchTree::~BinarySearchTree() {
    destroyTree(root);
}
//
bool BinarySearchTree::isEmpty() {
    return root == NULL;
}
//
int BinarySearchTree::getHeight() {
   return maxDepth(root);
}
//
int BinarySearchTree::maxDepth(BinaryNode *node) {
    if (node == NULL) {
        return 0;
    }
    else {
        return 1 + max(maxDepth(node->leftChildPtr), maxDepth(node->rightChildPtr));
    }
}
//
int BinarySearchTree::getNumberOfNodes() {
    return root->size + 1;}
//
bool BinarySearchTree::add(int newEntry) {

    if(!contains(newEntry) && newEntry > 0) {
        BinaryNode *nullBinaryNode = NULL;
        return insertItem(root, nullBinaryNode,newEntry);
    }
    return false;
}

//
bool BinarySearchTree::remove(int anEntry) {
    if (!contains(anEntry)) {
        return false;
    }
    else {
        removeHelper(root, anEntry);
        return true;
    }
}

void BinarySearchTree::removeHelper(BinaryNode*& treePtr, const int& anEntry) {
    if (treePtr != NULL) {
        if (anEntry > treePtr->item) {

            removeHelper(treePtr->rightChildPtr, anEntry);
        }
        else if (anEntry < treePtr->item) {

            removeHelper(treePtr->leftChildPtr, anEntry);
        }
        else {
            deleteNodeItem(treePtr);
        }
    }
}

int BinarySearchTree::count(int a, int b) {
    return countRecursive(root,a,b);

}

int BinarySearchTree::countRecursive(BinaryNode *root, int a, int b) {

    if (!root) return 0;

    if (root->item == b && root->item == a)
        return 1;

    if (root->item <= b && root->item >= a)
        return 1 + countRecursive(root->leftChildPtr, a, b) +
                countRecursive(root->rightChildPtr, a, b);


    else if (root->item < a)
        return countRecursive(root->rightChildPtr, a, b);

    else return  countRecursive(root->leftChildPtr, a, b);
}

bool BinarySearchTree::contains(int anEntry) {
    if(find(root, anEntry) != NULL) {
        return true;
    }
    return false;
}

int BinarySearchTree::select(int anEntry) {
    int index = -1;
    int count = 0;


    getIndexOfTheTree(root, anEntry, index, count);

    int indexSaved = index;

    count = 0;

    if (indexSaved == -1)
        return -1;

    return indexSaved;
}

int BinarySearchTree::successor(int anEntry) {

    if (!contains(anEntry))
    {
        return -1;
    }
    int item;

    BinaryNode* n  = find(root, anEntry);
    BinaryNode* success = successorHelp(n, NULL, 0);

    if (success == NULL) {
        return -2;
    }

    return (success->item);
}

BinaryNode* BinarySearchTree::successorHelp(BinaryNode *root, BinaryNode* next, int key) {

    if (root->rightChildPtr != NULL)
    {

        return min(root->rightChildPtr);
    }

    BinaryNode* n = root->parentPtr;
    while (n != NULL && root == n->rightChildPtr)
    {
        root = n;
        n = n->parentPtr;
    }
    return n;
}

BinaryNode *BinarySearchTree::min(BinaryNode *root) {
    BinaryNode* current = root;

    while (current->leftChildPtr != NULL)
    {
        current = current->leftChildPtr;
    }
    return current;
}
int BinarySearchTree::getWidth() {
    int height = getHeight();
    int currentMax = 0;
    // level count bul sonra yap
    int currentLevel = 1;
    for (int i = 1; i <= height; ++i) {

       int currentWidth =  getLevelNodeCount(root, i);

       if (currentMax < currentWidth) {
           currentMax = currentWidth;
    }

    }
    return currentMax;
}

void BinarySearchTree::inorderTraverse() {
    inorder(root);
}

bool BinarySearchTree::retrieveItem(BinaryNode *treePtr, int searchKey, int &item) {

    if (treePtr == NULL)
        return false;
    else if (searchKey == treePtr->item)
        item = treePtr->item;
    else if (searchKey < treePtr->item)
        retrieveItem(treePtr->leftChildPtr, searchKey, item);
    else
        retrieveItem(treePtr->rightChildPtr, searchKey, item);

}

int BinarySearchTree::getLevelNodeCount(BinaryNode *root, int level) {

    if(root == NULL) {
        return 0;
    }

    if (1 == level) {
        return 1;
    }
    else if (level > 1)
     return getLevelNodeCount (root->leftChildPtr,   level-1) +
            getLevelNodeCount (root->rightChildPtr,  level-1);

}
bool BinarySearchTree::insertItem(BinaryNode *& treePtr, BinaryNode *& parentPtr,
                                  const int& newItem)  {

    if (treePtr == NULL) {


        treePtr = new BinaryNode(newItem, parentPtr, NULL, NULL);

        if (treePtr == NULL) {
            return false;
        }
            return true;
    }

    else if (newItem < treePtr->item) {

      return insertItem(treePtr->leftChildPtr, treePtr, newItem);
    }
    else {

       return insertItem(treePtr->rightChildPtr,treePtr, newItem);
    }

}



bool BinarySearchTree::deleteItem(BinaryNode * &treePtr, int searchKey)
 {
    if (treePtr == NULL)
        return false;


    else if (searchKey == treePtr->item) {

        deleteNodeItem(treePtr);
        return true;
    }

    else if (searchKey < treePtr->item)
       return  deleteItem(treePtr->leftChildPtr, searchKey);
    else
       return deleteItem(treePtr->rightChildPtr, searchKey);
}
void BinarySearchTree::inorder(BinaryNode* treePtr) const {
    if (treePtr != NULL) {
        inorder(treePtr->leftChildPtr);
        cout << treePtr->item << " ";
        inorder(treePtr->rightChildPtr);
    }
}
BinaryNode* BinarySearchTree::find(BinaryNode *&treePtr, int searchKey) {
        if (treePtr == NULL)
            return NULL;

        else if (searchKey == treePtr->item)
            return treePtr;


        else if (searchKey < treePtr->item)
           return find(treePtr->leftChildPtr, searchKey);
        else
           return find(treePtr->rightChildPtr, searchKey);

}

void BinarySearchTree::deleteNodeItem(BinaryNode * &nodePtr) {
    BinaryNode *delPtr;
    int replacementItem;



    if ( (nodePtr->leftChildPtr == NULL) &&
         (nodePtr->rightChildPtr == NULL) ) {
        delete nodePtr;
        nodePtr = NULL;
    }


    else if (nodePtr->leftChildPtr == NULL) {
        delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }

    else if (nodePtr->rightChildPtr == NULL) {
         delPtr = nodePtr;
         nodePtr = nodePtr->leftChildPtr;
         delPtr->leftChildPtr = NULL;
         delete delPtr;
    }

    else {
            processLeftmost(nodePtr->rightChildPtr, replacementItem);
            nodePtr->item = replacementItem;
        }

    }

void BinarySearchTree::processLeftmost(BinaryNode * &nodePtr, int& item) {
    if (nodePtr->leftChildPtr != NULL) {
        processLeftmost(nodePtr->leftChildPtr, item);
    }
    else {
        item = nodePtr->item;
        BinaryNode* deletePTR = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        deletePTR->rightChildPtr = NULL;
        delete deletePTR;
    }
}


void BinarySearchTree::copyTree(BinaryNode *treePtr, BinaryNode *& newTreePtr) const {

    if (treePtr != NULL) {
        newTreePtr = new BinaryNode(treePtr->item, NULL, NULL);
        copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
        copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
    }
    else
        newTreePtr = NULL;
}

void BinarySearchTree::destroyTree(BinaryNode *& treePtr) {

    if (treePtr != NULL){
        destroyTree(treePtr->leftChildPtr);
        destroyTree(treePtr->rightChildPtr);
        delete treePtr;
        treePtr = NULL;
    }
}

bool BinarySearchTree::removeLeftmostNode(BinaryNode *nodePtr, int &inorderSuccesssor) {
    if (nodePtr->leftChildPtr == NULL)
    {
        inorderSuccesssor = nodePtr->item;
        deleteNodeItem(nodePtr);
    }
    else
        return removeLeftmostNode(nodePtr->leftChildPtr, inorderSuccesssor);
}



void BinarySearchTree::getIndexOfTheTree(BinaryNode* node, int n, int& i, int& c)
{
    if (node == NULL)
    {
        return;
    }
    if (c <= n)
    {
        getIndexOfTheTree(node->leftChildPtr, n, i, c);
        c++;
        if (node->item == n)
        {
            i += c;
        }
        getIndexOfTheTree(node->rightChildPtr, n, i, c);
    }
}