#include <stdio.h>
#include <stdlib.h>
// kalau di bst ga perlu buat rekursi (head and tail)
struct Node{
	int value; // key to compare, remember that left < root and right > root
	// Kita butuh penunjuk kiri dan kanan
	Node *left ,*right; //left andright child
};

Node *createNode(int value){
	Node *newNode = (Node*)malloc(sizeof(Node)); //ibarat kita bikin kotaknya   allocate memory and cast it to Node*
	//takecase itu ada : eksplisit dan implisit
	// implisit = otomatis contoh kita punya float tpi kita pake %d, ntar dia otomatis 3.5 jd 3
	// eksplisit = kita mau ganti dia jadi node bintang
	//Inisialisai
	newNode->value = value; // ibarat kita isi kotaknya   initialize the key
	newNode->left = newNode->right = NULL; // intialize both childs to point to NULL
	return newNode; // return the newly created Node
}	

// di bst ga cukup paramnya int value doang tp bakal ngeloop jd butuh current = Node *root
Node *insertNode(Node *root, int value){
	if(!root){ // jika di posisi sekarang kosong
		return createNode(value);
	} else if(value < root->value){
		root->left = insertNode(root->left, value);
	} else if(value > root->value){
		root->right = insertNode(root->right, value);
	}
	return root;
}

// key selalu unique tpi bisa aja sama/duplicate
// print traversal urut
void inOrder(Node *root){
	if(root){
		inOrder(root->left);
		printf("%d\n", root->value);
		inOrder(root->right);
	}
}

Node *deleteNode(Node *root, int value){
	if(!root){ // cann't find the value that needs to be deleted
		return root; // return unchanged tree
	} else if(value < root->value){
		root->left = deleteNode(root->left value); // enter left subtree
	} else if(value > root->value){
		root->right = deleteNode(root->right, value); // enter right subtree
	} else{ // value == root->value, found the value that needs to be deleted
		// jika dia punya 0 /1 child and 2 child
		// 0/1 child
		if(root->left || root->right){
			// if left child is NULL, new root is right child
			// if right child is NULL, new root is left child
			Node *newRoot = root->left ? root->left : root->right; // jika root->left gada isinya ambil root->left jika gada ambil ke root->right
			root->left = root->right = NULL;
			free(root);
			root = NULL;
			return newRoot;
		}
	}
}

int main(){
	// baseRoot itu root yang paling atas
	Node *baseRoot = NULL; // by default NULL dulu
	baseRoot = insertNode(baseRoot, 40); 
	baseRoot = insertNode(baseRoot, 10); 
	baseRoot = insertNode(baseRoot, 30); 
	
	baseRoot = deleteNode(basRoot, 15);
	inOrder(baseRoot);
	return 0;
}
