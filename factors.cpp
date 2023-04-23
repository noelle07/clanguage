#include <stdio.h>

int main(){
	int t;
	scanf("%d", &t);
	getchar();
	
	for(int i = 0; i <= t; i++)
	{
		long long int n;
		long long int count = 0;
		scanf("%d", &n);
		getchar();
		
//		printf("Case #%d: ", i+1);
		
		for(int j = 1; j <= n; j++)
		{
			if( n % j == 0){
				++count;
			}	
		}
		printf("Case #%d: %lld\n", i+1, count);

	}
	return 0;
}
