#include <stdio.h>
#include <stdlib.h>

struct Node{
	int id; // bakal nentuin posisi
	Node *left, *right;
};

Node *createNode(int id){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->id = id;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void preOrder(Node *root){
	if(root){
		printf("%d\n",root->id);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(Node *root){
	if(root){
		inOrder(root->left);
		printf("%d\n",root->id);
		inOrder(root->right);
	}
}

Node *insertData(Node *root, int id){
	if(!root){
		// Kalau rootnya kosong
		return createNode(id);
	}else if(id < root->id){
		root->left = insertData(root->left, id);
	}else if(id > root->id){
		root->right = insertData(root->right, id);
	}
}

Node *predecessor(Node *root){
	Node *curr = root->left;
	while(curr && curr->right){
		curr - curr->right;
	}
	return curr;
}
Node *deleteData(Node *root, int id){
	if(!root){
		// Kalau rootnya kosong
		return createNode(id);
	}else if(id < root->id){
		root->left = insertData(root->left, id);
	}else if(id > root->id){
		root->right = insertData(root->right, id);
	}else{
		if(!root->left || !root->right){
			Node *newRoot = root->left ? root->left : root->right;
			root->left = root->right = NULL;
			free(root);
			root = NULL;
			return newRoot;
		}else{
			Node *candidate = predecessor(root);
			root->id = candidate->id;
			root->left = deleteData(root->left, candidate->id);
		}
	}
	return root;
}


int main(){
	Node *baseRoot = NULL;
	baseRoot = insertData(baseRoot, 200);
	baseRoot = insertData(baseRoot, 10);
	baseRoot = insertData(baseRoot, 15);
	baseRoot = insertData(baseRoot, 25);
	inOrder(baseRoot);
	puts("\nAfter Delete:");
	baseRoot = deleteData(baseRoot, 60);
	baseRoot = deleteData(baseRoot, 25);
	baseRoot = deleteData(baseRoot, 15);
	preOrder(baseRoot);
	return 0;
}
