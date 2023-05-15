#ifndef NODE_H
#define NODE_H
#include <string.h>


class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int _data)
    {
        data=_data;
        next=prev=NULL;
    }
};

#endif // NODE_H
