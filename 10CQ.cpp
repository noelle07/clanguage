#include <stdio.h> 

int cut(long int);
    
int main(){
    long int t;
    long int x;
    scanf("%ld", &t);
    getchar();
    for(long int a = 1; a <= t; a++){
        scanf("%ld", &x);
        getchar();
        printf("Case %ld:", a);
        long int n2;
        for(long int i = 1;i <= x; i++){
            n2 = cut(i);   
			printf(" %ld", n2);
        }		
        printf("\n");
    }
    
return 0;
}

int cut(long int n){
        long int  x = n - 1;
        return (x * x + x + 2) / 2;
        return 0;
    } 
