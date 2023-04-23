#include<stdio.h>

int main (){
    
    int test;
    
    scanf("%d", &test); getchar();
    
    
    for(int a = 0 ; a <=test ; a++){
        int angka;
    
    int count =0;
        scanf("%d", &angka); getchar();
    
    for (int b = 1 ; b <= angka; b++){
        
        if (angka%b==0){
            ++count;
        }
    }
    printf("Case %d: %d\n", a+1, count);
    }
    
    return 0;
}
