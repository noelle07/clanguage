#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Data{
	int age;
	char name[100];
	struct Data *next;
}*head = NULL, *tail =NULL;

struct Data *createNewData(int age, const char name[]){
	struct Data *node = (struct Data*)malloc(sizeof(struct Data));
	node->age = age;
	strcpy(node->name, name);
	node->next = NULL;
	return node;
}

void pushHead(int age, const char name[]){
	struct Data *node = createNewData(age, name);
	if(head == NULL){
		head = tail = createNewData(age, name);
	}else{
		node->next = head;
		head = node;
	}
}


void pushTail(int age, const char name[]){
	struct Data *node = createNewData(age, name);
	if(head == NULL){
		head = tail = createNewData(age, name);
	}else{
		tail->next = node;
		tail = node;
	}
}

void pushMid(int age, const char name[]){
	struct Data *node = createNewData(age, name);
	if(head == NULL){
		head = tail = createNewData(age, name);
	}else if(head->age > age){
		pushHead(age, name);
	}else if(tail->age <= age){
		pushTail(age, name);
	}else{
		struct Data *current = head;
		while(current->next != NULL && current->next->age < age ){
			
		}
		node->next = current->next;
	current->next = node;
	}
}

struct Data *popHead(){
	if(head == NULL){
		return NULL;
	}else if(head == tail){
		struct Data *temp = head;
		head = tail = NULL;
		return temp;
	}else{
		struct Data *temp = head;
		head = head->next;
		return temp;
	}
}

struct Data *popTail(){
	if(head == NULL){
		return NULL;
	}else{
		struct Data *curr = head;
		while(curr->next != tail){
			curr = curr->next;
		}	
		struct Data *temp = tail;
		curr->next = NULL;
		tail = curr;
		return temp;
	}
}

struct Data *popMid(int age){
	if(head == NULL){
		return NULL;
	}else{
		if(head->age == age){
			popHead();
		}else if(tail->age == age){
			popTail();
		}else{
			struct Data *curr = head;
			while(curr->next != NULL && curr->next->age != age){
				curr = curr->next;
			}
			if(curr->next == NULL)
			return NULL;
			struct  Data *temp = curr->next;
			curr->next = temp->next;
			return temp;
		}
	}
}

void printAll(){
	struct Data *currentPos = head;
	if(head = NULL){
		printf("No Data!!");
	}
	while(currentPos != NULL){
		printf("%s [%d] ", currentPos->name, currentPos->age);
		currentPos = currentPos->next;
	}
}

int main(){

//	pushHead(10, "Piww");
//	pushHead(20, "Hellow");
//	pushHead(30, "Mwehehe");
//	pushHead(40, "Annyeong");
//	pushHead(50, "Konnichiwaaa");	
	
//	popHead();
//	popHead();
	
//	popTail();
//	popTail();

//	popMid(40);	
//	popMid(40);

	printAll();

//	puts("\n============================================\n");

	pushTail(10, "Piww");
	pushTail(20, "Hellow");
	pushTail(30, "Mwehehe");
	pushTail(40, "Annyeong");
	pushTail(50, "Konichiwaaa");
//
//	pushMid(10, "Piww");
//	pushMid(20, "Hellow");
//	pushMid(30, "Mwehehe");
//	pushMid(40, "Annyeong");
//	pushMid(50, "Konichiwaaa");

	printAll();
	
	return 0;
}

