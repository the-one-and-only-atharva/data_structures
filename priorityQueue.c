#include <stdio.h>
#include <stdlib.h>

struct Node {
    int priority;
    int data;
    struct Node *next;
};

void insert(struct Node **head, int priority, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->priority = priority;
    new_node->next = NULL;

    if (*head == NULL || (*head)->priority > priority) {
        new_node->next = *head;
        *head = new_node;
    } else {
        struct Node *ptr = *head;
        while (ptr->next != NULL && ptr->next->priority < priority) {
            ptr = ptr->next;
        }
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
}

void delete(struct Node **head) {
    if (*head == NULL) {
        printf("Priority Queue is empty.\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void print_priority_queue(struct Node *head) {
    if (head == NULL) {
        printf("Priority Queue is empty.\n");
        return;
    }
    printf("Data\t\tPriority\n");
    while (head != NULL) {
        printf("%d\t\t%d\n", head->data, head->priority);
        head = head->next;
    }
}

int main() {
    struct Node *head = NULL;
    insert(&head, 10, 5);
    insert(&head, 20, 3);
    insert(&head, 15, 7);
    insert(&head, 25, 2);
    print_priority_queue(head);
    delete(&head);
    print_priority_queue(head);
    return 0;
}