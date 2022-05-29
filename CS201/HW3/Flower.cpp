/**
 * Flower class implementation file for the CS201's HW3 assignment.
 * Author: Berk Cakar - 22003021
 */

#include "Flower.h"

Flower::Flower() {
    this->size = 0;
    this->flowerName = "";
    this->head = NULL;
}

Flower::Flower(std::string flowerName) {
    this->size = 0;
    this->flowerName = flowerName;
    this->head = NULL;
}

Flower::Flower(const Flower& aFlower) : size(aFlower.size), flowerName(aFlower.flowerName) {
    if (aFlower.head == NULL || aFlower.size == 0) {
        this->size = 0;
        this->head = NULL;
    } else {
        FeatureNode* cur2 = aFlower.head;

        this->head = new FeatureNode();
        this->head->feature = cur2->feature;
        this->head->next = NULL;

        FeatureNode* cur = this->head;
        cur2 = cur2->next;

        while (cur2 != NULL) {
            cur->next = new FeatureNode();
            cur = cur->next;
            cur->feature = cur2->feature;
            cur->next = NULL;
            cur2 = cur2->next;
        }
    }
}

Flower::~Flower() {
    FeatureNode* cur = this->head;
    while (cur != NULL) {
        FeatureNode* next = cur->next;
        delete cur;
        cur = next;
    }
    this->size = 0;
    this->head = NULL;
}

Flower& Flower::operator=(const Flower& aFlower) {
    if (this != &aFlower) {
        FeatureNode* cur = this->head;
        while (cur != NULL) {
            FeatureNode* next = cur->next;
            delete cur;
            cur = next;
        }

        this->size = aFlower.size;
        this->flowerName = aFlower.flowerName;

        if (aFlower.head == NULL || aFlower.size == 0) {
            this->size = 0;
            this->head = NULL;
        } else {
            FeatureNode* cur2 = aFlower.head;

            this->head = new FeatureNode();
            this->head->feature = cur2->feature;
            this->head->next = NULL;

            FeatureNode* cur = this->head;
            cur2 = cur2->next;

            while (cur2 != NULL) {
                cur->next = new FeatureNode();
                cur = cur->next;
                cur->feature = cur2->feature;
                cur->next = NULL;
                cur2 = cur2->next;
            }
        }
    }

    return *this;
}

bool Flower::isEmpty() const {
    if (this->size == 0) {
        return true;
    }

    return false;
}

int Flower::getLength() const { return this->size; }

bool Flower::add(std::string feature) {
    FeatureNode* node = new FeatureNode();
    node->feature = feature;
    node->next = NULL;

    FeatureNode *prev, *cur;
    if (this->head == NULL) {
        this->head = node;
    } else {
        prev = NULL;
        cur = this->head;
        while (cur != NULL && node->feature.compare(cur->feature) >= 0) {
            if (cur->feature == feature) {
                std::cout << feature << " already exists in " << this->flowerName << std::endl;
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
    std::cout << feature << " is added into " << this->flowerName << std::endl;
    return true;
}

bool Flower::remove(std::string feature) {
    FeatureNode *prev, *cur;
    prev = NULL;
    cur = this->head;
    while (cur != NULL && cur->feature != feature) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL) {
        std::cout << feature << " doesn't exist in " << this->flowerName << std::endl;
        return false;
    } else {
        if (prev == NULL) {
            this->head = cur->next;
        } else {
            prev->next = cur->next;
        }
        delete cur;
        this->size--;
        std::cout << feature << " is removed from " << this->flowerName << std::endl;
        return true;
    }
}

std::string Flower::printFlower() const {
    std::string result = this->flowerName + ": ";
    FeatureNode* cur = this->head;
    while (cur != NULL) {
        result += cur->feature + ", ";
        cur = cur->next;
    }

    if (result.length() == (this->flowerName.length() + 2)) {
        result += "No feature";
    } else {
        result.erase(result.end() - 2, result.end());
    }

    return result;
}

std::string Flower::getFlowerName() const { return this->flowerName; }

void Flower::setFlowerName(std::string flowerName) { this->flowerName = flowerName; }

bool Flower::findFeature(std::string feature) const {
    FeatureNode* cur = this->head;
    while (cur != NULL) {
        if (cur->feature == feature) {
            return true;
        }
        cur = cur->next;
    }
    return false;
}
