#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int data){
	if(top == SIZE - 1){
		return;
	}
	top++;
	stack[top] = data;
}

int pop(){
	if(top == -1){
		exit(EXIT_FAILURE);
	}
	int data = stack[top];
	top--;
	return data;
}

int main(){
	push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    
    printf("Fill out the stack before deletion:\n");
    for(int i = 0; i<=top; i++){
    	printf("%d ", stack[i]);
	}
	printf("\n");
	
	pop();
	
	printf("Fill in the stack after deletion:\n");
    for(int i = 0; i<=top; i++){
    	printf("%d ", stack[i]);
	}
	printf("\n");
	
	return 0;
}
