#include <iostream>
#include <string.h>

using namespace std;

class CircularQueuee
{
    int *arr;
    int rear;
    int front;
    int size;
public:
    CircularQueuee(int _size=5)
    {
        rear=front=-1;
        size=_size;
        arr=new int[size];
    }
    CircularQueuee(const CircularQueuee& q){
        rear = q.rear;
        front = q.front;
        size = q.size;
        arr = new int[size];
        for(int i =0;i<size;i++){
            arr[i]=q.arr[i];
        }
    }
    int enqueue(int item)
    {
        if(isFull() == 1)
            return 0;

        if(isEmpty()==1)
            front=rear=0;
        else if(rear == size-1)
            rear=0;
        else
            rear++;

        arr[rear]=item;
        return 1;
    }

    int dequeue(int& item)
    {
        if(isEmpty()==1)
            return 0;
        item = arr[front];

        if(front==rear)
            front=rear=-1;
        else if(front == size-1)
            front=0;
        else{
            front++;
        }
        return 1;
    }
    int isEmpty()
    {
        if(rear==-1) return 1;
        else return 0;
    }

    int isFull()
    {
        if(rear==size-1&&front==0 || rear == front-1) return 1;
        else return 0;
    }
    ~CircularQueuee(){
        delete arr;
    }
};

int main()
{
        int num,num2,num3,num4;
        CircularQueuee q(3);
        CircularQueuee q2;
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
        q2=q;
        q2.dequeue(num);
        q2.dequeue(num2);
        q2.dequeue(num3);
        q2.dequeue(num4);

        cout <<num<<endl;
        cout <<num2<<endl;
        cout <<num3<<endl;
        cout <<num4<<endl;



    return 0;
}
