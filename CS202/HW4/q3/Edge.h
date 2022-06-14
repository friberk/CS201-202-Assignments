/*
 * Title: CS202 Spring 2022
 * Author: Berk Çakar
 * ID: 22003021
 * Section: 3
 * Assignment: 4
 * Description: Edge class header file for CS202's HW4 assignment.
 */

#ifndef __EDGE_H__
#define __EDGE_H__

class Edge {
public:
    Edge();
    Edge(const int& destination, const int& weight);
    Edge(const Edge& otherEdge);
    Edge& operator=(const Edge& otherEdge);

    int getDestination() const;
    int getWeight() const;

    void setDestination(const int& destination);
    void setWeight(const int& weight);

private:
    int destination;
    int weight;
};

#endif // __EDGE_H__
