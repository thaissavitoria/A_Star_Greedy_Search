#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "PriorityQueue/pqNode.hpp"

class PriorityQueue {
public:
    PriorityQueue();

    ~PriorityQueue() {
        while (!Empty()) {
            Dequeue();
        }
    }

    PQNode *Front();

    void Enqueue(int vertex, int value);

    void Dequeue();

    bool Empty() const;

    int Size() const;

    size_t GetMemoriaTotalUsada() const { return picoMemoriaUsada; }
private:
    PQNode *front;

    size_t picoMemoriaUsada = 0;
    size_t memoriaUsada = 0;
    size_t size = 0;
};

#endif
