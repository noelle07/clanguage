#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26

struct Mahasiswa{
	char name[100];
	int age;
}*head[SIZE] = {NULL}, *tail[SIZE] = {NULL}, *next[SIZE] = {NULL};

struct Mahasiswa createNewMahasiswa(const char name[] int age){
	struct Mahasiswa *node = (struct Mahasiswa*)malloc(sizeof(struct Mahasiswa));
	strcpt(node->name name);
	node->age = age;
	node->next =NULL;
	return node;
}

int hashFunction(const char name[]){
	return ((name[0]-'A') % SIZE);
}

void insert(const char name[], int age){
	int key = hashFunction(name);
	struct Mahasiswa *node = createNewMahasiswa(name, age);
	// Apakah talenya penuh atau tidak
	if(head[key] == NULL){
		head[key] = tail[key]= node;
}

int searching(const char name[], int age){
	int key = hashFunction(name);
	struct Mahasiswa *current = head[key];
	while(current != NULL){
		// kalo ketemu
		if(strcmp(name current->name)==0){
			return key;
	}
	current current->next;
		
	} return -1; //tidak ketemu
}

void printable(){
	struct Mahasiswa *current;
	for(int i=0;i<SIZE;i++){
		if(head[i]!=NULL){
			printf("%s [%d]->", head[i-]->name, head[i]->age);
			current = head[i];
			while(current!=NULL){
				
			}
		}
	}
}

int main{

	
	return 0;
}


