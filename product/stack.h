#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define OK 1
#define NOK 0
typedef struct NODE
{
    struct NODE *next = 0;
    void *_obj;
    NODE(void *obj, size_t objsize)
    {
        _obj = operator new(objsize);
        _obj = obj;
    }
} NODE;
class Stack
{
private:
    size_t objsize;
    int numelem;

public:
    NODE *node;

    Stack(size_t objsize)
    {
        // this->numelem = numelem;
        this->objsize = objsize;
        this->node = NULL;
        this->numelem = 0;
    };
    ~Stack();
    int push(void *obj);
    int pop(void *obj);
    int destroy();
    int nofelem();
    int isEmpty();
    void printList();
};
#endif