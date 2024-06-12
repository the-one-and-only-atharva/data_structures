#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *arr;
};
int isFull(struct Queue *q)
{
    if(q->rear == q->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue *q)
{
    if(q->rear == q->front){
        return 1;
    }
    return 0;
}
void enqueue(struct Queue *q, int val)
{
    if(isFull(q)){
        printf("Queue is Full\n");
    }
    else{
        q->arr;
        q->arr[q->rear];
        printf("Enqueued element: %d\n",val);
    }
}

int dequeue(struct Queue *q)
{
    int a = -1;
    if(isEmpty(q)){
        printf("Queue is empty");
    }
    else{
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}
int main()
{
    struct Queue q;
    q.size = 4;
    q.front = q.rear = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));
}