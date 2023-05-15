#include <iostream>
#include <string.h>

using namespace std;
int binarySearch(int* arr,int size,int key)
{
    int start = 0;
    int end = size-1;
    int middle;
    if(key < arr[start] || key > arr[end])
        return -1;
    while(start<=end)
    {
        middle=(start+end)/2;
        if(key==arr[middle])
            return middle;
        else if(key>arr[middle])
        {
            start=middle+1;
        }
        else
        {
            end=middle-1;
        }
    }
    return -1;

}
int binarySearch(char** arr,int size,char* key)
{
    int start = 0;
    int end = size-1;
    int middle;
    while(start<=end)
    {
        middle=(start + end)/2;
        if(strcmp(key,arr[middle]) == 0 )
            return middle;
        else if(strcmp(key,arr[middle])>0)
            start=middle+1;
        else
            end=middle-1;
    }
    return -1;

}
int main()
{
    int myArr[5]={10,20,30,40,50};
    int res = binarySearch(myArr,5,40);
    cout << res<<endl;
    char** myStirngArr = new char*[3];
    myStirngArr[0]="ab";
    myStirngArr[1]="cd";
    myStirngArr[2]="zf";
    int resString =  binarySearch(myStirngArr,3,"zf");
    cout <<resString<<endl;

    return 0;
}
