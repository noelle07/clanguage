#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Level 1 2 3 4 

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
	strcpy(newNode->name,name);
	newNode->age = age;
	newNode->priority = priority;
	newNode->next = newNode->prev = NULL;
	return newNode;
	
}


// Push Head, Tail

//12 3 5
// Push head 1
// = 1 12 3 5
void pushHead(Node *temp){
	// cek apakah dia kosong
	if(!head){ // !head sama kayak head == NULL
			   head = tail = temp;
	} else { // Linked list sdh ada data
		temp->next = head;
		head->prev = temp; // tambahan satu baris DLL
		head = temp;
	}
	
}

// Push tail
void pushTail(Node *temp){
	// cek apakah dia kosong
	if(!head){ // !head sama kayak head == NULL
			   head = tail = temp;
	} else { // Linked list sdh ada data
		tail->next = temp;
		temp->prev = tail; // tambahan satu baris DLL
		tail = temp; 

	}
	
}
void print(){
	if(head){ //if(head) setara dgn if (head != NULL)
		Node *temp = head;
		while(temp){
			printf("Name : %s\n", temp->name);
			printf("Age : %d\n", temp->age);
			printf("Priority : %d\n", temp->priority);
			temp = temp->next;
			puts(" ");
		}
	} else { // validasi kalau dia gk ada data
	
			printf("List kosong\n");
	}
}
// Pop Head, Tail
void popHead(){
	//check is it empty
	if(!head){ // gk bisa di pake karena data kosong
 	return;
	}
	
	// check is it one node/data
	else if(head == tail){
		head = tail = NULL;
		free(head); // or free(tail) - bebas
	}
	// Data more than 1
	else {
		Node *candidateHead = head->next;
		head->next = NULL;
		candidateHead->prev = NULL; // tambahan DLL
		free(head);
		head = candidateHead; // memotong hubungan head dengan next agar merubah next menjadi head
				// candidate head setelah head
	}
}


// Pop Tail
void popTail(){
	//check is it empty
	if(!head){ // gk bisa di pake karena data kosong
 	return;
	}
	
	// check is it one node/data
	else if(head == tail){
		head = tail = NULL;
		free(head); // or free(tail) - bebas
	}
	// Data more than 1
	else {
		// kalau SLL -> kita looping terlebih dahulu
		// Loop sebanyak O(n-1)
		// candidate tail sebelum tail
		Node *candidateTail = tail->prev;
		candidateTail->next = NULL; // putus hubungan tail dan candidateTail
		tail->prev = NULL; // tambahan DLL
		free(tail);
		tail = candidateTail;
}
}


//Pop Mid
// cek kalo dia kosong apa gk
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
			if (curr->age == target){
				// hapus ditengah
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
	 else if (temp->priority > head ->priority){
		pushHead(temp);
	// Check if priority in < tail
	} else if (temp->priority < tail->priority){
		pushTail(temp);
	}
	// check in the middle
	// if head =4
	// tail = 1
	// temp = 2
	else {
		// Hemat 1 iterasi kalau pake head->next
		// 4 4 3 1
		// temp = 2
		Node *curr = head->next; // curr = current 
		while(curr && temp->priority < curr->priority){
			curr = curr->next;
		}
		// Logic Insert
		// urus temp
		temp->next = curr;
		temp->prev = curr->prev;
		// urus curr
		(curr->prev)->next = temp; // menunjuk ke temp , reference ke 3
		// ubah node sebelumnya si curr jadi temp
		curr->prev = temp; 
	}
}

int main(){
//	pushHead(createNode("Denis", 18, 4));
//	pushHead(createNode("Marvin", 19, 2));
	
	pushMid(createNode("Denis", 18, 4));
	pushMid(createNode("Marvin", 19, 2));
	pushMid(createNode("John", 14, 2));
	pushMid(createNode("Yefta", 19, 2));
	pushMid(createNode("Nikita", 19, 2));
	
	popMid(14);
	
//	pushTail(createNode("Rico", 20, 3));
//	pushTail(createNode("Nathan", 23, 1));
	
//	popHead();
//	popHead();
	
//	popTail();
	
	print();
	
	
	return 0;
}
// Queue: FIFO
// pushHead(front), popTail(rear) or pushTail(front), popHead(rear)

//Priority Queue: (hosipital)
// 4 3 2 1
// 4: Urgent
// 3: High
// 2: Medium
// 1: Low
// front and rear


