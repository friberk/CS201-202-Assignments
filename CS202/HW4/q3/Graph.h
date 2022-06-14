/*
 * Title: CS202 Spring 2022
 * Author: Berk Çakar
 * ID: 22003021
 * Section: 3
 * Assignment: 4
 * Description: Graph class header file for CS202's HW4 assignment.
 */

#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "Vertex.h"

class Graph {
public:
    Graph();
    Graph(const int& size);
    Graph(const Graph& otherGraph);
    Graph& operator=(const Graph& otherGraph);
    ~Graph();

    void addEdge(const int& from, const int& to, const int& weight, const bool& silent);
    void listEdges(const int& vertexId);

    void minimizeCosts();
    void shortestPath(const int& from, const int& to);

private:
    struct primsNode {
        int parentId;
        int weight;
    };

    void primsAlgorithm(primsNode* results, int* distances, bool* visited) const;
    void dijkstraAlgorithm(const int& startVertexId, int* distances, int* previousVertices);

    int size;
    Vertex* vertices;
};

#endif // __GRAPH_H__
