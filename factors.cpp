#include <stdio.h>

int main(){
	int t;

	scanf("%d", &t);
	getchar();
	
	for(int i = 0; i <= t; i++)
	{
		long long int n;
		long long int count = 0;
		scanf("%lld", &n);
		getchar();		
		
		for(long long int j = 1; j <= n; j++)
		{
			if( n % j == 0){
				++count;
//			printf("%d ", j);
			}	
		}
		printf("Case #%d: %lld\n", i+1, count);

	}
	return 0;
}

