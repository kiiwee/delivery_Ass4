
#ifndef QUEUE_H
#define QUEUE_H
#include "stack.h"
class Queue
{
private:
    Stack *in;
    Stack *out;
    size_t objsize;

public:
    Queue(size_t objsize);
    ~Queue();
    void enqueue(void *obj);
    void dequeue(void *obj);
    int destroy();
    void printQueue();
};
#endif