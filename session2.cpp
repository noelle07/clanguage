#include <stdio.h>
#include <string.h>

//struct myStructure{
//	int myNum;
//	char myLetter;
//	char myString[30]; //string
//};

struct profile{
	int age;
	char name[100];
};
struct student{
	struct profile p;
	int score;
	char grade;
};

int main(){
//	struct myStructure s1;
//	//trying to assign a value to he string
//	strcpy(s1.myString, "Some text");
//	//trying to print the value
//	printf("My string: %s", s1.myString);
	struct student x;
	student arr[10];
	
	arr[0].score = 92;
	arr[0].grade = 'A';
	arr[0].p.age = 20;
	strcpy(arr[0].p.name, "budi");
	
	arr[1].score = 83;
	arr[1].grade = 'B';
	arr[1].p.age = 19;
	strcpy(arr[1].p.name, "chandra");
	
	
//	x.score = 92;
//	x.grade = 'A';
//	x.p.age = 20;
//	
//	strcpy(x.p.name, "budi");
	printf("%d %s %d %s", arr[0].score, arr[0].grade, arr[0].p.age, arr[0].p.name);
	printf("%d %s %d %s", arr[1].score, arr[1].grade, arr[1].p.age, arr[1].p.name);	
	return 0;
}
