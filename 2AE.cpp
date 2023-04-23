#include <stdio.h>
//WOSU
int main(){
	long int n;
	long int hit;
	long int point=0;
	long int total=0;
	scanf("%ld", &n);
	for(int i= 1; i<=n; i++){
		hit = point+100;
		point=point+50;
		total= total+hit;
	}
	printf("%ld", total);
	
	return 0;
}
