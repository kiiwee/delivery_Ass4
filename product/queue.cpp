#include "queue.h"

#include <stdio.h>

#include <iostream>
using namespace std;
Queue::Queue(size_t objsize)
{
  this->objsize = objsize;
  this->in = new Stack(objsize);
  this->out = new Stack(objsize);
}
Queue::~Queue()
{
  this->destroy();
}
void Queue::enqueue(void *obj) { this->in->push(obj); }

void Queue::dequeue(void *obj)
{
  printQueue();
  if (this->out->isEmpty())
  {

    while (!this->in->isEmpty())
    {
      void *a = operator new(this->objsize);
      this->in->pop(a);
      this->out->push(a);
      a = NULL;
      operator delete(a);
    }
  }

  this->out->pop(obj);
}
void Queue::printQueue()
{
  printf("In stack: \n");
  this->in->printList();
  printf("Out stack: \n");
  this->out->printList();
}
int Queue::destroy()
{
  if (!this->in->isEmpty() || !this->out->isEmpty())
  {
    this->in->~Stack();
    this->out->~Stack();
    return OK;
  }

  return NOK;
}
