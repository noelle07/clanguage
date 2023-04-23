#include <stdio.h>

int main(){
	double l,b,h;
	scanf("%lf %lf %lf", &l,&b,&h);
	printf("%.3lf", (b*h)+(b+b+b)*l);
	
	return 0;
}
