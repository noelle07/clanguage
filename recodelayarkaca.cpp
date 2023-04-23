#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#define SIZE 100

int ran1, ran2, ran3, count;

struct movie{
	char id[100];
	char name[100];	
	int price;
	char genre[100];	
	int duration;
	movie *next, *prev;
}*head[SIZE], *tail[SIZE];

movie *createmovie(char id[], char name[], int price, char genre[], int duration){
	movie *newmovie = (movie*)malloc(sizeof(movie));
	strcpy(newmovie->id, id);
	strcpy(newmovie->name, name);
	newmovie->price = price;
	strcpy(newmovie->genre, genre);
	newmovie->duration = duration;
	newmovie->next = newmovie->prev =NULL;
	return newmovie;
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
}

int generatekey(int num1, int num2, int num3){
	return (num1+num2+num3-1)% SIZE;
}

void pushTail(movie *temp){
	int key = generatekey(temp->id[2]-'0', temp->id[3]-'0', temp->id[4]-'0');
	if(!head[key]){
		head[key] = tail[key] =temp;
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
	else if(head[key]=tail[key]){
		free(head[key]);
		head[key]=tail[key]=NULL;
	}
	else{
		movie *temp =head[key]->next;
		temp->prev =NULL;
		free(head[key]);
		return;
	}
}
void poptail(int key){
	if(!head[key]){
		return;
	}
	else if(head[key]=tail[key]){
		free(head[key]);
		head[key]=tail[key]=NULL;
	}
	else{
		movie *temp =tail[key]->prev;
		temp->next =NULL;
		free(tail[key]);
		return;
	}
}

void popmid(char id[]){
	int key = generatekey(id[2]-'0', id[3]-'0', id[4]-'0');
	if(!head[key]){
		return;
	}
	else if(strcmp(head[key]->id,id)==0){
		pophead(key);
		free(head[key]);
		return;
		count--;
	}
	else if(strcmp(tail[key]->id,id)==0){
		poptail(key);
		free(tail[key]);
		return;
		count--;
	}
	else{
		movie *temp = head[key]->next;
		for(int i =0; i<SIZE;i++){
			temp =head[i];
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
		}
		temp =temp->next;
	}
}

int main(){
	
	return 0;
}
