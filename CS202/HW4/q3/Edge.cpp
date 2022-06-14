/*
 * Title: CS202 Spring 2022
 * Author: Berk Çakar
 * ID: 22003021
 * Section: 3
 * Assignment: 4
 * Description: Edge class implementation file for CS202's HW4 assignment.
 */

#include "Edge.h"

Edge::Edge() {
    this->destination = -1;
    this->weight = -1; // Invalid state
}

Edge::Edge(const int& destination, const int& weight) {
    if (destination >= 0) {
        this->destination = destination;
    } else {
        this->destination = -1;
    }

    if (weight >= 0) {
        this->weight = weight;
    } else {
        this->weight = -1;
    }
}

Edge::Edge(const Edge& otherEdge) : destination(otherEdge.destination), weight(otherEdge.weight) {}

Edge& Edge::operator=(const Edge& otherEdge) {
    if (this != &otherEdge) {
        this->destination = otherEdge.destination;
        this->weight = otherEdge.weight;
    }

    return *this;
}

int Edge::getDestination() const { return this->destination; }

int Edge::getWeight() const { return this->weight; }

void Edge::setDestination(const int& destination) {
    if (destination >= 0) {
        this->destination = destination;
    }
}

void Edge::setWeight(const int& weight) {
    if (weight >= 0) {
        this->weight = weight;
    }
}
