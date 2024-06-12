#include<stdio.h>
#include<stdlib.h>
int ls(int arr[], int n, int x)
{
int i;
for (i = 0; i < n; i++){
    if (arr[i] == x){
        printf("%d ", x);
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    ls(arr, n, 10);
    return 0;
}