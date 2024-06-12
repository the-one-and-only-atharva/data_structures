#include<stdio.h>
#include<stdlib.h>
void selectionSort(int arr[], int n)
{
    for(int i=0; i<n; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
int main()
{
    int arr[] = {1,3,2,5,9,8,4,7,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,n);
    for(int i=0; i<n; i++){
        printf("%d", arr[i]);
    }
}