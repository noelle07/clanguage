#include <stdio.h>
#include <string.h>

struct mhs {
	char nim[9];
	char name[26];
	float gpa;
};

int main(){
	struct mhs lia;
	float wgpa;
	
	scanf("%s", lia.nim);
	fflush(stdin);
	gets(lia.name);
	scanf("%f", &wgpa);
	lia.gpa = wgpa;
	printf("%s %s %.2f", lia.nim, lia.name, lia.gpa);
	return 1;
}
//#include <stdio.h>
//
//struct account{
//	int accountNo;
//	char accountType;
//	char name[31];
//	long credit;
//}customer1, customer2;
//
//int main(){
//	
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//struct tmhs{	//structure data type
//	char nim[11];
//	char name[26];
//	float gpa;
//}akad_mhs, ali, tono;
//
////void function1(){
////	struct tmhs akad_mhs; // variable of structure
////}
//int main(){
////	struct tmhs ali, tono; // variable of structure
//	return 0;
//}
