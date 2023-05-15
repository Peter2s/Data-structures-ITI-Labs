#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <Node.h>

using namespace std;
class LinkedList
{
    Node *head;
    Node *tail;
public:
    LinkedList()
    {
        head=tail=NULL;
    }
    void append(int id, char* name)
    {
        Node* node=new Node(id,name);
        if(head==NULL)
        {
            head=tail=node;
        }
        else
        {
            tail->next=node;
            node->prev=tail;
            tail=node;
        }
    }
    void display()
    {
        Node* current=head;
        while(current!=NULL)
        {
            cout <<"ID : "<<current->id<<",Name : "<<current->name<<"\n"<< endl;
            current=current->next;
        }
    }
    Node* get(int id)
    {
        Node* current=head;
        while(current!=NULL)
        {
            if(current->id==id)
            {
                return current;
                break;
            }
            current=current->next;
        }
        return NULL;
    }
    Node* get(char* name)
    {
        Node* current=head;
        while(current!=NULL)
        {
            if(!strcmp(current->name,name))
            {
                return current;
                break;
            }
            current=current->next;
        }
        return NULL;
    }
    int count()
    {
        Node* current=head;
        int totalCount = 0;
        while(current!=NULL)
        {
            totalCount++;
            current=current->next;
        }
        return totalCount;
    }
    int deleteNode(int id)
    {
        Node* node = get(id);
        deleteNode(node);
    }
    int deleteNode(char* name)
    {
        Node* node = get(name);
        deleteNode(node);
    }
    int insert(int prevId,int id,char* name)
    {
        Node* node = get(prevId);
        if(node==NULL)
            return 0;

        Node* newNode = new Node(id,name);
        if(node != tail)
        {
            newNode->next=node->next;
            node->next=newNode;
            newNode->next->prev=newNode;
            newNode->prev=node;
        }
        else
        {
            newNode->prev=node;
            node->next=newNode;
            tail=newNode;
        }
        return 1;
    }


private:
    int deleteNode(Node* node)
    {
        if(node == NULL)
            return 0;
        if(node == head)
        {
            if(node == tail)
                head = tail = NULL;
            else
            {
                head = head->next;
                head->prev = NULL;
            }
        }
        else if (node == tail)
        {
            tail = tail->prev;
            tail->next = NULL;
        }
        else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        delete node;
        return 1;
    }

};

#endif // LINKEDLIST_H
