#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26

int counter; // Buat menghitung data yang masuk ke tabel

struct Mahasiswa{
	char name[100];
	int age;
}*table[SIZE] = {NULL};

struct Mahasiswa *createNewMahasiswa(const char name[], int age){
	struct Mahasiswa *node = (struct Mahasiswa*)malloc(sizeof(struct Mahasiswa));
	strcpy(node->name, name);
	node->age = age;
	return node;
}

int hashFunction(const char name[]){
	return ((name[0] - 'A' )% SIZE);
}

void insert(const char name[], int age){
	int key = hashFunction(name);
	int currentPos = key;
	// Apakah talenya penuh atau tidak
	if(counter == SIZE){
		printf("[!] Table is already full!\n");
		return;
	}
	// Kalo table di key tersebut sudah keisi
	while(table[currentPos] != NULL){
		currentPos = (currentPos +1) % SIZE;
	}
	
	table[currentPos] = createNewMahasiswa(name, age);
	counter++;
}

void deletes(const char name[]){
	int key = hashFunction(name);
	int currentPos = key;

	do{
		if(table[currentPos]!=NULL && strcmp(name, table[currentPos]->name) == 0){
			free(table[currentPos]);
			counter--;
			table[currentPos] = NULL;
			}
		currentPos = (currentPos + 1)  % SIZE;
	} while (currentPos != key);
}
// struct aja 
struct Mahasiswa* searching(const char name[]){
	int key = hashFunction(name);
	int currentPos = key;
	
	do{
		if(table[currentPos] != NULL && strcmp(name, table[currentPos]->name) == 0){
			return table[currentPos];
		}
		
	}while(currentPos != key);
		return NULL;
}

void printTable(){
	for(int i=0; i< SIZE;i++){
		if(table[i]!=NULL){
			printf("%d. %s [%d]\n", i, table[i]->name, table[i]->age);
		}else{
			printf("%d. -\n", i);
		}
	}
}

int main(){
	insert ("Marvin", 20);
	insert ("Valentino", 21);
	insert ("Rico", 21);
	
	deletes("Rico");
	printTable();
	
	struct Mahasiswa *searchs = searching("Rico");
	if(searchs==NULL){
		printf("Tidak ketemu!\n");
	}else{
		printf("ketemu!\n");
	}
	
	return 0;
}


