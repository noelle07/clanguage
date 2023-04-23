#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define SIZE 30

int ran1, ran2, ran3, count;

struct node{
	char id[100];
	char name[100];
	char type[100];
	int price;
	char confirm[3];
	node *next, *prev;
}*head[SIZE], *tail[SIZE];

node *createnode(char id[], char name[], char type[], int price, char confirm[]){
	node *newnode=(node*)malloc(sizeof(node));
	strcpy(newnode->id, id);
	strcpy(newnode->name, name);
	strcpy(newnode->type, type);
	newnode->price = price;
	strcpy(newnode->confirm, confirm);
	newnode->prev = newnode->prev =NULL;
	return newnode;
}

void random(){
	ran1 = rand()%10;
	ran2 = rand()%10;
	ran3 = rand()%10;
}

void generateid(char id[], char first, char second){
	random();
	id[0] = toupper(first);
	id[1] = toupper(second);
	id[2] = ran1 + '0';
	id[3] = ran2 + '0';
	id[4] = ran3 + '0';
	id[5] = '\0';
}

int generatekey(char id[]){
	int key = 0;
	len = strlen(id);
	for(int i = 0; i < SIZE; i++){
		key = key + id[i];
	}
	key = key % SIZE;
}

void pushtail(node *temp){
	int key = generetekey(temp->id[2] = '0', temp->id[3]='0', temp->id[4]-'0');
	if(!head[key]){
		tail[key] = head[key] = temp;
	}
	else{
		tail[key]->next = temp;
		temp->prev = tail[key];
		tail[key] = temp;
	}
}

void pophead(int key){
	if(!head[key]){
		return;
	}
	else if(head[key] == tail [key]){
		free(head[key]);
		head[key] = tail[key] = NULL;
	}
	else{
		node *temp = head[key]->next;
		temp->prev = NULL;
		free(head[key]);
		head[key] = temp;
	}
}

void poptail(int key){
	if(!head[key]){
		return;
	}
	else if(head[key] == tail [key]){
		free(head[key]);
		head[key] = tail[key] = NULL;
	}
	else{
		node *temp = tail[key]->prev;
		temp->next = NULL;
		free(tail[key]);
		tail[key] = temp;
	}
}

void popmid(char id[]){
	int key = generatekey(id[2] - '0', id[3] - '0',id[4] - '0');
	if(!head[key]){
		return;
	}
	else if(strcmp(head[key]->id, id) == 0){
		pophead();
		count--;
		puts("Deleted");
		return;
	}
	else if(strcmp(tail[key]->id,id)==0){
		poptail();
		count--;
		puts("deleted");
		return;
	}
	else{
		node *temp = head[key]->next;
		while(temp){
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			free(temp);
			count--;
			puts("Deleted");
			return;
		}
		temp = temp->next;
	}
}

void view(){
	if(count == 0){
		puts("there is no data");
		return;
	}
	else{
		for(int i = 0; i SIZE; i++){
			node *temp = head[i]
			while(temp){
				printf("Id: %s\n", temp->id);
				printf("Name: %s\n", temp->name);
				printf("type: %s\n", temp->type);
				printf("price %d\n", temp->price);
				printf("confirm: %s\n", temp->confirm);
				temp = temp->next;
			}			
		}
	}
}



void menu(){
	int choice = 0;
	do{
	printf("1. Add \n");
	printf("2. View \n");
	printf("3. Insert \n");
	printf("4. Exit\n");
	printf(">> ");
	scanf("%d", &choice);
	getchar();
	switch(choice){
		case 1:
			add();
			break;
	
		case 2:
			view();
			break;
		case 3:
			insert();
			break;
		case 4:
			puts("Thankyou");
			break;
	}
	}while(choice != 4);
}



int main(){
	srand(time(NULL));
	menu();
	return 0;
}
