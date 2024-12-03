#include "pqNode.hpp"

int PQNode::getValue() const {
    return value;
}

int PQNode::getVertex() const {
    return vertex;
}

PQNode *PQNode::getNext() {
    return next;
}

void PQNode::setNext(
    PQNode *node
) {
    next = node;
}
