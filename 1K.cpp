//#include <stdio.h>
////new student!
//int main(){
//	char nama[101];
//	long long int nis;
//	int age;
//	
//	scanf("%s", &nama);
//	scanf("%lld %d", &nis, &age);
//	printf("Name : %s\n", nama);
//	printf("NIS : %lld\nAge : %d", nis, age);
//	
//	return 0;
//}

#include <stdio.h>
//
int main(){
	long long int id;
	char n[26];
	char c [26];
	long int num;
	
	scanf("%lld\n", &id);
	scanf("%[^\n]", &n);
	scanf("%s %ld", &c, &num);
	printf("Id	: %lld\n",id);
	printf("Name	: %s\n",n);
	printf("Class	: %s\n",c);
	printf("Num	: %ld\n",num);
		
	return 0; 
}
