#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 30

struct node{
	char name[55]; //key
	int angka;
}*list[SIZE];

int count = 0; //berapa anggota di dalam hash table

node *createnode(char name[], int angka){
	node *newnode = (node*)malloc(sizeof(node));
	strcpy(newnode->name, name);
	newnode->angka = angka;
	return newnode;
}

int hash(char name[]){
	int key=0;
	int len = strlen(name);
	for(int i=0; i<len ; i++){
		key =key +name[i];
	}
	return key % SIZE;
}

void insert(char name[], int angka){
	int hashkey = hash(name);
	int temp = hashkey;
	if(count == SIZE){
		printf("Hash table is full\n");
		return;
	}
	
	while(list[temp] != NULL){ //indexnya itu tdk ada nilai
		temp = (temp+1)%SIZE;
		if(temp == SIZE){
			temp=0;
		}
	}
	list[temp] = createnode(name,angka);
	count++;
}

void print(){
	for(int i=0; i<SIZE;i++){
		if(list[i] != NULL){
			printf("%d: %s, %d\n", i, list[i]->name, list[i]->angka);
		}
		else{
			printf("%d: -\n",i);
		}
	}
}

node *search(char name[]){
	int hashkey = hash(name);
	int pos = hashkey;
	
	do{
		if(list[pos] != NULL && strcmp(list[pos]->name,name)==0){
			printf("Found at %d",pos);
			return list[pos];
		}
		pos = (pos+1)%SIZE;
	}
	while(pos != hashkey);
	return NULL;
}

void pop(char name[]){
	int hashkey = hash(name);
	int pos = hashkey;
	
	do{
		if(list[pos] != NULL && strcmp(list[pos]->name,name) == 0){
			free(list[pos]);
			list[pos] = NULL;
			return;
		}
		pos = (pos+1)%SIZE;
	}
	while(pos != hashkey);
	return;
}

int main(){
	insert("Jokowi",90);
	insert("Jokowi",60);	
	insert("Soekarno",95);
	print();
	printf("\n");
	if(search("Soekarno")){
		printf("Ketemu\n");
	}
	else{
		printf("gak ketemu\n");
	}
	pop("Jokowi");
	pop("Jokowi");
	print();
	return 0;
}
