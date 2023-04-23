#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	
}*head;

void viewLinkedList()
{
	struct node *temp;
	temp = head;
    printf("%d ", temp->data);
	
	while(temp->next != NULL)
	{
		temp = temp->next;
		printf("%d ", temp->data);		
	}
	printf("\n");
}

int main(){
	head = malloc(sizeof(struct node));
	head-> data = 33;
	head->next = NULL;
	
	struct node *current = malloc(sizeof(struct node));
	current-> data = 37;
	current->next = NULL;
	head->next = current; 
	
	struct node *current2 = malloc(sizeof(struct node));
	current2->data = 50;
	current2->next = NULL;
	current->next = current2;
	
	struct node *current3 = malloc(sizeof(struct node));
	current3->data = 70;
	current3->next = NULL;
	current2->next = current3;
	
	struct node *current4 = malloc(sizeof(struct node));
	current4->data = 90;
	current4->next = NULL;
	current3->next = current4;
	
	viewLinkedList();

	// Add node at Begin
	struct node *addbegin = malloc(sizeof(struct node));
	addbegin->data = 31;
	addbegin->next = head;
	head = addbegin;
	viewLinkedList();

	// Delete list 50
	struct node *toBeDeleted = malloc(sizeof(struct node));
	toBeDeleted = head;
	
	while(toBeDeleted->next->data != 50)
	{
		toBeDeleted = toBeDeleted->next;
	}
	
	toBeDeleted->next = toBeDeleted->next->next;
	viewLinkedList();	
	
	return 0;
}
