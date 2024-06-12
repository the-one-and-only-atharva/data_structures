#include<stdio.h>
#include<stdlib.h>
void insertionSort(int *arr, int n)
{
    for(int i=1;i<n;i++){
        int temp = arr[i];
        int j = i - 1;
        while((temp < arr[j]) && (j>=0)){
            arr[j+1] = arr [j];
            j--;
        }
        arr[j+1] = temp;
    }
}
int main()
{
    int arr[] = {500,1,50,23,76};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    for(int i=0;i<n;i++){
        printf(" %d\t", arr[i]);
    }
    return 0;
}