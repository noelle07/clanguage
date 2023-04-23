#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h> // buat randomize number setiap jalan
#include<ctype.h> // buat pake toUpper
// Global variable
int ran1, ran2, ran3, count;
// create Struct
struct Movie{
	char id[100];
	char name[100];
	int price;
	char genre[20];
	int duration;
	Movie *next, *prev;
}*head[100], *tail[100];
// Allocate nenory
Movie *createMovie(const char id[], const char name[], int price, const char genre[], int duration){
	Movie *newMovie = (Movie*)malloc(sizeof(Movie));
	strcpy(newMovie->id, id); 
	strcpy(newMovie->name, name);
	newMovie->price = price;
	strcpy(newMovie->genre, genre);
	newMovie->duration = duration;
	newMovie->next = newMovie->prev = NULL;
	return newMovie; 
}

// Generate random number
void generateRandom(){
	ran1 = rand()%10;
	ran2 = rand()%10;
	ran3 = rand()%10;
}

// Genaerate Id
void generateId(char id[], char first, char second){
	generateRandom();
	id[0] = toupper(first);	
	id[1] = toupper(second);	
	id[2] = ran1 + '0';	
	id[3] = ran2 + '0';	
	id[4] = ran3 + '0';	
	id[5] = '\0'; // End of string
}

// Generate Key
int generateKey(int num1, int num2, int num3){
	return (num1 + num2 + num3 - 1) % 100;
}

// Push data
void pushTail(Movie *temp){
	int key = generateKey(temp->id[2] - '0',temp->id[3] -'0',temp->id[4] -'0');
	if(!head[key]){
		head[key] = tail[key] = temp;
	}
	else{
		tail[key]->next = temp;
		temp->prev = tail[key];
		tail[key] = temp;
	}
}
// Pop Data
void popHead (int key){
	if(!head[key]){
		return;
	} 
	else if(head[key] == tail[key]){
		free(head[key]);
		head[key] = tail[key] = NULL;
	}
	else{
	Movie *temp = head[key]->next;
	temp->prev = NULL;
	free(head[key]);
	head[key] = temp;
	}
}

void popTail(int key){
	if(!head[key]){
	return;
	} 
	else if(head[key] == tail[key]){
		free(head[key]);
		head[key] = tail[key] = NULL;
	}
	else{
	Movie *temp = tail[key]->prev;
	temp->next = NULL;
	free(tail[key]);
	tail[key] = temp;
	}
}

void popMid(char id[]){
	int key = generateKey(id[2] - '0', id[3] - '0', id[4] - '0');
	if(!head[key]){
		puts("No Data Found\n");
	return;
	} 
	else if(strcmp(head[key]->id, id) == 0){
		popHead(key);
		puts("Data Deleted\n");
		return;
		count--;
	}
	else if(strcmp(tail[key]->id, id) == 0){
		popTail(key);
		puts("Data Deleted\n");
		return;
		count--;
	}
	else{
		Movie *temp = head[key]->next;
		while(temp){
			if(strcmp(temp->id, id) == 0){
				temp->next->prev = temp->prev;
				temp->prev->next = temp->next;
				free(temp);
				temp = NULL;
				count--;
				puts("Data Deleted\n");
				return;
			}
			temp = temp->next;
			
		}
	}
}

// View Data
void viewData(){
	if(count == 0){
		puts("No Movie Data!\n");
		return;
	}
	else{
		for(int i = 0; i < 100; i++){
			Movie *temp = head[i];
			while(temp){
				printf("Id: %s\n", temp->id);
				printf("Name: %s\n", temp->name);
				printf("Genre: %s\n", temp->genre);
				printf("Price: %d\n", temp->price);
				printf("Duration: %d\n", temp->duration);
				temp = temp->next;
			}
		}
	}
}

// Delete Data
void deleteData(){
	if(count == 0){
		puts("No Movie Data!\n");
		return;
	}
	else{
		viewData();
		printf("Insert Movie Id to be deleted: ");
		char id[10];
		scanf("%s", id);
		popMid(id);
	}
}

// Add data
bool checkLast(char name[]){
	for(int i = 0; i < strlen(name); i++){
		if(strcmp(name +i, " Movie") == 0){
			return true;
		}
	}
	return false;
}

void addData(){
	char id[100];
	char name[100];
	int price;
	char genre[20];
	int duration;
	while(true){
		printf("Insert Movie name: ");
		scanf("%[^\n]", name); 
		getchar();
		if(strlen(name) >= 5 && strlen(name) <= 30 && checkLast(name)){
			break;
		}
	}
	while(true){
		printf("Insert Movie price: ");
		scanf("%d", &price);
		getchar();
		if(price >= 1 && price <= 100000){
			break;
		}
	}
	while(true){
		printf("Insert Movie genre: ");
		scanf("%[^\n]", genre);
		getchar();
		if(strcmp(genre, "Horror") == 0 || strcmp(genre, "Action") == 0 || strcmp(genre, "Drama") == 0){
			break;
		}
	}
	while(true){
		printf("Insert Movie duration: ");
		scanf("%d", &duration);
		getchar();
		if(duration >= 1 && duration <= 200){
			break;
		}
	}
	generateId(id, name[0], name[1]);
	count++;
	pushTail(createMovie(id, name, price, genre, duration));
}


void menu(){
	int choice = 0;
	do{
	printf("1. Add Movies\n");
	printf("2. View Movies\n");
	printf("3. Delete Movies\n");
	printf("4. Exit\n");
	printf(">> ");
	scanf("%d", &choice);
	getchar();
	switch(choice){
		case 1:
			addData();
			break;
	
		case 2:
			viewData();
			break;
		case 3:
			deleteData();
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
