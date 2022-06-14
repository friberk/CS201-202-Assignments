/*
 * Title: CS202 Spring 2022
 * Author: Berk Çakar
 * ID: 22003021
 * Section: 3
 * Assignment: 4
 * Description: Graph class implementation file for CS202's HW4 assignment.
 */

#include "Graph.h"
#include "Heap.h"
#include "Stack.h"
#include <climits>
#include <iostream>
#include <sstream>

Graph::Graph() {
    this->size = 0;
    this->vertices = NULL;
}

Graph::Graph(const int& size) {
    this->size = size;
    this->vertices = new Vertex[size];

    for (int i = 0; i < size; i++) {
        this->vertices[i].setId(i);
    }
}

Graph::Graph(const Graph& otherGraph) {
    this->size = otherGraph.size;
    if (this->size == 0 || otherGraph.vertices == NULL) {
        this->vertices = NULL;
    } else {
        this->vertices = new Vertex[this->size];

        for (int i = 0; i < this->size; i++) {
            this->vertices[i] = otherGraph.vertices[i];
        }
    }
}

Graph& Graph::operator=(const Graph& otherGraph) {
    if (this != &otherGraph) {
        if (this->vertices != NULL || this->size != 0) {
            delete[] this->vertices;
            this->vertices = NULL;
        }

        if (otherGraph.vertices == NULL || otherGraph.size == 0) {
            this->vertices = NULL;
            this->size = 0;
        } else {
            this->size = otherGraph.size;
            this->vertices = new Vertex[this->size];

            for (int i = 0; i < this->size; i++) {
                this->vertices[i] = otherGraph.vertices[i];
            }
        }
    }

    return *this;
}

Graph::~Graph() {
    if (this->vertices != NULL || this->size != 0) {
        delete[] this->vertices;
    }
    this->vertices = NULL;
}

void Graph::addEdge(const int& from, const int& to, const int& weight, const bool& silent) {
    if (from < 0 || from >= this->size || to < 0 || to >= this->size || weight < 0) {
        if (silent == false) {
            std::cout << "Invalid parameter(s)." << std::endl;
        }
        return;
    }

    if (from == to) {
        if (silent == false) {
            std::cout << "Self-loops are not allowed." << std::endl;
        }
        return;
    }

    Edge edge1(to, weight);
    Edge edge2(from, weight);

    this->vertices[from].getEdges().insert(this->vertices[from].getEdges().getLength() + 1, edge1);
    this->vertices[to].getEdges().insert(this->vertices[to].getEdges().getLength() + 1, edge2);

    if (silent == false) {
        std::cout << "Inserted a new flight between " << from << " and " << to << "." << std::endl;
        std::cout << "  The number of flights from " << from << " is "
                  << this->vertices[from].getEdges().getLength() << "." << std::endl;
    }
}

void Graph::listEdges(const int& vertexId) {
    if (vertexId < 0 || vertexId >= this->size) {
        std::cout << "Invalid vertex ID." << std::endl;
        return;
    }

    std::cout << "List of flights from " << vertexId << ":" << std::endl;
    List<Edge> edges = this->vertices[vertexId].getEdges();

    if (edges.isEmpty() == true) {
        std::cout << "  There are no flights from " << vertexId << "." << std::endl;
    } else {
        for (int i = edges.getLength(); i >= 1; i--) {
            Edge edge;
            edges.retrieve(i, edge);
            std::cout << "  " << vertexId << " to " << edge.getDestination()
                      << " with a duration of " << edge.getWeight() << "." << std::endl;
        }
        std::cout << "  The number of flights is " << edges.getLength() << "." << std::endl;
    }
}

void Graph::shortestPath(const int& from, const int& to) {
    if (from < 0 || from >= this->size || to < 0 || to >= this->size) {
        std::cout << "Invalid vertex ID." << std::endl;
        return;
    }

    if (this->size <= 0) {
        std::cout << "The graph is empty." << std::endl;
        return;
    }

    int* distances = new int[this->size];
    int* previousVertices = new int[this->size];

    dijkstraAlgorithm(from, distances, previousVertices);

    if (distances[to] == INT_MAX) {
        std::cout << "No paths from " << from << " to " << to << "." << std::endl;

        if (distances != NULL) {
            delete[] distances;
        }
        if (previousVertices != NULL) {
            delete[] previousVertices;
        }

        return;
    }

    std::cout << "The shortest path from " << from << " to " << to << ":" << std::endl;

    Stack<std::string> route;
    int k = INT_MIN;
    int tempTo = to;
    while (k != from) {
        std::stringstream ss;
        if (tempTo == to) {
            ss << "  Total flight duration of path: " << distances[to];
            route.push(ss.str());
            ss.str("");
        }

        k = previousVertices[tempTo];
        ss << "  " << k << " to " << tempTo << " with a duration "
           << distances[tempTo] - distances[k];
        tempTo = k;

        route.push(ss.str());
        ss.str("");
    }

    while (!route.isEmpty()) {
        std::string s = "";
        route.getTop(s);
        std::cout << s << std::endl;
        route.pop();
    }

    if (distances != NULL) {
        delete[] distances;
    }
    if (previousVertices != NULL) {
        delete[] previousVertices;
    }
}

