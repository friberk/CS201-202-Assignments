/*
 * Title: Trees
 * Author: Berk Çakar
 * ID: 22003021
 * Section: 3
 * Assignment: 2
 * Description: Implementation file for the BinaryNode class.
 */

#include "BinaryNode.h"

BinaryNode::BinaryNode() {
    this->data = 0;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->size = 0;
}

BinaryNode::BinaryNode(const int& data, BinaryNode* parent, BinaryNode* left, BinaryNode* right,
                       const int& size) {
    this->data = data;
    this->parent = parent;
    this->left = left;
    this->right = right;
    this->size = size;
}

BinaryNode::BinaryNode(const BinaryNode& otherNode)
    : data(otherNode.data), parent(otherNode.parent), left(otherNode.left), right(otherNode.right),
      size(otherNode.size) {}

BinaryNode& BinaryNode::operator=(const BinaryNode& otherNode) {
    if (this != &otherNode) {
        this->data = otherNode.data;
        this->parent = otherNode.parent;
        this->left = otherNode.left;
        this->right = otherNode.right;
        this->size = otherNode.size;
    }

    return *this;
}

BinaryNode::~BinaryNode() {
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}
