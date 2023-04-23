#include <stdio.h>
//shopping
int main(){
	float x,y,a,b,p,q,m,n;
	scanf("%f %f", &x,&y);
	scanf("%f %f", &a,&b);
	scanf("%f %f", &p,&q);
	scanf("%f %f", &m,&n);
	printf("%.2f\n", (100*y)/(100-x));
	printf("%.2f\n", (100*b)/(100-a));
	printf("%.2f\n", (100*q)/(100-p));
	printf("%.2f\n", (100*n)/(100-m));
	
	return 0;
}
