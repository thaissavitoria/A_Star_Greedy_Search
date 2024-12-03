#ifndef PQNODE_H
#define PQNODE_H

#include <iostream>

class PQNode {
public:
    PQNode(int v, int va, PQNode *n = nullptr) : vertex(v), value(va), next(n) { }

    int getValue() const;
    int getVertex() const;
    PQNode *getNext();
    void setNext(PQNode *node);
private:
    int vertex;
    int value;
    PQNode *next;
};

#endif