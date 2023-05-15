#include <iostream>

using namespace std;
 int sumArray(int* arr,int size){
        if(size ==0 )
            return 0;
       return (sumArray(arr, size - 1) + arr[size - 1]);
    }
 void printArry(int* arr,int size){
    if(size == 0) {
        cout << arr[0]<<"\n";
        return;
    }
    cout << arr[size-1]<<"\n";
    printArry(arr,size-1);
    }
int main()
{
    int arr[5]={1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<sumArray(arr,size)<<endl;
    printArry(arr,size);

    return 0;
}
