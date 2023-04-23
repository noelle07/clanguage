#include <stdio.h>

int calls;
int multiple(int n){
	if(n == 4 || n == 3){
    	(calls)++;
    }
    if(n == 0) 
        return 1;
    if(n == 1) 
        return 2;
    if(n % 3 == 0){
//    	(calls)++;  
        return multiple(n - n / 3)+1; 
    }
   
    return multiple(n-1)+n+multiple(n-2)+1;
}

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    int num[n], calls_count[n];
    
    for(int i = 0; i < n; i++){
        int value = 0;
        calls = 0;
        
        scanf("%d", &value);
        num[i] = multiple(value);
        calls_count[i] = calls;
    }
    
    for(int i = 0; i < n; i++){
        printf("Case #%d: %d %d\n", i+1, num[i], calls_count[i]);
    }
    
    
    return 0;
}
//#include <stdio.h>
//
//int multiple(int n, int *calls){
//	if(n == 0) 
//		return 1;
//	if(n == 1) 
//		return 2;
//	if(n % 3 == 0){
//		return multiple(n - n / 3, calls)+1;		
//	}
//
//	if(n % 4 == 0){
//	(*calls)++;
//	}
//	
//	return multiple(n-1,calls)+n+multiple(n-2,calls)+1;
//	(*calls)++;	
//}
//
//int main(){
//	int n;
//	scanf("%d", &n);
//	getchar();
//	int num[n], calls_count[n];
//	
//	for(int i = 0; i < n; i++){
//		int value = 0;
//		int calls = 0;
//		
//		scanf("%d", &value);
//		num[i] = multiple(value, &calls);
//		calls_count[i] = calls;
//	}
//	
//	for(int i = 0; i < n; i++){
//		printf("Case #%d: %d %d\n", i+1, num[i], calls_count[i]);
//	}
//	
//	
//	return 0;
//}

//#include <stdio.h>
//// n --> nilai ke n, *calls --> variabel yg menyimpan berapa banyak yg kelipatan 3 dipanggil
////call juga buat mengevaluasi nilai n-th
//int multiple (int n, int *calls){
//	//kalau n = 0, return 1
//	if(n == 0 )
//		return 1;	
//	//kalau n = 1, return 2
//	if(n == 1)
//		return 2;
//	//n yang kelipatan 3 (bisa habis dibagi 3) --> nilainya nambah 1 saat pointer call dipanggil
//	if(n % 4 == 0)
//		(*calls)++;
//	//n yang keliapatan 5(bisa habis dibagi 5) --> rumusnya n*2
//	if(n % 3 == 0 )
//		return multiple(n-n/3)+1;	
//	//lainnya bakal direturn pake rumus f(n) = f(n-1)+n+f(n-2)+n-2
//	return multiple(n-1,calls)+n+multiple(n-2,calls)+n-2;
//}
//
//int main (){
//	
//	int n;
//	scanf("%d", &n);
//	// array num berisi nilai ke-i dalam penyimpanan
//	int num[n], calls_count[n];
//	
//	for(int i = 0; i < n; i++){
//		//initialized variabel temporary
//		int value = 0, calls = 0;
//		scanf("%d", &value);
//		//nilai ke n diambil dari multiple dan disimpan dalam num array
//		num[i] = multiple(value,&calls);
//		//array calls_count buat nyimpen semua panggilan
//		calls_count[i]= calls ;
//	}
//	//hasil diprint
//	for(int i = 0; i < n; i++){
//		printf("Case #%d: %d %d\n",i+1,num[i],calls_count[i]);
//	}
//	
//	return 0;
//}

//#include<stdio.h>
//
//int count =0;
//
//int fibonacci(int n){
//	if (n==3 ) {
//		count++;
//	}
//	else if (n==4){
//		count++;
//	}
//	
//	if (n==0) return 1;
//	
//	if(n==1) return 2;
//	else if (n%3==0){
//		return  fibonacci (n-n/3)+1;
//	}
//	
//	else {
//		
//		return fibonacci(n-1)+ n + fibonacci(n-2)+1;
//	}
//}
//int main (){
//	int tc;
//	scanf("%d", &tc); getchar();
//	
//	int n;
//	for(int a = 1; a<=tc;a++){
//		
//	scanf("%d", &n); getchar();
//	
//	int result = fibonacci(n);
//	
//	printf("Case #%d: %d %d\n", a, result, count);
//	count =0;
//	
//	}
//	
//	
//	return 0;
//}

