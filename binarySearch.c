#include<stdio.h>
#include<stdlib.h>

int bs(int arr[], int start, int end, int x)
{
    if(end>=start){
        int mid = start + (end-start)/2;
        if(arr[mid] == x){
            return mid;
        }
        else if(arr[mid] > x){
            return bs(arr, start, mid -1, x);
        }
        else if(arr[mid] < x){
            return bs(arr, mid+1, end, x);
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 11;
    int result = bs(arr, 1, 10, 11);
    if(result == -1){
        printf("element not in array");
    }
}