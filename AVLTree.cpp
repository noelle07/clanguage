#include <stdio.h>
#include <stdlib.h>

struct Node{
	int value, height, bf; // saran buat height sama balance factor
	Node *left, *right; // punya anak kiri dan anak kanan
};

int max(int a, int b){ // buat nyari tinggi max tree
	return (a >= b) ? a : b; // if(a>=b) return a else return b
}

int getHeight(Node *root){ // buat ambil tingginya
	return root ? root->height : 0; // kalau ada root dia baru root->height else 0
}

int setHeight(Node *root){ // untuk set tinggi yang baru (node yg baru)
	return max(getHeight(root->left),getHeight(root->right))+1; 
}

int setBalanceFactor(Node *root){
	return getHeight(root->left) - getHeight(root->right); // kalau gada fungsi get Height pake ->return root ? getHeight(root->left) - getHeight(root->right) : 0;
}

Node *createNode(int value){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->height = 1;
	newNode->bf = 0; 
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node *updateNode(Node *root){
	root->height =setHeight(root);
	root->bf = setBalanceFactor(root);
	return root;
}

Node *leftRotate(Node *root){
	Node *pivot = root->right;
	Node *temp = pivot->left; //yang berubah anak kririnya pivot
	pivot->left = root;
	root->right = temp;
	root = updateNode(root);
	pivot = updateNode(pivot);
	return pivot;
}

Node *rightRotate(Node *root){
	Node *pivot = root->left;
	Node *temp = pivot->right; //yang berubah anak kririnya pivot
	pivot->right = root;
	root->left = temp;
	root = updateNode(root);
	pivot = updateNode(pivot);
	return pivot;
}

Node *rotation(Node *root){
	if(root->bf > 1){ // unbalanced left child // kalau unbalanced pasti bf nya lebih dari 1
		if(root->left->bf >=0){
			return rightRotate(root); // left child of root is already balanced // not zigzag pattern
		} else{ // left-right rotation -> zigzag pattern
			root->left = leftRotate(root->left); // make it linear pattern
			return rightRotate(root); // then do single rotation
		}
	} else if(root->bf < -1){ //unbalanced right child
		if(root->right->bf <= 0){ // left Rotation
			return leftRotate(root); // right child of root is already balanced // not zigzag pattern
		} else{ // right-left rotation -> zigzag pattern
			root->right = rightRotate(root->right); // make it linear pattern
			return leftRotate(root); // then do single rotation
		}
	}
	return root; // no ratation needed
}

Node *insertNode(Node *root, int value){
	if(!root){
		return createNode(value);
	} else if(value < root->value){
		root->left = insertNode(root->left, value);
	} else if(value > root->value){
		root->right = insertNode(root->right, value);
	}
	return rotation(updateNode(root));
}

Node *predecessor(Node *root){
	Node *curr = root->left;
	
	while(curr->right){
		curr = curr->right;
	}
	return curr;
}

Node *deleteNode(Node *root, int value){
	if(!root){
		return createNode(value);
	} else if(value < root->value){
		root->left = insertNode(root->left, value);
	} else if(value > root->value){
		root->right = insertNode(root->right, value);
	} else{
		if(!root->left || !root->right){
			Node *newRoot = root->left ? root->left : root->right;
			root->left = root->right = NULL;
			free(root);
			root = NULL;
			return newRoot;
		}
		Node *inOrderPredecessor = predecessor(root);
		root->value = inOrderPredecessor->value;
		root->left = deleteNode(root->left, inOrderPredecessor->value);
	}
	return rotation(updateNode(root));
}

void inOrder(Node *root){
	if(root){
		inOrder(root->left);
		printf("|	%-3d	|	%4d		|	%7d		|\n", root->value, root->height, root->bf);
		inOrder(root->right);
	}
}

int main(){
	Node *baseRoot = NULL;
	int toInsert[] = {10, 11, 12, 5, 3, 2, 8, 7, 4};
	
	for(int i = 0; i < 9; i++){
		baseRoot = insertNode(baseRoot, toInsert[i]);
			printf("\nAdded %d from the tree.\n", toInsert[i]);
			printf("|	%-3s	|	%-5s		|	%-14s	|\n", "Key", "Height", "Balance Factor");
			inOrder(baseRoot); 
			getchar();
		}
	for(int i = 0; i < 9; i++){
		baseRoot = insertNode(baseRoot, toInsert[i]);
			printf("\nRemoved %d from the tree.\n", toInsert[i]);
			printf("|	%-3s	|	%-5s		|	%-14s	|\n", "Key", "Height", "Balance Factor");
			inOrder(baseRoot); 
			getchar();
	}
	
	
	return 0;
}
