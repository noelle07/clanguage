#include <stdio.h>

int main(){
//	float a,b,c;
	int a1,b1,c1,d1;
	int a2,b2,c2,d2;
	int a3,b3,c3,d3;
	scanf("%d %d %d %d", &a1,&b1,&c1,&d1);
	scanf("%d %d %d %d", &a2,&b2,&c2,&d2);
	scanf("%d %d %d %d", &a3,&b3,&c3,&d3);
	float a = (a1/1)*2 + (b1/2*4) + (c1/3)*6 + (d1/4)*4;
	float b = (a2/1)*2 + (b2/2*4) + (c2/3)*6 + (d2/4)*4;
	float c = (a3/1)*2 + (b3/2*4) + (c3/3)*6 + (d3/4)*4;
	printf("%.2f\n", a);
	printf("%.2f\n", b);
	printf("%.2f\n", c);
	
	return 0;
}
