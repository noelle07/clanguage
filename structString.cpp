//#include <stdio.h>
//#include <string.h>
//
//struct myStruct{
//	int myNum;
//	char myLetter[50];
//	char myString[30]; //string
//};
//
//int main(){
//	struct myStruct s1;
//	strcpy(s1.myString, "Hellow");
//	printf("My String: %s", s1.myString);
//	
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//struct profile{
//	int age;
//	char name[100];
//	
//};
//
//struct student{
//	struct profile p;
//	int score;
//	char grade;
//};
//
//// kalau pake string di dalam struct pake strcpy
//int main(){
//	struct student x;
//	
//	x.score = 92;
//	x.grade = 'A';
//	x.p.age = 19;
//	strcpy(x.p.name, "Amelia");
//	printf("score: %d\ngrade: %c\nage: %d\nname: %s\n", x.score, x.grade, x.p.age, x.p.name);
//	
//	return 0;
//}

#include <stdio.h>
#include <string.h>

struct car{
	char brand[50];
	char model[50];
	long int year;
	
};

struct customer{
	char name[5000];
	char address[5000];
	long int salary;
	
};

struct employee{
	char name[5000];
	long int salary;
	long int id;
	
};

int main(){
	struct car car1 ={"BM", "X", 1999};
	struct car car2 = {"Ford", "Mustang", 1969};
	struct car car3 = {"Toyota", "Corolla", 2011};
	 
	struct customer cus1 = {"Alam", "Malang", 30000000};
	struct customer cus2 = {"Hannis", "Lampung", 70000000};
	struct customer cus3 = {"Ghina", "Tangerang", 90000000};
	
	struct employee e1= {"Alif", 400000000, 1};
	struct employee e2 = {"Hafid", 600000000, 2};
	struct employee e3 = {"Rizki", 5000000000, 3};
	
	printf("%s %s %d\n", car1.brand, car1.model, car1.year);
	printf("%s %s %d\n", car2.brand, car2.model, car2.year);
	printf("%s %s %d\n", car3.brand, car3.model, car3.year);
	
	printf("%s %s %d\n", cus1.name, cus1.address, cus1.salary);
	printf("%s %s %d\n", cus2.name, cus2.address, cus2.salary);
	printf("%s %s %d\n", cus3.name, cus3.address, cus3.salary);
	
	printf("%s %d %d\n", e1.name, e1.salary, e1.id);
	printf("%s %d %d\n", e2.name, e2.salary, e2.id);
	printf("%s %d %d\n", e3.name, e3.salary, e3.id);
	return 0;
}
