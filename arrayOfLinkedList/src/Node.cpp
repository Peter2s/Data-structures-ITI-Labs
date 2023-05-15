#include "Node.h"

Node::Node(int _id,char* _name)
    {
        id=_id;
        strcpy(name,_name);
        next=prev=NULL;
    }
