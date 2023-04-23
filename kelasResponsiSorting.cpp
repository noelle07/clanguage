//#include <stdio.h>
//#include <string.h>
//// 1. N string, setiap string cek berapa jumlah karakter yang ada dari kumpulan karakter "binus"
////     jika jumlah sama, maka urutkan berdasarkan alphabet
////  panjang setiap string input maksimum 20
//
//char cekS[6] = "binus";
//
//int isPresent(char c){
//    int i;
//    for(i = 0; i<5; i++){
//        if(cekS[i] == c){
//            return 1;
//        }
//    }
//    return 0;
//}
//int countChar(char s[]){
//    int count=0;
//    int i;
//    for(i = 0;i<strlen(s);i++){
//        if(isPresent(s[i])){
//            count++;
//        }
//    }
//    return count;
//}
//
//int main(){
//    // variable N
//    int N;
//    //menyimpan string input
//    char arrS[100][20];
//    //menyimpan count dari string
//    int countC[100];
//    scanf("%d",&N);
//    int i,j;
//    // input data
//    for(i = 0; i<N;i++){
//        scanf("%s",arrS[i]);
//    }
//    // cek data
//    for(j = 0; j<N; j++){
//        printf("%s\n",arrS[j]);
//    }
//    //cek count dari setiap string
//    for(j = 0; j<N; j++){
//        countC[j] = countChar(arrS[j]);
//    }
//
//    for(j = 0; j<N; j++){
//        printf("%d\n",countC[j]);
//    }
//
//    //sorting
//    for(i = 0; i<N-1;i++){
//        for(j = i+1; j<N;j++){
//            if(countC[j]<countC[i]){
//                int tmp;
//                char tmpS[20];
//                // swap countC
//                tmp = countC[j];
//                countC[j] = countC[i];
//                countC[i] = tmp;
//                // swap string
//                strcpy(tmpS,arrS[j]);
//                strcpy(arrS[j],arrS[i]);
//                strcpy(arrS[i],tmpS);            
//            }else if(countC[j] == countC[i]){
//                if(strcmp(arrS[j],arrS[i])<0){
//                    int tmp;
//                    char tmpS[20];
//                    // swap countC
//                    tmp = countC[j];
//                    countC[j] = countC[i];
//                    countC[i] = tmp;
//                    // swap string
//                    strcpy(tmpS,arrS[j]);
//                    strcpy(arrS[j],arrS[i]);
//                    strcpy(arrS[i],tmpS); 
//                }
//            }
//        }
//    }
//    // cek data lagi
//    for(j = 0; j<N; j++){
//        printf("%s\n",arrS[j],countC[j]);
//    }
//    return 0;
//}

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
