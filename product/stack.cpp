#include "stack.h"

#include <stdio.h>
#include <string.h>

Stack::~Stack()
{
    this->destroy();
}
int Stack::push(void *obj)
{

    if (this->node == NULL)
    {
        this->node = new NODE(obj, this->objsize);
        return OK;
    }
    else
    {
        NODE *temp = new NODE(obj, this->objsize);
        temp->next = this->node;
        this->node = temp;
        return OK;
    }
    return NOK;
}

int Stack::pop(void *obj)

{

    if (this->isEmpty())
        return NOK;

    NODE *temp = this->node;
    memcpy(obj, temp->_obj, this->objsize);
    this->node = this->node->next;

    delete (temp);
    return OK;
}
int Stack::destroy()
{
    if (!this->isEmpty())
    {

        NODE *temp = this->node;
        NODE *prev = NULL;

        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
            delete (prev);
            // temp = temp->next;
            // delete (prev);
        }
        delete (temp);
        this->node = NULL;
        return OK;
    }
    return NOK;
    // if (!this->isEmpty())
    // {

    //     NODE *temp = this->node;
    //     NODE *prev = NULL;

    //     while (temp->next != NULL)
    //     {
    //         prev = temp;
    //         temp = temp->next;
    //         delete (prev);
    //     }
    //     delete (temp);
    //     this->node = NULL;
    //     return OK;
    // }
    // return NOK;
}
int Stack::nofelem()
{
    int numelem = 0;
    if (this->node == NULL)
    {
        return numelem;
    }
    else
    {
        numelem++;
        NODE *temp = this->node;
        while (temp->next != NULL)
        {
            temp = temp->next;
            numelem++;
        }
        return numelem;
    }
}
int Stack::isEmpty()
{
    if (this->node != NULL)
    {
        return NOK;
    }
    else
        return OK;
}
void Stack::printList()
{
    NODE *temp = this->node;
    int i = 0;
    while (temp != NULL)
    {
        printf("Ellement Nr: %d, val= %d \n", i, *static_cast<int *>(temp->_obj));
        i++;
        temp = temp->next;
    }
}
