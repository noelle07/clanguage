#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// using linear probling
//m = table size
int m = 23;
//int counter;
struct tnode{
 char value[10];
 int step;
}*ND[25];
int hashing(const char value[10]){
//complete the code to do hashing using division hashing
int key = 0;
for(int i=0; i<strlen(value); i++){
        key += (int)value[i];
        key = key % m;
    }
    return key;

//function 
//add all the character ASCII in the string
}

struct tnode *newData(const char value[10]){
//complete the code to create a new tnode name ND
struct tnode *N_Data = (struct tnode*)malloc(sizeof(struct tnode));
 strcpy(N_Data->value, value);
 N_Data->step = 0;
 return N_Data;
}
void insert(const char value[10]){
 struct tnode *N_Data = newData(value);
 int key = hashing(value);
// int currentPos = key;
//complete the code to insert new data to hash table. If there
//is any collision, use linear probing to solve it and show ‘TABLE
//IS FULL!!!’ when the hash table is full or the data cannot be
//insert to the table.
 int i = 0;
    while(ND[(key + i) % m] != NULL){
        i++;
        if(i == m){
            printf("TABLE IS FULL!!!\n");
            return;
        }
    }
    ND[(key + i) % m] = N_Data;
    ND[(key + i) % m]->step = i;
}
void view(){
 for(int i=0;i<m;i++){
 if(ND[i]) printf("[%d]\t%s (%d step(s))\n", i, ND[i]->value, ND[i]->step+1);
 else printf("[%d]\tNULL\n", i);
 }
} 
int main(){
 for(int i=0;i<m;i++){
 ND[i] = NULL;
 }

 insert("AAAAA");
 insert("BBBBB");
 insert("CCCCC");
 insert("AAABB");
 insert("BABAA");
 insert("BAABA");
 insert("BBAAA");
 insert("ABBAA");

 view();
 return 0;
}
