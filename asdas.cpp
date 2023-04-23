#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#define SIZE 100

int ran1,ran2,ran3, count;

struct Movie{
	char id[100];
	char name[100];
	int price;
	char genre[100];
	int duration;
	Movie *next, *prev;
}*head[SIZE], *tail[SIZE];

Movie *createMovie(char id[], char name[], int price, char genre[], int duration){
	Movie *newMovie = (Movie*)malloc(sizeof(Movie));
	strcpy(newMovie->id, id);
	strcpy(newMovie->name, name);
	newMovie->price = price;
	strcpy(newMovie->genre, genre);
	newMovie->duration = duration;
	newMovie->next = newMovie->prev =NULL;
	return newMovie;
}

void random(){
	ran1 = rand() %10;
	ran2 = rand() %10;
	ran3 = rand() %10;
}

void generateId(char id[], char first, char second){
	random();
	id[0] = toupper(first);
	id[1] = toupper(second);
	id[2] = ran1 + '0';
	id[3] = ran2 + '0';
	id[4] = ran3 + '0';
	id[5] = '\0';
}

int generatekey(int num1, int num2, int num3){
	return(num1 + num2 + num3 - 1)%SIZE;
}

void pushHead(Movie *temp){
	int key = generatekey(temp->id[2] - '0', temp->id[3] - '0', temp->id[4] - '0');
	if(!head[key]){
		head[key] = tail[key] = temp;
	}else{
		head[key]->prev = temp;
		temp->next = head[key];
		head[key] = temp;
	}
}

void pophead(int key){
	if(!head[key]){
		return;
	}else if(head[key] == tail[key]){
		free(head[key]);
		head[key] = tail[key] = NULL;
	}else{
		Movie *temp =head[key]->next;
		temp->prev = NULL;
		free(head[key]);
		head[key] = temp;
	}
}
void poptail(int key){
	if(!head[key]){
		return;
	}else if(head[key] == tail[key]){
		free(head[key]);
		head[key] = tail[key] = NULL;
	}else{
		Movie *temp =tail[key]->prev;
		temp->next = NULL;
		free(tail[key]);
		tail[key] = temp;
	}
}

void popMid(char id[]){
	int key = generatekey(id[2] - '0', id[3] -'0', id[4] -'0');
	if(!head[key]){
		puts("no data");
		return;
	}else if(strcmp(head[key]->id, id)==0){
		pophead(key);
		count--;
		puts("data deleted");
		return;
	}else if(strcmp(tail[key]->id, id)==0){
		poptail(key);
		count--;
		puts("data deleted");
		return;
	}else{
		Movie *temp = head[key]->next;
		while(temp){
			if(strcmp(head[key]->id, id)==0){
				temp->next->prev = temp->prev;
				temp->prev->next = temp->next;
				free(temp);
				temp = NULL;
				count--;
				puts("data deleted");
				return;
			}
			temp =temp->next;
		}
	}
}

void viewMovie(){
	if(count == 0){
		puts("empty");
		return;
	}else{
		for(int i = 0; i<SIZE; i++){
			Movie *temp = head[i];
			while(temp){
				printf("Id: %s\n", temp->id);
				printf("Name: %s\n", temp->name);
				printf("price: %d\n", temp->price);
				printf("genre: %s\n", temp->genre);
				printf("duration: %d\n", temp->duration);
				temp = temp->next;
			}
		}
	}
}

void deletes(){
	if(count == 0){
		puts("data not found");
		return;
	}else{
		viewMovie();
		char id[10];
		scanf("%s", id);
		popMid(id);
	}
}

bool check(char name[]){
	for(int i=0;i<strlen(name);i++){
		if(strcmp(name +i, " Movie")==0){
			return true;
		}
	}
	return false;
}

void add(){
	char id[100];
	char name[100];
	int price;
	char genre[100];
	int duration;
	while(true){
		printf("Insert name:");
		scanf("%[^\n]", name);
		getchar();
		if(strlen(name)>= 5 && strlen(name)<=30 && check(name)){
			break;
		}
	}
	while(true){
		printf("Insert price: ");
		scanf("%d", &price);
		getchar();
		if(price>=1 && price<=100000){
			break;
		}
	}
	while(true){
		printf("Insert genre: ");
		scanf("%s", genre);
		getchar();
		if(strcmp(genre, "Action") ==0 ||strcmp(genre, "Horror")==0 ||strcmp(genre, "Drama")==0){
			break;
		}
	}
	while(true){
		printf("Insert duration: ");
		scanf("%d", &duration);
		getchar();
		if(duration>=1 &&duration<=200){
			break;
		}
	}
	generateId(id, name[0],name[1]);
	count++;
	pushHead(createMovie(id,name, price, genre, duration));
}

void menu(){
	int choice =0;
	do{
		puts("1. Add Movies");
		puts("2. View Movies");
		puts("3. Delete Movies");
		puts("4. Exit");
		printf(">>");
		scanf("%d", &choice);
		getchar();
		switch(choice){
			case 1:
				add();
				break;
			case 2:
				viewMovie();
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
