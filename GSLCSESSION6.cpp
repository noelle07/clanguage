#include <stdio.h>
#include <stdlib.h>

// structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// global variable to keep track of the top of the stack
struct Node* top = NULL;

// function to push an element onto the stack
void push(int data) {
    // create a new node and allocate memory for it
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // check if memory allocation was successful
    if (newNode == NULL) {
        printf("Error: unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    
    // set the data and next fields of the new node
    newNode->data = data;
    newNode->next = top;
    
    // update the top of the stack to point to the new node
    top = newNode;
}

// function to pop an element from the stack
int pop() {
    // check if the stack is empty
    if (top == NULL) {
        printf("Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }
    
    // get the data from the top node
    int data = top->data;
    
    // update the top of the stack to point to the next node
    struct Node* temp = top;
    top = top->next;
    
    // free the memory allocated to the old top node
    free(temp);
    
    // return the data from the popped node
    return data;
}

// function to peek at the top element of the stack
int peek() {
    // check if the stack is empty
    if (top == NULL) {
        printf("Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }
    
    // return the data from the top node
    return top->data;
}

int main() {
    // push some elements onto the stack
    push(1);
    push(2);
    push(3);
    
    // peek at the top element of the stack
    printf("Top element is: %d\n", peek());
    
    // pop some elements from the stack
    printf("Elements popped: %d %d %d\n", pop(), pop(), pop());
    
    return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//
//#define STACK_SIZE 5

//int stack[STACK_SIZE];
//int top = -1;
//
//void push(int data) {
//    if (top == STACK_SIZE - 1) {
//        printf("Stack overflow\n");
//        exit(EXIT_FAILURE);
//    }
//    top++;
//    stack[top] = data;
//}
//
//int pop() {
//    if (top == -1) {
//        printf("Stack underflow\n");
//        exit(EXIT_FAILURE);
//    }
//    int data = stack[top];
//    top--;
//    return data;
//}
//
//int main() {
//    push(10);
//    push(20);
//    push(30);
//    push(40);
//    push(50);
//
//    printf("Fill out the stack before deletion:\n");
//    for (int i = 0; i <= top; i++) {
//        printf("%d ", stack[i]);
//    }
//    printf("\n");
//
//    pop();
//
//    printf("Fill in the stack after deletion:\n");
//    for (int i = 0; i <= top; i++) {
//        printf("%d ", stack[i]);
//    }
//    printf("\n");
//
//    return 0;
//}

