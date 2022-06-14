/*
 * Title: CS202 Spring 2022
 * Author: Berk Çakar
 * ID: 22003021
 * Section: 3
 * Assignment: 4
 * Description: Vertex class header file for CS202's HW4 assignment.
 */

#ifndef __VERTEX_H__
#define __VERTEX_H__

#include "Edge.h"
#include "List.h"

class Vertex {
public:
    Vertex();
    Vertex(const int& id);
    Vertex(const Vertex& otherVertex);
    Vertex& operator=(const Vertex& otherVertex);

    int getId() const;
    void setId(const int& id);

    List<Edge>& getEdges();
    void setEdges(const List<Edge>& edges);

private:
    int id;
    List<Edge> edges;
};

#endif // __VERTEX_H__
