#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// To define total 26 alphabet
#define SIZE 26

int counter; // Buat menghitung data yang masuk ke dalam tabel

struct Mahasiswa{
	char name[100];
	int age;
}*table[SIZE] = {NULL}; // Kita mau buat table seukuran SIZE tapi masih kosong belum diisi apa2

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
	return ((name[0] - 'A') % SIZE);
}

// insert buat masukin data
void insert(const char name[], int age){
	// kita declare key buat nyimpen hasil data yang masuk dari hashFunction
	int key = hashFunction(name);
	// nah kita mau posisi saat ini itu berisi key tadi kan yg nyimpen hasil hashFunction
	int currentPos = key;
	
	// Apakah tabelnya penuh atau tidak
	if(counter == SIZE){
		printf("[!] Table is already full!\n");
		return;		
	}
	
	// Kalau tabel di key tersebut sudah keisi
	while(table[currentPos] != NULL){
		// buat mindahin ke tabel di key selanjutnya
		currentPos = (currentPos + 1) % SIZE;
	}
	table[currentPos] = createNewMahasiswa(name, age);
	counter++;
}

void deletes(const char name[]){
	// kita declare key buat nyimpen hasil data yang masuk dari hashFunction
	int key = hashFunction(name);
	// nah kita mau posisi saat ini itu berisi key tadi kan yg nyimpen hasil hashFunction
	int currentPos = key;
	
	do{
		// Kalau tidak kosong dan nama yang mau dihapus ternyata sama
		if(table[currentPos] != NULL && strcmp(name, table[currentPos]->name) == 0){
			free(table[currentPos]);
			counter--;
			table[currentPos] = NULL;
		}
		currentPos = (currentPos + 1) % SIZE;
	}while(currentPos != key);
}

struct Mahasiswa* searching(const char name[]){
	// kita declare key buat nyimpen hasil data yang masuk dari hashFunction
	int key = hashFunction(name);
	// nah kita mau posisi saat ini itu berisi key tadi kan yg nyimpen hasil hashFunction
	int currentPos = key;
	do{
		// Kalau tidak kosong dan nama yang mau dihapus ternyata sama
		if(table[currentPos] != NULL && strcmp(name, table[currentPos]->name) == 0){
//			free(table[currentPos]);
//			counter--;
//			table[currentPos] = NULL;
			return table[currentPos];
		}
//		currentPos = (currentPos + 1) % SIZE;
	}while(currentPos != key);
	return NULL;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

void printTable(){
	for(int i = 0; i < SIZE; i++){
		if(table[i] != NULL){
			printf("%d. %s [%d]\n", i, table[i]->name, table[i]->age);
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
	
	printTable();
	
	struct Mahasiswa *searchs = searching("Yuudachi");
	if(searchs == NULL){
		printf("No Data!\n");
	}
	else{
		printf("IYOI!! :)\n");
	}
	return 0;
}
