#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#define SIZE 100
int count = 0;

struct Movie{
	char id[100];
	char name[100];
	int price;
	char genre[100];
	int duration;
	Movie *next;
}head[SIZE];

Movie *createMovie(char id[], char name[], int price, char genre[], int duration){
	Movie *newMovie = (Movie*)malloc(sizeof(Movie));
	strcpy(newMovie->id, id);
	strcpy(newMovie->name, name);
	newMovie->price = price;
	strcpy(newMovie->genre, genre);
	newMovie->duration = duration;
	newMovie->next = NULL;
	return newMovie;
}

int hash(char name[]){
	int key = 0;
	int len = strlen(name);
	for(int i = 0; i < len; i++){
		key+=name[i];
	}
	return key % SIZE;
}

void insert(char id[],char name[], int price, char genre[], int duration){
	int hashKey = hash(name);
	Movie *insertMovie = createMovie(id, name, price, genre, duration);
	if(head[hashKey]==NULL){
		head[hashKey] = insertMovie;
		count++;
		return;
	}
	printf("tst\n");
	Movie *temp = head[hashKey];
	while(temp->next != NULL){
		temp=temp->next;
	}
	temp->next = insertMovie;
	count++;
}
