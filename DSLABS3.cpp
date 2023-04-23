#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	char name[100];
	int age;
	int priority;
	Node *next, *prev;
	// Single Link List -> hanya punya next
	// Double Link List -> punya next dan previous
}*head, *tail;

// Initiate Memory
Node *createNode(const char *name, int age, int priority){
	Node *newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->name, name);
	newNode->age = age;
	newNode->priority = priority;
	newNode->next = newNode->prev = NULL;
	return newNode;
}

//Push Head, Tail

/* 12 3 5
Push Head 1
1 12 3 5
*/

void pushHead(Node *temp){
	// Cek apakah dia kosong
	if(!head){// !head sama kayak head == NULL
		head = tail = temp;
	} else{ // linked list sudah ada data
		temp->next = head;
		head->prev = temp; // tambahan satu dari DLL
		head = temp;
	}
}

// Push Tail
void pushTail(Node *temp){
	// Cek apakah dia kosong
	if(!head){
		head = tail = temp;
	} else{
		tail->next = temp;
		temp->prev = tail; // tambahan satu dari DLL
		tail = temp;
	}
}

void print(){
	if(head){ // if(head) setara dengan if (head!= NULL)
    	Node *temp = head;
    	while(temp){
			printf("Name : %s\n", temp->name);
			printf("Age : %d\n", temp->age);
			printf("Priority : %d\n", temp->priority);
			temp = temp->next;
			puts(" ");
		}
	} else{ // Validasi kalau dia gak ada data
		printf("List Kosong\n");
	}	
}

// Pop Head, Tail
void popHead(){
	// Check is it empty
	if(!head){ // gak bisa dipake karna data kosong
	return;
	}
	
	// Check is it one node / data
	else if(head == tail){
		head = tail = NULL;
		free(head); // or free(tail) - bebas
	}
	// Data lebih dari 1
	else {
		Node *candidateHead =  head->next;
		head->next = NULL;
		candidateHead->prev = NULL; // tambahan DLL
		free(head); // or free(tail) - bebas
		head = candidateHead; // memotong hubungan head dengan next agar merubah next menjadi head
							 //  candidate head setelah head
	}
}

// Pop Tail
void popTail(){
	// Check is it empty
	if(!head){ // gak bisa dipake karna data kosong
		return;
	}
	// Data lebih dari 1
	else {
		Node *candidateTail = tail->prev;
		candidateTail->next = NULL; //putus hubungan tail dan candidate tail
		tail->prev = NULL; // tambhan DLL
		free(tail);
		tail = candidateTail;
	}
}


// Pop Mid
// Cek kalo dia kosong apa gak?
void popMid(int target){
	if(!head){
		return;
	} else if(target == head->age){
		popHead();
	} else if(target == tail->age){
		popTail();
	} else {
		Node *curr = head->next;
		while(curr){
			if(curr->age == target){
				// hapus di tengah
				Node *afterCurr = curr->next;
				Node *beforeCurr = curr->prev;
				afterCurr->prev = curr->prev;
				beforeCurr->next = curr->next;
				curr->next = curr->prev = NULL;
				free(curr);
				curr = NULL;
				return;
			}
			curr = curr->next;
		}
	} 
}

void pushMid(Node *temp){
	if(!head){
		head = tail = temp;
	}
	// Check if priority in > head
	else if(temp->priority > head->priority){
		pushHead(temp);
		// Check if priority in < tail
	} else if(temp->priority < tail->priority){
		pushTail(temp);
	} 
	else{
		// Hemat 1 iterasi kalau pake head->next
		// 4 4 3 1
		// temp = 2
		Node *curr = head->next; // curr = current
		while(curr && temp->priority < curr->priority){
			curr = curr->next;
		}
		// logic Insert
		// urus temp
		temp->next = curr;
		temp->prev = curr->prev;
		// urus curr
		(curr->prev)->next = temp; // menunjuk ke temp, reference ke 3
		// ubah node sebelumnya si curr jadi temp
		curr->prev = temp;
	}
}

int main(){
//	pushHead(createNode("Pandora", 18, 2));
//	pushHead(createNode("Naevis", 20, 5));
//	pushHead(createNode("Gumi", 22, 3));
	
//	pushTail(createNode("Pandora", 18, 2));
//	pushTail(createNode("Naevis", 20, 5));
//	pushTail(createNode("Gumi", 22, 3));

	pushMid(createNode("Pandora", 18, 4));
	pushMid(createNode("Naevis", 19, 2));
	pushMid(createNode("Gumi", 14, 2));
	pushMid(createNode("Dandism", 19, 2));
	pushMid(createNode("Luna", 19, 2));

//	popHead();
//	popTail();
	popMid(14);
	
	print();
	
	return  0;
}

// Queue  : FIFO
// pushHead(front), popTail(rear) or pushTail(front), popHead(rear/belakang)

// Priority Queue: (hospital)
// 4 3 2 1
// 4 : urgent
// 3 : High
// 2 : Medium
// 1 : Low
// front and rear
