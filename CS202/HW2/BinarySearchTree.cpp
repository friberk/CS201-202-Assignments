/*
 * Title: Trees
 * Author: Berk Çakar
 * ID: 22003021
 * Section: 3
 * Assignment: 2
 * Description: Implementation file for the BinarySearchTree class.
 */

#include "BinarySearchTree.h"
#include "BinaryNode.h"
#include <iostream>

BinarySearchTree::BinarySearchTree() { this->root = nullptr; }

BinarySearchTree::BinarySearchTree(const BinarySearchTree& otherTree) {
    copyBST(this->root, otherTree.root);
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& otherTree) {
    if (this != &otherTree) {
        if (this->root != nullptr) {
            destroyBST(this->root);
        }

        copyBST(this->root, otherTree.root);
    }

    return *this;
}

void BinarySearchTree::copyBST(BinaryNode*& newRoot, BinaryNode* sourceRoot) {
    if (sourceRoot == nullptr) {
        newRoot = nullptr;
        return;
    }

    newRoot = new BinaryNode(sourceRoot->data, sourceRoot->parent, sourceRoot->left,
                             sourceRoot->right, sourceRoot->size);

    copyBST(newRoot->left, sourceRoot->left);
    if (newRoot->left != nullptr)
        newRoot->left->parent = newRoot;
    copyBST(newRoot->right, newRoot->right);
    if (newRoot->right != nullptr)
        newRoot->right->parent = newRoot;
}

BinarySearchTree::~BinarySearchTree() {
    if (this->root != nullptr) {
        destroyBST(this->root);
    }
}

void BinarySearchTree::destroyBST(BinaryNode*& root) {
    if (root == nullptr) {
        return;
    }

    destroyBST(root->left);
    destroyBST(root->right);

    delete root;
    root = nullptr;
}

bool BinarySearchTree::isEmpty() {
    if (this->root == nullptr) {
        return true;
    }

    else {
        return false;
    }
}

int BinarySearchTree::getHeight() { return getHeightHelper(this->root); }

int BinarySearchTree::getHeightHelper(BinaryNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = getHeightHelper(root->left);
    int rightHeight = getHeightHelper(root->right);

    if (leftHeight >= rightHeight) {
        return leftHeight + 1;
    }

    else {
        return rightHeight + 1;
    }
}

int BinarySearchTree::getNumberOfNodes() { return getNumberOfNodesHelper(this->root); }

int BinarySearchTree::getNumberOfNodesHelper(BinaryNode* root) {
    if (root == nullptr) {
        return 0;
    }

    return getNumberOfNodesHelper(root->left) + getNumberOfNodesHelper(root->right) + 1;
}

bool BinarySearchTree::add(int newEntry) {
    if (this->contains(newEntry) == true) {
        return false;
    }

    else {
        bool success = false;
        addHelper(this->root, newEntry, success);
        return success;
    }
}

void BinarySearchTree::addHelper(BinaryNode*& root, const int& newEntry, bool& success) {
    if (root == nullptr) {
        root = new BinaryNode(newEntry);
        root->size = 1;
        success = true;
    }

    else if (newEntry < root->data) {
        addHelper(root->left, newEntry, success);
        if (root->left != nullptr)
            root->left->parent = root;
        root->size++;
    }

    else {
        addHelper(root->right, newEntry, success);
        if (root->right != nullptr)
            root->right->parent = root;
        root->size++;
    }
}

bool BinarySearchTree::remove(int anEntry) {
    bool success = false;
    removeHelper(this->root, anEntry, success);
    return success;
}

void BinarySearchTree::removeHelper(BinaryNode*& root, const int& anEntry, bool& success) {
    if (root == nullptr) {
        success = false;
    }

    else if (anEntry < root->data) {
        root->size--;
        removeHelper(root->left, anEntry, success);
    }

    else if (anEntry > root->data) {
        root->size--;
        removeHelper(root->right, anEntry, success);
    }

    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
            success = true;
        }

        else if (root->left == nullptr && root->right != nullptr) {
            BinaryNode* temp = root;
            root = root->right;
            temp->right = nullptr;
            delete temp;
            success = true;
        }

        else if (root->left != nullptr && root->right == nullptr) {
            BinaryNode* temp = root;
            root = root->left;
            temp->left = nullptr;
            delete temp;
            success = true;
        }

        else {
            int successor = this->successor(anEntry);
            root->data = successor;
            removeHelper(root->right, successor, success);
            root->size--;
        }
    }
}

