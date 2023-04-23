#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#define SIZE 25

int ran1,ran2,ran3,count;

struct node{
	char name[101];
	char id[15];
	int difficulty;
	char type[15];
	int submisions;
	int solved;
	node *next, *prev;
}*head[SIZE], *tail[SIZE];

node *createnode(char id[], char name[], char type[], int difficulty, int submisions, int solved){
	node newnode = (node*)malloc(sizeof(node));
	strcpy(newnode->id,id);
	strcpy(newnode->name,name);
	strcpy(newnode->type,type);
	newnode->difficulty = difficulty;
	newnode->submisions = submisions;
	newnode->solved = solved;
	newnode->next = newnode->prev = NULL;
	return newnode;
}

void random(){
	ran1 = rand() % 10;
	ran2 = rand() % 10;
	ran3 = rand() % 10;
}

void generateid(char id[], char type[]){
	random();
	if(strcmp(type,"Dynamic Programming") == 0){
		id[0] = 'D';
		id[1] = 'P';
	}
	else if(strcmp(type,"Greedy") == 0){
		id[0] = 'G';
		id[1] = 'R';
	}
	else if(strcmp(type,"Math") == 0){
		id[0] = 'M';
		id[1] = 'A';
	}
	else if(strcmp(type,"Brute Force") == 0){
		id[0] = 'B';
		id[1] = 'F';
	}
	id[2] = ran1 + '0';
	id[3] = ran2 + '0';
	id[4] = ran3 + '0';
	id[5] = '\0'; 
}

int generatekey(char id[]){
	int key=0;
	int len = strlen(id);
	for(int i=0; i<len ; i++){
		key = key + id[i];
	}
	key = key % SIZE;
}

void pushtail(node *temp){
	int key = generatekey(temp->id);
	if(!head[key]){
		head[key] = tail[key] = temp;
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
	else if(head[key] == tail[key]){
		free(head[key]);
		head[key] = tail[key] = NULL;
	}
	else{
		node *temp = head[key]->next;
		temp->prev = NULL;
		free(temp);
		head[key] = temp;
	}
}

void poptail(int key){
	if(!head[key]){
		return;
	}
	else if(head[key] == tail[key]){
		free(head[key]);
		head[key] = tail[key] = NULL;
	}
	else{
		node *temp = tail[key]->prev;
		temp->next = NULL;
		free(temp);
		tail[key] = temp;
	}
}

void popmid(char id[]){
	int key = generatekey(id);
	if(!head[key]){
		puts("Problem not found...");
		return;
	}
	else if(strcmp(head[key]->id,id) == 0){
		pophead(key);
		count--;
		puts("Problem sucessfully deleted...");
		return;
	}
	else if(strcmp(tail[key]->id,id) == 0){
		poptail(key);
		count--;
		puts("Problem sucessfully deleted...");
		return;
	}
	else{
		node *temp = head[key]->next;
		while(temp){
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			free(temp);
			temp = NULL;
			count--;
			puts("Problem sucessfully deleted...");
			return;
		}
		temp = temp->next;
	}
}

void viewdata(){
	if(count == 0 ){
		puts("There is no code problem data...");
		return;
	}
	else{
		puts("Successfully inserted !");
		puts("---------------------------");
		for(int i=0 ;i<SIZE ; i++){
			node *temp = head[i];
			while(temp){
				printf("Problem ID : %s\n",temp->id);
				printf("Problem Name : %s\n", temp->name);
				printf("Difficulty : %d\n", temp->difficulty);
				printf("Type : %s\n",temp->type);
				printf("Total of submission : %d\n",temp->submisions);
				printf("Total of solved cases : %d\n",temp->solved);
				temp = temp->next;
			}
		}
	}
}

void deletedata(){
	if(count == 0){
		puts("There is no code problem data...");
		return;
	}
	else{
		viewdata();
		char id[15];
		scanf("Input Problem ID to be deleted : %s",id);
		popmid(id);
	}
}

void adddata(){
	char name[101];
	char id[15];
	int difficulty;
	char type[15];
	int submisions;
	int solved;
	puts("Add a Code Problem");
	puts("-------------------");
	while(1){
		printf("Input problem's name : ");
		scanf("%[^\n]",name);
		getchar();
		if(strlen(name) >= 3 && strlen(name) <= 30){
			break;
		}
	}
	while(1){
		printf("Input problem's difficluty : ");
		scanf("%d",&difficulty);
		getchar();
		if(difficulty >= 800 && difficulty<= 3500){
			break;
		}
	}
	while(1){
		printf("Input problem's type : ");
		scanf("%s",type);
		getchar();
		if(strcmp(type,"Dynamic Programming") == 0 || strcmp(type,"Greedy") == 0 || strcmp(type,"Math") == 0 || strcmp(type,"Brute Force") == 0){		
			break;
		}
	}	
	while(1){
		printf("Input problem's total of case submissions : ");
		scanf("%d",&submisions);
		getchar();
		if(submisions >= 0 && submisions <= 100){
			solved = (submisions*(rand()%71))/100;
			break;
		}
	}
	generateid(id,type);
	count++;
	pushtail(createnode(name,id,type,difficulty,submisions,solved));
}

void menu(){
	int ch=0;
	do{
		puts("codeforJeS");
		puts("-------------------");
		puts("1. Add a Code Problem");
		puts("2. View All Code Problem");
		puts("3. Delete a Code Problem");
		puts("4. Exit");
		printf(">> ");
		scanf("%d",&ch);
		getchar();
		switch(ch){
			case 1:
				adddata();
				break;
			case 2:
				viewdata();
				break;
			case 3:
				deletedata();
				break;
			case 4:
				break;
		}
	}while(ch!=4);
}

int main(){
	srand(time(NULL));
	menu();
	return 0;
}
