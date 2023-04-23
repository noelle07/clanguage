#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char name[100];
	char priority[100];
	int status;
	node *next;
	node *prev;
}*head, *tail;

node *createnode(const char *name, const char *priority, int status){
	node *newnode =(node*)malloc(sizeof(node));
	strcpy(newnode->name, name);
	strcpy(newnode->priority, priority);
	newnode->status = status;
	newnode->next = newnode->prev =NULL;
	
	return newnode;
}

void insert(node *newnode){ // FIFO 
	if(head == NULL){
		head = tail = newnode;
	}
	else if(newnode->status > head->status){ //(push head)
		head->prev = newnode;
		newnode->next = head;
		head = newnode;
	}
	else if(newnode->status <= tail->status){ // (push tail)
		tail->next = newnode;
		newnode->prev = tail;
		tail = newnode;
	}
	else{ // (push mid)
		node *curr = head;
		while(curr != tail && newnode->status <= curr->next->status){
			curr = curr->next; // kita jalanin
		}
		newnode->prev = curr;
		newnode->next = curr->next;
		curr->next = newnode;
		curr->next->prev =newnode;
	}
}

void pop(){ // Queue (FIFO) pop head
	if(head == NULL){
		puts("Queue is empty");
		return;
	}
	printf("Attention! %s is being served at %s table.\n", head->name, head->priority);
	if(head == tail){ // data cuma 1
		free(head);
		head = tail = NULL;
	}
	else{ // data lebih dari 1
		node *curr = head;
		head = head->next;
		free(curr);
		curr = NULL;
	}
}

void popAll(){
	while(head != NULL){
		pop();
	}
}

void dismiss(){
	popAll();
	puts("End of the day!");
}

void view(){
	if(head == NULL){
		puts("Queue is empty");
		return;
	}
	int num = 1;
	
	node *curr = head;
	
	while(curr != NULL){
		printf("%d. %s\n", num++, curr->name);
		curr = curr->next;
	}
}

void add(){
	char name[100];
	char priority[100];
	int status;
	
	scanf("%s %[^\n]", priority, name);
	
	if(strcmp(priority, "VVIP") == 0){
		status = 3;
	}
	if(strcmp(priority, "VIP") == 0){
		status = 2;
	}
	if(strcmp(priority, "Guest") == 0 || strcmp(priority, "Member") == 0){
		status = 1;
	}
	insert(createnode(name, priority, status));
}

int main(){
	int input;
	while(1){
		do{
			puts("=============================");
			puts("SUNIB Restaurant Reservation");
			puts("=============================");
			puts("Waiting Line:");
			view();
			
			puts("1. Add Customer to Queue");
			puts("2. Serve One");
			puts("3. Serve All");
			puts("4. Dismiss Queue");
			puts("0. Exit");
			scanf("%d", &input);
		}
		while(input <= 0 || input >4 );
		
		switch(input){
			case 1:
				add();
				break;
			case 2:
				pop();
				break;
			case 3:
				popAll();
				break;
			case 4 :
				dismiss();
				break;
			case 0:
				return 0;
				break;
		}
	} 
	
	return 0;
}
