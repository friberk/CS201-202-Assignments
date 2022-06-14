/*
 * Title: Trees
 * Author: Berk Çakar
 * ID: 22003021
 * Section: 3
 * Assignment: 2
 * Description: Header file for the BinaryNode class.
 */

#ifndef __BINARYNODE_H__
#define __BINARYNODE_H__

#define nullptr 0

class BinaryNode {
private:
    BinaryNode();
    BinaryNode(const int& data, BinaryNode* parent = nullptr, BinaryNode* left = nullptr,
               BinaryNode* right = nullptr, const int& size = 0);
    BinaryNode(const BinaryNode& otherNode);
    BinaryNode& operator=(const BinaryNode& otherNode);
    ~BinaryNode();

    int data;
    BinaryNode* parent;
    BinaryNode* left;
    BinaryNode* right;
    int size; // Number of nodes in the subtree referred by this node.

    friend class BinarySearchTree; // Let BinarySearchTree class to access private fields.
};

#endif // __BINARYNODE_H__
