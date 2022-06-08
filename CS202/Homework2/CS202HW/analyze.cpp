/*
* Title: Trees
* Author: Kutay Şenyiğit
* ID: 21902377
* Section: 1
* Assignment: 2
* Description: analyze.cpp
*/
#include "BinarySearchTree.h"
#include <iostream>


  void analyzeBST() {
   int  size = 1000;
  int  arr[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % (INT_MAX) + 1;
    }
    BinarySearchTree binarySearchTree;

      cout << "Random BST size vs. height (Insertion)\n" <<
              "-----------------------------------------" << endl;
    for (int i = 0; i < size; ++i) {

    binarySearchTree.add(arr[i]);

        if (i % 99 == 0) {
            cout << i + 1 << " " << binarySearchTree.getHeight() << endl;
        }
    }
      random_shuffle(&arr[0],&arr[size]);

      cout << "Random BST size vs. height (Insertion)\n" <<
              "-----------------------------------------" << endl;

      for (int i = 0; i < size; ++i) {

          binarySearchTree.remove(arr[i]);

          if (i % 99 == 0) {
              cout << i + 1 << " " << binarySearchTree.getHeight() << endl;

          }
      }

}

