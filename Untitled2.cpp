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

void pushtail(Movie *temp){
	int key = generateKey(temp->id[2]- '0', temp->id[3]-'0', temp->id[4] -'0');
	if(!tail[key]){
		tail[key] = head[key] = temp;
	} 
	else{
		tail[key]->next =temp;
		temp->prev = tail[key];
		tail[key]=temp;
	}
}

void pophead(int key){
	if(!head[key]){
		return;
	}
	else if(head[key] = tail[key]){
		free(tail[key]);
		tail[key] = NULL;
	}
	else{
		Movie *temp = head[key]->next;
		temp->prev =NULL;
		free(tail[key]);
		head[key] =temp;
	}
}
