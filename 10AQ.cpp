#include <stdio.h>

int main(){
	long int t;
	scanf("%ld", &t);
	getchar();
	for(int a = 1; a <= t; a++){
		long long int n, temp, reverse,result=0;
		scanf("%lld", &n);
		temp = n;
		do{
			reverse = temp % 10;
			result = result*10+reverse;
			temp= temp / 10;
		}
		while(temp != 0);
		printf("Case #%ld: %lld\n", a, result+n);
	}
	
	return 0;
}
