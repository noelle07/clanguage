#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// linear probing
#define SIZE 9
struct hashNode{
 char name[20];
 int key;
};
int hashFunction(char name[]){
 //COMPLETE THE CODE
 int sum = 0;
 for(int i = 0; i < strlen(name); i++){
 	sum += name[i];
 }
 return sum % SIZE;
}

int main(){
	printf("%d ", hashFunction("yve"));
	printf("%d ", hashFunction("pharsa"));
	printf("%d ", hashFunction("estes"));
	printf("%d ", hashFunction("miya"));
	printf("%d ", hashFunction("aulus"));
	printf("%d ", hashFunction("lylia"));
	printf("%d ", hashFunction("gusion"));
	
	return 0;
}
