#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26

struct Mahasiswa{
	char name[100];
	int age;
	struct Mahasiswa *next;
}*head[SIZE] = {NULL}, *tail[SIZE] = {NULL};

struct Mahasiswa *createNewMahasiswa(const char name[], int age){
	// Kita mau buat data baru yg dmn kita mau inisiasi(mulai kegiatan) memori
	// Kita mau nyimpen si node yang bakal buat nunjuk alamat selanjutnya nah total node nya kita mau sebesar si struct Mahasiswa
	struct Mahasiswa *node = (struct Mahasiswa*)malloc(sizeof(struct Mahasiswa));
	// Kalau mau nampilin nama pake strcpy
	strcpy(node->name, name);
	node->age = age;
	// kita mau return si node yg udh nyimpen data(nama, age)
	return node;
}

int hashFunction(const char name[]){
	return ((name[0] - 'A' )% SIZE);
}

void insert(const char name[], int age){
	int key = hashFunction(name);
	struct Mahasiswa *node = createNewMahasiswa(name, age);
	if(head[key == NULL]){
		head[key] = tail[key] = node;
	}
	else{
		// Push tail
		tail[key]->next = node;
		tail[key] = node;
	}
}

int searching(const char name[]){
	int key = hashFunction(name);
	struct Mahasiswa *current = head[key];
	while(current != NULL){
		// Kalo namanya sama berarti ketemu
		if(strcmp(name, current->name) == 0){
			return key;
		}
		current = current->next;
		}
		// Kalau Tidak ketemu
		return -1;
	}
	
void printTable(){
	struct Mahasiswa *current;
	for(int i = 0; i < SIZE; i++){
		if(head[i] != NULL){
			printf("%d. ", i);
			current = head[i];
			while(current != NULL){
				if(current != tail[i]){
					printf("%s [%d] -> ", current->name, current->age);
				}
				else{
					printf("%s [%d] -> NULL\n", current->name, current->age);
				}
				current = current->next;
			}
		}
		else{
		printf("%d. -\n", i);
		}
	}
}


int main(){
	insert("Amelia", 19);
	insert("Yuudachi", 22);
	insert("Ackerman", 20);
	insert("Violet", 25);
	
	if(searching("Amelia") != -1){
		printf("Yeay Found it!\n");
	}
	else{
		printf("Not Found it! :(\n");
	}
	
	printTable();
	
	return 0;
}
