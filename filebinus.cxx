#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    int tmp;
    int freq[1001];
    // inisiasi frequency
    int iter;
    for(iter = 0;iter<1001; iter++){
        freq[iter] = 0;
    }
    FILE * fp  = fopen("testdata.in","r");
    if(fp == NULL){
        printf("file tidak ada\n");
        return -1;
    }
    fscanf(fp,"%d",&N);
    printf("%d\n",N);
    // int i = 0;
    int j = 0;
    while(!feof(fp)){
        fscanf(fp,"%d",&tmp);
        printf("%d\n",tmp);
        freq[tmp]+=1;
    }
    for(j = 0; j<1001;j++){
        if(freq[j]!=0){
            printf("%d -> %d\n",j,freq[j]);
        }
    }
    fclose(fp);
    return 0;
}