void Graph::dijkstraAlgorithm(const int& startVertexId, int* distances, int* previousVertices) {
    Heap heap;

    distances[startVertexId] = 0;
    for (int i = 0; i < this->size; i++) {
        if (i != startVertexId) {
            distances[i] = INT_MAX;
            previousVertices[i] = -1;
        }

        else {
            priorityNode node;
            node.key = i;
            node.priority = distances[i];
            heap.heapInsert(node);
        }
    }

    while (heap.heapIsEmpty() == false) {
        priorityNode node;
        heap.heapDelete(node);

        for (int i = 1; i <= this->vertices[node.key].getEdges().getLength(); i++) {
            Edge e;
            this->vertices[node.key].getEdges().retrieve(i, e);
            int k = distances[node.key] + e.getWeight();

            if (k < distances[e.getDestination()]) {
                distances[e.getDestination()] = k;
                previousVertices[e.getDestination()] = node.key;

                priorityNode node;
                node.key = e.getDestination();
                node.priority = k;
                heap.heapInsert(node);
            }
        }
    }
}

void Graph::minimizeCosts() {
    if (this->size == 0) {
        std::cout << "The graph is empty." << std::endl;
        return;
    }

    bool allEmpty = true;
    for (int i = 0; i < this->size && allEmpty; i++) {
        if (this->vertices[i].getEdges().isEmpty() == false) {
            allEmpty = false;
            break;
        }
    }

    if (allEmpty == true) {
        std::cout << "There are no edges in the graph. Cannot determine a minimum spanning tree."
                  << std::endl;
        return;
    }

    primsNode* results = new primsNode[this->size];
    int* distances = new int[this->size];
    bool* visited = new bool[this->size];

    for (int i = 0; i < this->size; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
        results[i].parentId = -1;
        results[i].weight = 0;
    }

    primsAlgorithm(results, distances, visited);

    int oldCost = 0;
    for (int i = 0; i < this->size; i++) {
        for (int j = 1; j <= this->vertices[i].getEdges().getLength(); j++) {
            Edge e;
            this->vertices[i].getEdges().retrieve(j, e);
            oldCost += e.getWeight();
        }
    }
    std::cout << "Total cost of operations before minimization: " << oldCost / 2 << std::endl;

    int minimizedCost = 0;
    for (int i = 0; i < this->size; i++) {
        minimizedCost = minimizedCost + results[i].weight;
    }
    std::cout << "Total cost of operations after minimization: " << minimizedCost << std::endl;

    Graph newGraph(this->size);
    for (int i = 1; i < this->size; i++) {
        newGraph.addEdge(results[i].parentId, i, results[i].weight, true);
    }
    *this = newGraph;

    if (results != NULL) {
        delete[] results;
    }
    if (distances != NULL) {
        delete[] distances;
    }
    if (visited != NULL) {
        delete[] visited;
    }
}

void Graph::primsAlgorithm(primsNode* results, int* distances, bool* visited) const {
    Heap heap;
    for (int j = 0; j < this->size; j++) {
        if (j == 0) {
            priorityNode node;
            node.key = j;
            node.priority = 0;
            heap.heapInsert(node);
        }

        else {
            priorityNode node;
            node.key = j;
            node.priority = INT_MAX;
            heap.heapInsert(node);
        }
    }

    while (heap.heapIsEmpty() == false) {
        priorityNode node;
        heap.heapDelete(node);
        visited[node.key] = true;
        for (int i = 1; i <= this->vertices[node.key].getEdges().getLength(); i++) {
            Edge edge;
            this->vertices[node.key].getEdges().retrieve(i, edge);
            if (!visited[edge.getDestination()]) {
                int u = edge.getDestination();
                int weight = edge.getWeight();
                if (distances[u] > weight) {
                    distances[u] = weight;
                    heap.decreaseKey(u, weight);
                    results[u].parentId = node.key;
                    results[u].weight = weight;
                }
            }
        }
    }
}
