#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int array[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapify(array, n, largest);
    }
}

void heapSort(int array[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    for (i = n - 1; i >= 0; i--) {
        swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}

int main() {
    int data[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(data) / sizeof(data[0]);
    int i;

    printf("Unsorted array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", data[i]);
    printf("\n");

    heapSort(data, n);

    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", data[i]);
    printf("\n");

    return 0;
}