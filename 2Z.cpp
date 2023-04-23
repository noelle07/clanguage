#include <stdio.h>
//DIAMOND SUM
int main(){
	int t;
	float a1,b1,c1,d1;
	float a2,b2,c2,d2;
	float a3,b3,c3,d3;
	
	scanf("%d", &t);
	scanf("%f %f %f %f", &a1,&b1,&c1,&d1);
	scanf("%f %f %f %f", &a2,&b2,&c2,&d2);
	scanf("%f %f %f %f", &a3,&b3,&c3,&d3);
//	float a =;
//	float b = ;
//	float c = ;
	printf("%.2f\n", (a1/1)*2+(b1/2)*4+(c1/3)*4+(d1/4)*2);
	printf("%.2f\n", (a2/1)*2+(b2/2)*4+(c2/3)*4+(d2/4)*2);
	printf("%.2f\n", (a3/1)*2+(b3/2)*4+(c3/3)*4+(d3/4)*2);
	
	return 0;
}
