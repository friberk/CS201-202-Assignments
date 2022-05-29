/**
 * FlowerList class implementation file for the CS201's HW3 assignment.
 * Author: Berk Cakar - 22003021
 */

#include "FlowerList.h"

FlowerList::FlowerList() {
    this->size = 0;
    this->head = NULL;
}

FlowerList::FlowerList(const FlowerList& aList) : size(aList.size) {
    if (aList.head == NULL || aList.size == 0) {
        this->size = 0;
        this->head = NULL;
    } else {
        FlowerNode* cur2 = aList.head;

        this->head = new FlowerNode();
        this->head->f = cur2->f;
        this->head->next = NULL;

        FlowerNode* cur = this->head;
        cur2 = cur2->next;

        while (cur2 != NULL) {
            cur->next = new FlowerNode();
            cur = cur->next;
            cur->f = cur2->f;
            cur->next = NULL;
            cur2 = cur2->next;
        }
    }
}

FlowerList::~FlowerList() {
    FlowerNode* cur = this->head;
    while (cur != NULL) {
        FlowerNode* temp = cur;
        cur = cur->next;
        delete temp;
    }
    this->size = 0;
    this->head = NULL;
}

FlowerList& FlowerList::operator=(const FlowerList& aList) {
    if (this != &aList) {
        FlowerNode* cur = this->head;
        while (cur != NULL) {
            FlowerNode* temp = cur;
            cur = cur->next;
            delete temp;
        }

        this->size = aList.size;

        if (aList.head == NULL || aList.size == 0) {
            this->size = 0;
            this->head = NULL;
        } else {
            FlowerNode* cur2 = aList.head;

            this->head = new FlowerNode();
            this->head->f = cur2->f;
            this->head->next = NULL;

            FlowerNode* cur = this->head;
            cur2 = cur2->next;

            while (cur2 != NULL) {
                cur->next = new FlowerNode();
                cur = cur->next;
                cur->f = cur2->f;
                cur->next = NULL;
                cur2 = cur2->next;
            }
        }
    }

    return *this;
}

bool FlowerList::isEmpty() const {
    if (this->size == 0) {
        return true;
    }

    return false;
}

int FlowerList::getLength() const { return this->size; }

bool FlowerList::retrieve(std::string flowerName, Flower& flower) const {
    FlowerNode* cur = this->head;
    while (cur != NULL) {
        if (cur->f.getFlowerName() == flowerName) {
            flower = cur->f;
            return true;
        }
        cur = cur->next;
    }
    return false;
}

// This version of retrieve returns the actual reference to the flower object
bool FlowerList::retrieve(std::string flowerName, Flower** flower) const {
    FlowerNode* cur = this->head;
    while (cur != NULL) {
        if (cur->f.getFlowerName() == flowerName) {
            *flower = &(cur->f);
            return true;
        }
        cur = cur->next;
    }
    return false;
}

bool FlowerList::add(std::string flowerName) {
    FlowerNode* node = new FlowerNode();
    node->f.setFlowerName(flowerName);
    node->next = NULL;

    FlowerNode *prev, *cur;
    if (this->head == NULL) {
        this->head = node;
    } else {
        prev = NULL;
        cur = this->head;
        while (cur != NULL && node->f.getFlowerName().compare(cur->f.getFlowerName()) >= 0) {
            if (cur->f.getFlowerName() == flowerName) {
                std::cout << flowerName
                          << " cannot be added into the library because it already exists."
                          << std::endl;
                delete node;
                return false;
            }
            prev = cur;
            cur = cur->next;
        }
        if (cur == NULL) {
            prev->next = node;
        } else {
            if (prev != NULL) {
                node->next = prev->next;
                prev->next = node;
            } else {
                node->next = this->head;
                this->head = node;
            }
        }
    }
    this->size++;
    std::cout << flowerName << " has been added into the library." << std::endl;
    return true;
}

bool FlowerList::remove(std::string flowerName) {
    FlowerNode *prev, *cur;
    prev = NULL;
    cur = this->head;
    while (cur != NULL && cur->f.getFlowerName() != flowerName) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL) {
        std::cout << flowerName << " cannot be removed because it's not in the library."
                  << std::endl;
        return false;
    } else {
        if (prev == NULL) {
            this->head = cur->next;
        } else {
            prev->next = cur->next;
        }
        delete cur;
        this->size--;
        std::cout << flowerName << " has been removed from the library." << std::endl;
        return true;
    }
}

void FlowerList::listFlowers() const {
    if (isEmpty() == true) {
        std::cout << "Library is empty." << std::endl;
        return;
    }

    FlowerNode* cur = this->head;
    while (cur != NULL) {
        std::cout << cur->f.printFlower() << std::endl;
        cur = cur->next;
    }
}

void FlowerList::listFeatures(std::string flowerName) const {
    Flower* f;
    if (retrieve(flowerName, &f) == true) {
        std::cout << f->printFlower() << std::endl;
    } else {
        std::cout << flowerName << " isn't found in library." << std::endl;
    }
}

std::string FlowerList::findFlowers(std::string feature) const {
    std::string result = feature + " flowers: ";
    FlowerNode* cur = this->head;
    while (cur != NULL) {
        if (cur->f.findFeature(feature) == true) {
            result += cur->f.getFlowerName() + ", ";
        }
        cur = cur->next;
    }

    if (result.length() == (feature.length() + 10)) {
        result += "there is no such flower";
    } else {
        result.erase(result.end() - 2, result.end());
    }

    return result;
}
