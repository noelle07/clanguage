#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Naming Convention
/* 1. Kasih first letter
   2. Kasih Snakecase
*/

struct Student{	// 104 bytes
	char name [100]; //100 bytes
	int age; // 4 bytes
	Student *next; // buat nunjuk alamat berikutnya
};

/*Dynamic Memory Allocation
Malloc -> Siapin address yang BELUM dibersihin
Calloc -> Siapin address yang SUDAH dibersihin
Realloc

0001 -> 123127312
Kalau pake Malloc -> 123127312
Kalau pake Calloc -> 0

Cast Type -> alokasiin data buat tipe data apa
*/

// Allocate Data
Student *Initiate(const char *name, int age){
	// Reverse Memory
	Student *student = (Student*)calloc(1,sizeof(Student));
	// Insert Data
	strcpy(student -> name, name);
	student -> age = age;
	student -> next = NULL;
	// Return Data
	return student;
}

/* CRUD
Create
Read
Upload
Delete
*/

int main(){
//	Student students[100];
//	strcpy(students[0].name, "Marvin");
//	students[0].age = 20;
//	printf("Name	:	%s\n", students[0].name);
//	printf("Age	:	%d\n", students[0].age);

	Student *student1 = Initiate("Valen", 20);
	Student *student2 = Initiate("Marvin", 20);
	student1 -> next = student2;
	printf("Nama : %s\n",student1 -> name);
	printf("Nama ke-2 : %s\n",student1 -> next -> name);
	
	// pointer and array
	// array of struct
//	int arr[100] = {0};
//	char str[100] = "Hello";
//	
//	// Alamat
//	puts("Alamat String");
//	printf("%d\n", &str[0]);
//	printf("%d\n", &str[1]);
//	printf("%d\n", &str[2]);
//	
//	// value
//	printf("%d\n\n", str[0]);
	
//	long long int arr [100] = {1,2,3,4,5};
	// Alamat
//	puts("Alamat Integer");
//	printf("%d\n", &arr[0]);
//	printf("%d\n", &arr[1]);
//	printf("%d\n\n", &arr[2]);
//	
//	puts("Pointer Concept");
//	printf("%d\n", arr);
//	printf("%d\n", arr + 1);
//	printf("%d\n", arr + 2);
//	
//	
//	//pointer -> buat nyimpen alamat
//	int a = 13;
//	int *b = &a;
//	int **c = &b;
//	
//	
//	
	// value of b
//	printf("%d\n", b);
//	// pointer of b
//	printf("%d\n", *b);
//	// alamat b
//	printf("%d\n", &b);
	return 0;
}
