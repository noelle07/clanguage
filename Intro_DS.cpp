#include <stdio.h> // Input Output
#include <stdlib.h> // Dynamic Memory Allocation
#include <string.h> // strcpy

struct Student{
	char name[255];
	int age;
	double gpa;
};

// Data Structure -> create read update delete (CRUD)
// Create -> return type nya Student* ikutin yg di dlm int main
// Kalau kita lempar string literal "Budi" yang bukan variabel string itu harus pake const char *name
// return pointer that points to the newly created  Student
Student *createStudent(const char *name, int age, double gpa){
	// Allocate Memory with size of Student, cast void* to Student*
	Student *newStudent = (Student*)malloc(sizeof(Student));
	strcpy(newStudent->name, name); //strcpy((*newStudent*).name name);
	newStudent->age = age; // (*newStudent).age = age;
	newStudent->gpa = gpa; // (*newStudent).gpa = gpa;
	return newStudent;
}

void readStudent(Student *s){
	
}

int main(){
	// Student s itu cuma nyimpen alamat si variable jadi pake pointer
	Student *s = createStudent("Budi", 20, 3.97);
	printf("%s ", s->name);
	printf("%d ", s->age);
	printf("%.2f ", s->gpa);
	return 0;
}
