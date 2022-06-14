/*
 * Title: CS202 Spring 2022
 * Author: Berk Çakar
 * ID: 22003021
 * Section: 3
 * Assignment: 4
 * Description: Vertex class implementation file for CS202's HW4 assignment.
 */

#include "Vertex.h"

Vertex::Vertex() {
    id = -1; // Invalid ID
}

Vertex::Vertex(const int& id) {
    this->id = id;
}

Vertex::Vertex(const Vertex& otherVertex) {
    this->id = otherVertex.id;
    this->edges = otherVertex.edges;
}

Vertex& Vertex::operator=(const Vertex& otherVertex) {
    if (this != &otherVertex) {
        this->id = otherVertex.id;
        this->edges = otherVertex.edges;
    }

    return *this;
}

int Vertex::getId() const {
    return this->id;
}

void Vertex::setId(const int& id) {
    if (id >= 0) {
        this->id = id;
    }
}

List<Edge>& Vertex::getEdges() {
    return this->edges;
}

void Vertex::setEdges(const List<Edge>& edges) {
    this->edges = edges;
}
