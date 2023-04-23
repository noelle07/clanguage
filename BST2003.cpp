#include <stdio.h> // untuk input output
#include <stdlib.h> // untuk malloc

// struct yang mempresentasikan sebuah tree
struct node{
	int key; // menyimpan nilai
	struct node *left; //anak kiri
	struct node *right; // anak kanan
};

// fungsi untuk memesan alamat kosong di memori untuk node
// baru yang akan di push ke dalam tre yang ada
struct node *newNode(int x)
{
	// pesan memorinya
	struct node *currNewNode = (struct node*)malloc(sizeof(struct node));
	currNewNode->key = x; //assign nilai
	currNewNode->left = NULL;
	currNewNode->right = NULL;
	
	return currNewNode;
}

// fungsi insert digunakan untuk memasukan/pushdata baru
struct node *insert(struct node *root, int x)//x adalah nilai baru yang kita ingin masukkan
{ 
	if(root == NULL) return newNode(x); // pengecekan apakah root kosong atau tidak, jika kosong maka push
	else if(x < root->key) root->left = insert(root->left, x); //tambah rekursif ke left
	else if(x > root->key) root->right = insert(root->right, x); // tambahkan rekursif ke right
	
	return root;
}

// fungsi untuk mencetak semua node/simpul yang ada dlm sebuah tree
void printAll(struct node *root){
	if(root == NULL) return;
	printAll(root->left); // tambahkan rekursif utk panggil sub tree left
	printf(" %d ", root->key);
	printAll(root->right);// tambahkan rekursif utk panggil sub tree right
}

// fungsi menghapus semua node yg ada dlm Tree
struct node *freeAll(struct node *root){
	if(root == NULL) return NULL;
	root->left = freeAll(root->left);	
	root->right = freeAll(root->right);
	free(root);
	return NULL;	
}

struct node *predecessor(struct node *root){
	struct node *curr = root->left;
	while(curr->right != NULL){ // apakah anak kanannya kosong atau tidak
		curr = curr->right; //maka akan pindah ke kanan
	}	
	return curr;
}

struct node *deleteValue(struct node *root, int x){
	if(root == NULL) return NULL;
	else if(x < root->key) root->left = deleteValue(root->left,x); 
	else if(x > root->key) root->right = deleteValue(root->right,x);
	else{
		if((root->left == NULL) || (root->right) == NULL){
			struct node *temp = NULL;
			if(root->left != NULL) temp = root->left;
			else temp = root->right;
			// Jika data ditemukan, proses delete dilakukan
			// CASE 1
			if(temp == NULL){ //misal menghapus node 3 
				temp = root;
				root = NULL; // maka 3 terhapus
			} 
			// CASE 2
			else{
				// menghapus angka 15 keudian menyambungkan 19 ke 10
				// addres dari 15 akan di gantikan dengan addres dari anak
				// maka 10 akan terkoneksi dengan node 13
				*root = *temp;
			}
			free(temp);
		}
		// CASE 3
		else{
			// precedessor : node terbesar dari sub-tree kiri
			struct node *temp = predecessor(root);
			root->key = temp->key; // ganti nilai root dengan node terbesar dari subtree kiri
			//delete 
			// setelah itu proses delete terjadi di  atau di paling ujung
			// angka 10 akan diganti dengan angka 8
			// dan angka 8 dalam sab-tree kiri right child terhapus(node terbesar dari subtree kiri
			root->left = deleteValue(root->left,temp->key);
		}
	}
	return root;
}

int main(){
	printf("Binary Search Tree\n");
	struct node *root = NULL;// membuat root terlebih dahulu yaitu tree yang masih kosong
	
	root = insert(root, 10);
	root = insert(root, 5);
	root = insert(root, 15);
	root = insert(root, 3);
	
//	root = insert(root, 12);
	root = insert(root, 8);
	root = insert(root, 19);
	printAll(root);
	puts("");
	
	root = deleteValue(root,3);
	
	printAll(root);
	puts("");
	root = deleteValue(root,15);
	printAll(root);
	puts("");
	root = deleteValue(root,10);
	printAll(root);
	puts("");
	return 0;
}
