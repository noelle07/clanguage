#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
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

int main ()
{
	head = malloc(sizeof(struct node));
	head->data = 10;
	head->next = NULL;
	
	struct node *current = malloc(sizeof(struct node));
	current->data = 35;
	current->next = NULL;
	head->next = current;
	
	struct node *current2 = malloc(sizeof(struct node));
	current2->data = 27;
	current2->next = NULL;
	current->next = current2;
	
	viewLinkedList();
	// Add node at head
	struct node *addbegin = malloc(sizeof(struct node));
	addbegin->data = 31;
	addbegin->next = head;
	head = addbegin;
	viewLinkedList();
	
//	(head->next)->next = head->next->next->next;
	struct node *toBeDeleted = malloc(sizeof(struct node));
	toBeDeleted = head;
	
	while(toBeDeleted->next->data != 35)
	{
		toBeDeleted = toBeDeleted->next;
	}
	
	toBeDeleted->next = toBeDeleted->next->next;
	viewLinkedList();	
	return 0;
}
