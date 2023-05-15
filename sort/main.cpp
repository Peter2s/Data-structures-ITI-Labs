#include <iostream>

using namespace std;

//pivot from start
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int i = end+1;
    for (int j = end; j > start ; j--) {
        if (arr[j] > pivot) {
            i--;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i -1], arr[start]);
    return i-1;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end) {
        int pivotintdex = partition(arr, start, end);
        quickSort(arr, start, pivotintdex - 1);
        quickSort(arr, pivotintdex + 1, end);
    }
}


void insertSort(int* arr, int size)
{
    int i ;
    for (i = 1 ; i < size ; i++ )
    {
        int j = i ;                         // 0  1  2
        while (j > 0  && arr[j] < arr[j-1]) // 60 40 30 70
        {
            swap(arr[j], arr[j-1]) ;
            j-- ;
        }
    }
}
void printArray(int* arr,int size){
    for(int i =0 ; i<size;i++){
        cout<<arr[i]<<"\t";
    }
}
int main()
{
    int arr[] = {10,9,4,5,1};
    //insertSort(arr,5);
    quickSort(arr,0,4);
    printArray(arr,5);
}
