#include <stdio.h>

int fibonacci(int n)
{
	if(n == 1)
		return 0;
	if(n == 2)
		return 1;
	else
		return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
	int n;
	scanf("%d", &n);
	
	printf("%d\n", fibonacci(n));
	return 0;
}

//1 2 3 4 5 6
//0 1 1 2 3 5
