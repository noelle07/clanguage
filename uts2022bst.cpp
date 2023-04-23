#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
int key;
struct node *left;
struct node *right;
} *root;
bool search(struct node *curr, int find){
//COMPLETE THE CODE!

	if(curr == NULL){
		return false;
	}
	if(curr->key == find){
		return true;
	}else if(find < curr->key){
		search(curr->left, find);
	} else{
		search(curr->right, find);
	}
}
int heightBinaryTree(struct node *node){
//COMPLETE THE CODE!
	if(node == NULL){
		return 0;
	}
	int heightRight = heightBinaryTree(node->right);
	int heightLeft = heightBinaryTree(node->left);
	
	if(heightLeft > heightRight){
		return heightLeft + 1;
	} else{
		return heightRight + 1;
	}
}

