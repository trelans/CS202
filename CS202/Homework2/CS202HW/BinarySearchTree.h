/*
* Title: Trees
* Author: Kutay Şenyiğit
* ID: 21902377
* Section: 1
* Assignment: 2
* Description: BinarySearchTree.h
*/

#include "BinaryNode.h"
#include <iostream>

using namespace std;
#ifndef CSHW2_BINARYSEARCHTREE_H
#define CSHW2_BINARYSEARCHTREE_H



class BinarySearchTree {
public:

    BinarySearchTree(); // done
    BinarySearchTree(const BinarySearchTree& tree); // done
    ~BinarySearchTree(); // done

    // required methods for hw
    bool isEmpty(); // done
    int getHeight();
    int getNumberOfNodes(); //done
    bool add(int newEntry);
    bool remove(int anEntry);
    bool contains(int anEntry);
    void inorderTraverse();
    int getWidth();
    int count(int a, int b);
    int select(int anEntry);
    int successor(int anEntry);

    void searchTreeRetrieve(int searchKey, int& item);
    void searchTreeInsert(const int& newItem);
    void searchTreeDelete(int searchKey);

    int maxDepth(BinaryNode* node);
protected:

    bool retrieveItem(BinaryNode *treePtr, int searchKey,int& item); // done
    bool insertItem(BinaryNode * &treePtr, BinaryNode *& parentPtr, const int& item);
    bool deleteItem(BinaryNode * &treePtr, int searchKey);
    BinaryNode* find(BinaryNode *& treePtr, int searchKey);
    void deleteNodeItem(BinaryNode * &nodePtr);
    void processLeftmost(BinaryNode * &nodePtr, int& item);

    void copyTree(BinaryNode *treePtr, BinaryNode *& newTreePtr) const; // done
    void destroyTree(BinaryNode *& treePtr); // done
    void inorder(BinaryNode* tree) const;



    int getLevelNodeCount (BinaryNode* root, int level);
    int countRecursive(BinaryNode* root, int a, int b);
    BinaryNode* successorHelp(BinaryNode* root, BinaryNode* prev, int key);
    BinaryNode* min(BinaryNode* root);
    void getIndexOfTheTree(BinaryNode* node, int n, int& i, int& c);
    bool removeLeftmostNode( BinaryNode* nodePtr, int& inorderSucesssor );
    void removeHelper(BinaryNode*& treePtr, const int& anEntry);
private:
     BinaryNode* root;
};


#endif //CSHW2_BINARYSEARCHTREE_H
