#include <stdio.h>
#include <stdlib.h>

// Doubly linked list node
typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} Node;

int main() {
    // Create the first node with value 5
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 5;
    head->prev = NULL;
    head->next = NULL;

    // Add the next elements sequentially at the end of the list
    Node *curr = head;
    Node *newNode;
    int data[] = {10, 15, 7, 20};
    int i;
    for (i = 0; i < sizeof(data) / sizeof(int); i++) {
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data[i];
        newNode->prev = curr;
        newNode->next = NULL;
        curr->next = newNode;
        curr = newNode;
    }

    // Traverse the doubly linked list and print its elements
    printf("Doubly linked list:\n");
    curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    // Free memory
    curr = head;
    while (curr != NULL) {
        newNode = curr->next;
        free(curr);
        curr = newNode;
    }

    return 0;
}


