#include "priorityQueue.hpp"
#include <iostream>

PriorityQueue::PriorityQueue() : front(nullptr) { }

bool PriorityQueue::Empty() const {
    return front == nullptr;
}

void PriorityQueue::Enqueue(int vertex, int value) {
    PQNode *newNode = new PQNode(vertex, value);
    memoriaUsada += sizeof(PQNode);

    if (memoriaUsada > picoMemoriaUsada) {
        picoMemoriaUsada = memoriaUsada;
    }

    if (Empty()) {
        newNode->setNext(front);
        front = newNode;
    } else if (value < front->getValue()) {
        newNode->setNext(front);
        front = newNode;
    } else {
        PQNode *atual = front;
        while (atual->getNext() && atual->getNext()->getValue() <= value) {
            atual = atual->getNext();
        }
        newNode->setNext(atual->getNext());
        atual->setNext(newNode);
    }

    size++;
}

void PriorityQueue::Dequeue() {
    if (Empty()) {
        return;
    }

    PQNode *temp = front;
    front = front->getNext();

    delete temp;
    memoriaUsada -= sizeof(PQNode);
    size--;
}

PQNode *PriorityQueue::Front() {
    return front;
}

int PriorityQueue::Size() const {
    return size;
}

