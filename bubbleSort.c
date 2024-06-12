#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int *arr, int n)
{
    int flag = 0;
    for (int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                int flag = 1;
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
        if(flag == 0){
            return;
        }
    }
}