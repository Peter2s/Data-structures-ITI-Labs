#include <iostream>
#include <Node.h>

using namespace std;

class Stack
{
    Node* top;
public:
    Stack(){
        top = NULL;
    }
    int isEmpty(){
        if(top == NULL)return 1;
        else return 0;
    }
    void Push(int number){
        Node* newNode = new Node(number);
        if(isEmpty() == 1){
            top = newNode;
        }
        else {
            newNode->next = top;
            top = newNode;
        }
    }
    void Display(){
        Node* node = top;
        while(node!=NULL){
            cout<< node->data<<"\t"<<endl;
            node=node->next;
        }
    }

    int Pop(int& data){
        if(isEmpty()) return 0;
        Node* nodeTodelete = top;
        top=top->next;
         data = nodeTodelete->data;
        return 1;
        delete nodeTodelete;
    }
    int Peek(){
        return top->data;
    }
    ~Stack(){
        delete top;
    }

};

int main()
{   int num1,num2,num3,num4;
    Stack s;
    Stack s1;

    s.Push(10);
    s.Push(20);
    s.Push(30);
    s1=s;
    s1.Pop(num1);
    s1.Pop(num2);
    s1.Pop(num3);
    s1.Push(50);
    s1.Pop(num4);
    cout <<num1<<endl;
    cout <<num2<<endl;
    cout <<num3<<endl;
    cout <<num4<<endl;


    return 0;
}
