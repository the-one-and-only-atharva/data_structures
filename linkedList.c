#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
}

struct node * insertAtStart(struct node *head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

struct node * insertAtEnd(struct node *head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    struct node *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = NULL;
    return head;
}

struct node * insertAtIndex(struct node *head, int data, int index)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    int i=0;
    while(i!=index-1){
        ptr = ptr->next;
        i++;
    }
    newNode->data = data;
    newNode->next = ptr->next;
    ptr->next = newNode;
    return head;
}

struct node * insertAfter(struct node *head, struct node* prevNode, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    return head;
}

struct node *deleteFirst(struct node *head){
    struct node *ptr =head;
    head = head->next;
    free(ptr);
    return head;
}

struct node *deleteEnd(struct node *head)
{
    struct node *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    free(ptr);
    return head;
}

struct node * deleteAtIndex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
    for(int i = 0; i < index-1; i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct node * deleteGiven(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head->next;
    while(q->data!=value && q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    head = insertAtStart(head, 0);
    head = insertAtEnd(head, 5);
    head = insertAtIndex(head, 6, 6);
    head = insertAfter(head, third, 69);
    //head = deleteFirst(head);
    //head = deleteEnd(head);
    //head = deleteAtIndex(head, 3);
    //head = deleteGiven(head, 69);

    linkedListTraversal(head);

    return 0;
}
