#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	int head;
	struct node *next;
}head;

int main(){
	head = (struct *node)malloc(sizeof(struct node));
	head -> data = 10;
	head -> next = NULL;
	
	struct node *current = (struct *node)malloc(sizeof(struct node));
	current -> data = 35;
	current -> next = NULL;
	return 0;
}
