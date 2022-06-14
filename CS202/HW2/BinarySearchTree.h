/*
 * Title: Trees
 * Author: Berk Çakar
 * ID: 22003021
 * Section: 3
 * Assignment: 2
 * Description: Header file for the BinarySearchTree class.
 */

#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

#include "BinaryNode.h"
#include "analyze.h"

class BinarySearchTree {
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& otherTree);
    BinarySearchTree& operator=(const BinarySearchTree& otherTree);
    ~BinarySearchTree();

    bool isEmpty();
    int getHeight();
    int getNumberOfNodes();
    bool add(int newEntry);
    bool remove(int anEntry);
    bool contains(int anEntry);
    void inorderTraverse();
    int getWidth();
    int count(int a, int b);
    int select(int anEntry);
    int successor(int anEntry);

private:
    BinaryNode* root;

    // Auxillary functions
    void copyBST(BinaryNode*& newRoot, BinaryNode* sourceRoot);
    void destroyBST(BinaryNode*& root);
    int getHeightHelper(BinaryNode* root);
    int getNumberOfNodesHelper(BinaryNode* root);
    void addHelper(BinaryNode*& root, const int& newEntry, bool& success);
    void removeHelper(BinaryNode*& root, const int& anEntry, bool& success);
    void BSTSearch(BinaryNode* root, const int& key, BinaryNode*& refPtr, bool& success);
    void inorderTraverseHelper(BinaryNode* root);
    int getWidthHelper(BinaryNode* root, int level);
    void countHelper(BinaryNode* root, const int& a, const int& b, int& count);
    void selectHelper(BinaryNode* root, const int& key, int& index, bool& found);
    void successorHelper(BinaryNode* node, BinaryNode*& refPtr);
};

#endif // __BINARYSEARCHTREE_H__
