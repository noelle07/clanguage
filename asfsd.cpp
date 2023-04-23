#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define SIZE 120

int ran1, ran2, ran3, count;

struct research{
	char id[100];
	char name[100];
	int age;
	char jobdesk[100];
	char researchname[100];
	char researchdescription[100];
	int member;
	int toolused;
	research *next, *prev;
}*head[SIZE], *tail[SIZE];

research *createresearch(char id[] ,char name[], int age, char jobdesk[], char researchname[], char researchdescription[], int member, int toolused){
	research *newresearch = (research*)malloc(sizeof(research));
	strcpy(newresearch->id, id);
	strcpy(newresearch->name, name);
	newresearch->age = age;
	strcpy(newresearch->jobdesk, jobdesk);
	strcpy(newresearch->researchname, researchname);
	strcpy(newresearch->researchdescription, researchdescription);
	newresearch->member = member;
	newresearch->toolused = toolused;
	newresearch->next = newresearch->prev = NULL;
	return newresearch;
}

void random(){
	ran1 = rand() % 10;
	ran2 = rand() % 10;
	ran3 = rand() % 10;
}

void generateid(char id[]){
	random();
	id[0] = 'R';
	id[1] = 'E';
	id[2] = ran1 + '0';
	id[3] = ran2 + '0';
	id[4] = ran3 + '0';
	id[5] = '\0';
}

int generatekey(char id[]){
	int key = 0;
	int len = strlen(id);
	for(int i = 0; i<len; i++){
		key = key + id[i];
	}
	return key % SIZE;
}

void pushhead(research *temp){
	int key = generatekey(temp->id);
	if(!head[key]){
		head[key] = tail[key] = temp;
	}
	else{
		head[key]->next = temp;
		temp->prev = head[key];
		head[key] = temp;
		puts("Succesfully Add a new research!\nPress enter to continue...");
	}
}

void pophead(int key){
	if(!head[key]){
		return;
	}
	else if(head[key] = tail[key]){
		free(head[key]);
		head[key] = tail[key] = NULL;
	}
	else{
		research *temp = head[key]->next;
		temp->prev = NULL;
		free(head[key]);
		head[key] = temp;
	}
}

void poptail(int key){
	if(!head[key]){
		return;
	}
	else if(tail[key] = head[key]){
		free(tail[key]);
		tail[key] = head[key] = NULL;
	}
	else{
		research *temp = tail[key]->prev;
		temp->next = NULL;
		free(tail[key]);
		tail[key] = temp;
	}
}

void popmid(char id[]){
	int key = generatekey(id);
	if(!head[key]){
		puts("NOT FOUND! Can't delete");
	}
	else if(strcmp(head[key]->id, id)==0){
		pophead(key);
		puts("Succesfully deleted");
		count--;
		return;
	}
	else if(strcmp(tail[key]->id, id)==0){
		poptail(key);
		puts("Succesfully deleted");
		count--;
		return;
		
	}
	else{
		research *temp =head[key]->next;
		while(temp){
			if(strcmp(temp->id, id) == 0){
				temp->next->prev = temp->prev;
				temp->prev->next = temp->prev;
				free(temp);
				temp = NULL;
				count--;
				puts("Succesfully deleted");
				return;
			}
		}
		temp = temp->next;
	}
}

void view(){
	if(count == 0){
		puts("There is no research.\n Press enter to continue...");
		return;
	}
	else{
		for(int i = 0; i < SIZE; i++){
			research *temp = head[i];
			while(temp){
				printf("Id: %s\n", temp->id);
				printf("Name: %s\n", temp->name);
				printf("age: %d\n", temp->age);
				printf("jobdesk: %s\n", temp->jobdesk);
				printf("research name: %s\n", temp->researchname);
				printf("description: %s\n", temp->researchdescription);
				printf("member: %d\n", temp->member);
				printf("tool that has been used: %d\n", temp->toolused);
				temp = temp->next;
			}
		}
	}
}

void deletes(){
	if(count == 0){
		puts("There is no research.\n Press enter to continue...");
		return;
	}
	else{
		view();
		printf("Input Id you want to delete: ");
		char id[20];
		scanf("%s", id);
		popmid(id);
	}
}

bool check(char researchname[]){
	for(int i=0; i<strlen(researchname); i++){
		if(strcmp(researchname +i, " Research")==0){
			return true;
		}
	}
	return false;
}


void add(){
	char id[100];
	char name[100];
	int age;
	char jobdesk[100];
	char researchname[100];
	char researchdescription[100];
	int member;
	int toolused;
	while(1){
		printf("Insert your leader name: ");
		scanf("%[^\n]", name);
		getchar();
		if(strlen(name)>=5){
			break;
		}
	}
	while(1){
		printf("Insert your leader age: ");
		scanf("%d", &age);
		getchar();
		if(strlen(name)>=5){
			break;
		}
	}
	while(1){
		printf("Insert your jobdesk: ");
		scanf("%[^\n]", jobdesk);
		getchar();
		if(strcmp(jobdesk, "Gather Sample")==0 ||strcmp(jobdesk, "Researching Sample")==0 || strcmp(jobdesk, "Documentation")==0){
			break;
		}
	}
	while(1){
		printf("Insert your research name: ");
		scanf("%[^\n]", researchname);
		getchar();
		if(strlen(researchname)>=10 && strlen(researchname)<=50 &&check(researchname)){
			break;
		}
	}
	while(1){
		printf("Insert your research description: ");
		scanf("%[^\n]", researchdescription);
		getchar();
		if(strlen(researchdescription)>=10 && strlen(researchdescription)<=50){
			break;
		}
	}
	while(1){
		printf("Insert your member: ");
		scanf("%d", &member);
		getchar();
		if(member>=5){
		break;
		}
	}
	while(1){
		printf("Insert your research tool has been used: ");
		scanf("%d", &toolused);
		getchar();
		if(toolused>=0){
			break;
		}
	}
	generateid(id);
	count++;
	pushhead(createresearch(id,name, age,jobdesk,researchname, researchdescription, member, toolused));
}

void menu(){
	int choice =0;
	do{
		puts("1. Add Research");
		puts("2. View Research");
		puts("3. Delete Research");
		puts("4. Exit");
		printf(">>");
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
				deletes();
				break;
			case 4:
				break;
					
		}
	} while(choice!=4);
}
int main(){
	srand(time(NULL));
	menu();
	return 0;
}
