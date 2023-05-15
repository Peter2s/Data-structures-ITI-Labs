#ifndef NODE_H
#define NODE_H


class Node
{
public:
    int id;
    char name[50];
    Node* next;
    Node* prev;

    Node(int _id,char* _name)
    {
        id=_id;
        strcpy(name,_name);
        next=prev=NULL;
    }
};

#endif // NODE_H
