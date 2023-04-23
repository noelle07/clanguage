// sum of series
#include <stdio.h>

int main()
{
	long long int a,b;
	scanf("%lld %lld", &a, &b);
	long long int count = 0;
	getchar();
	
	for(long long int i = a; i <= b; i++){
		count += a;
		a++;
	}
	
	printf("%lld\n", count);
	
	return 0;
}
