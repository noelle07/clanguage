#include <stdio.h>

int main()
{
	int t;
	int n;
	
	scanf("%d", &t);
	
	for(int i=0; i<t; i++)
	{
		scanf("%d", &n);

	for(int j=1; j<n; j++)
	{
		int num;
//		int count = num;
		scanf("%d", &num);
		printf("%d", num);
		++num;
	}
	
	}
	return 0;
}
