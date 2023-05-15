#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int data;
    Node* next;
    Node(int _data=0)
    {
        data=_data;
        next=NULL;
    }
};

#endif // NODE_H
