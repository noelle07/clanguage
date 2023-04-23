#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	int id; // bakal nentuin posisi
	char name[100];
	// dst.. untuk attributes lain
	Node *left, *right;
};

// Allocate Memory
Node *createNode(int id, const char *name){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->id = id;
	strcpy(newNode->name, name);
	newNode->left = newNode->right = NULL;
	return newNode;
}

// Display data
// Preorder (print recursive kiri kanan)
void preOrder(Node *root){
	if(root){
		printf("%d %s\n", root->id, root->name);
		preOrder(root->left);
		preOrder(root->right);
	}
}

// Inorder (recursive kiri print recursive kanan)
void inOrder(Node *root){
	if(root){
		inOrder(root->left);
		printf("%d %s\n", root->id, root->name);
		inOrder(root->right);
	}
} 

// Pos Order (recursive kiri kanan print)
void posOrder(Node *root){
	if(root){
		posOrder(root->left);
		posOrder(root->right);
		printf("%d %s\n", root->id, root->name);
	}
}

// Insert Delete Update
// Insert
Node *insertData(Node *root, int id, const char *name){
	if(!root){
		// Kalau rootnya kosong
		return createNode(id, name);
	}else if(id < root->id){
		// Kalau id lebih kecil dari root
		root->left = insertData(root->left, id, name);
	}else if(id > root->id){
		// Kalau id lebih besar dari root
		root->right = insertData(root->right, id, name);
	}
}

// Update (change name)
Node *updateData(Node *root, int id, const char *name){
	if(!root){
		// Kalau rootnya kosong
		return createNode(id, name);
	}else if(id < root->id){
		// Kalau id lebih kecil dari root
		root->left = insertData(root->left, id, name);
	}else if(id > root->id){
		// Kalau id lebih besar dari root
		root->right = insertData(root->right, id, name);
	}else{
		// Kalau id nya ketemu/sama
		// root id 123 ada name isinya Marvin
		// Kita ganti dengan Zenli dari parameter name
		strcpy(root->name, name);
	}
	return root;
}

// Delete data
Node *predecessor(Node *root){
	Node *curr = root->left;
	// Looping ke kanan samapai NUll;
	while(curr && curr->right){
		curr - curr->right;
	}
	return curr;
}
Node *deleteData(Node *root, int id){
	if(!root){
		// Kalau rootnya kosong
		return NULL;
	}else if(id < root->id){
		// Kalau id lebih kecil dari root
		root->left = deleteData(root->left, id);
	}else if(id > root->id){
		// Kalau id lebih besar dari root
		root->right = deleteData(root->right, id);
	}else{
		// 2 kondisi kalau data ketemu
		if(!root->left || !root->right){
			Node *newRoot = root->left ? root->left : root->right;
			// If root->left !=NULL newRoot-> root->left
			// else newRoot = root->right
			root->left = root->right =NULL;
			free(root);
			root = NULL;
			return newRoot;
		}else{
			// Ada 2 child yang ada value
			// 1. cari candidate root
			Node *candidate = predecessor(root);
			// 2. copy data dari candidate menuju root
			root->id = candidate->id;
			strcpy(root->name, candidate->name);
			// 3. hapus data candidate
			root->left = deleteData(root->left, candidate->id);
		}
	}
	return root;
}



int main(){
	Node *baseRoot = NULL;
	baseRoot = insertData(baseRoot, 123, "Marvin");
	baseRoot = insertData(baseRoot, 12, "Sejo");
	baseRoot = insertData(baseRoot, 130, "Denis");
	baseRoot = insertData(baseRoot, 128, "Hans");
	baseRoot = insertData(baseRoot, 140, "Marchel");
	inOrder(baseRoot);
//	preOrder(baseRoot);
//	posOrder(baseRoot);

	puts("\nAfter Update:");
	baseRoot = updateData(baseRoot, 123, "Zenli");
	inOrder(baseRoot);
	puts("\nAfter Delete:");
	baseRoot = deleteData(baseRoot, 123);
	preOrder(baseRoot);
	puts("\nAfter Delete All:");
	// pop All
	while(baseRoot){
		baseRoot = deleteData(baseRoot, baseRoot->id);
	}
	inOrder(baseRoot);
	return 0;
}
