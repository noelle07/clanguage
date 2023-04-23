// Function

#include <stdio.h>

void sum(int a, int b)
{
	int res = a+b;
	printf("%d\n", res);
}

//int sum(int a,int b)
//{
//	return a+b;
//}

int main()
{
	int a, b, res = 0;
	scanf("%d %d", &a, &b);
	getchar();
	
	sum(a, b);
//	res = sum(a,b);
//	printf("%d\n", res);
	
	return 0;
}


//#include <stdio.h>
//
//int main()
//{
//	
//	
//}
