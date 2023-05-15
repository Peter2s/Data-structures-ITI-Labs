#include <iostream>
#include <LinkedList.h>

using namespace std;
class LinkedListQueue{
LinkedList List;
public:
LinkedListQueue(){}
 void enqueu(int _id){
    List.append(_id);
 }
 int dequeue(int& data){
    if(List.getHead(data)==0)
        return 0;

    List.getHead(data);
    List.deleteHead();
    return 1;
 }

};
int main()
{
    int num1,num2,num3;
    LinkedListQueue q;
    q.enqueu(10);
    q.enqueu(20);
    q.dequeue(num1);
    q.dequeue(num2);
    q.dequeue(num3);
    cout << num1 <<"\n"<<endl;
    cout << num2 <<"\n"<<endl;
    cout << num3 <<"\n"<<endl;

    return 0;
}