bool BinarySearchTree::contains(int anEntry) {
    bool success = false;
    BinaryNode* refPtr = nullptr;
    BSTSearch(this->root, anEntry, refPtr, success);

    return success;
}

void BinarySearchTree::BSTSearch(BinaryNode* root, const int& key, BinaryNode*& refPtr,
                                 bool& success) {
    if (root == nullptr) {
        refPtr = nullptr;
        success = false;
    }

    else if (key < root->data) {
        BSTSearch(root->left, key, refPtr, success);
    }

    else if (key > root->data) {
        BSTSearch(root->right, key, refPtr, success);
    }

    else {
        refPtr = root;
        success = true;
    }
}

void BinarySearchTree::inorderTraverse() {
    inorderTraverseHelper(this->root);
    std::cout << std::endl;
}

void BinarySearchTree::inorderTraverseHelper(BinaryNode* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraverseHelper(root->left);

    std::cout << root->data << " ";

    inorderTraverseHelper(root->right);
}

int BinarySearchTree::getWidth() {
    if (this->root == nullptr) {
        return 0;
    }

    int height = getHeight();
    int width = 0;

    for (int i = 1; i <= height; i++) {
        int levelWidth = getWidthHelper(this->root, i);
        if (levelWidth >= width) {
            width = levelWidth;
        }
    }

    return width;
}

int BinarySearchTree::getWidthHelper(BinaryNode* root, int level) {
    if (root == nullptr) {
        return 0;
    }

    else if (level == 1) {
        return 1;
    }

    else {
        return getWidthHelper(root->left, level - 1) + getWidthHelper(root->right, level - 1);
    }
}

int BinarySearchTree::count(int a, int b) {
    int count = 0;
    countHelper(this->root, a, b, count);
    return count;
}

void BinarySearchTree::countHelper(BinaryNode* root, const int& a, const int& b, int& count) {
    if (root == nullptr) {
        return;
    }

    if (root->data >= a && root->data <= b) {
        count++;
    }

    if (a <= root->data) {
        countHelper(root->left, a, b, count);
    }

    if (b >= root->data) {
        countHelper(root->right, a, b, count);
    }
}

int BinarySearchTree::select(int anEntry) {
    if (this->root == nullptr) {
        return -1;
    }

    bool found = false;
    int index = 0;
    selectHelper(root, anEntry, index, found);

    if (found == false) {
        return -1;
    }

    else {
        return index;
    }
}

void BinarySearchTree::selectHelper(BinaryNode* root, const int& key, int& index, bool& found) {
    if (root == nullptr) {
        found = false;
    }

    else if (key < root->data) {
        selectHelper(root->left, key, index, found);
    }

    else if (key > root->data) {
        index++;
        if (root->left != nullptr) {
            index = index + root->left->size;
        }
        selectHelper(root->right, key, index, found);
    }

    else {
        if (root->left != nullptr) {
            index = index + root->left->size;
        }
        found = true;
    }
}

int BinarySearchTree::successor(int anEntry) {
    bool success = false;
    BinaryNode* node = nullptr;
    BSTSearch(this->root, anEntry, node, success);

    if (success == false) {
        return -1;
    }

    BinaryNode* refPtr = nullptr;
    successorHelper(node, refPtr);

    if (refPtr != nullptr) {
        return refPtr->data;
    }

    else {
        return -2;
    }
}

void BinarySearchTree::successorHelper(BinaryNode* node, BinaryNode*& refPtr) {
    if (node->right != nullptr) {
        node = node->right;
        while (node->left != nullptr) {
            node = node->left;
        }
        refPtr = node;
    }

    else {
        BinaryNode* temp = node->parent;
        while (temp != nullptr && node == temp->right) {
            node = temp;
            temp = temp->parent;
        }
        refPtr = temp;
    }
}
