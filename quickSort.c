#include<stdio.h>
#include<stdlib.h>

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start -1;

    for(int j=start; j<=end; j++){
        if(arr[j] < pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;
    return i;
}

void quickSort(int arr[], int start, int end)
{
    if(end <= start) return;
	int pivot = partition(arr, start, end);
	quickSort(arr, start, pivot - 1);
	quickSort(arr, pivot + 1, end);	
}

int main()
{
    int arr[] = {3,2,1,7,6,5,9,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, size-1);
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}