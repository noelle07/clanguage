#include <stdio.h>

int main(){
	double x;
	double y;
	scanf("%lf %lf", &x,&y);
	double a = x*y/100; //1000 
	double a1 = x + a; // 1000 + 1000 = 2000
	double b = a1*y/100; // 2000 --> 2000
	double b1 = a1 + b; // 1000 + 2000
	double c = b1*y/100; //2000 --> 4000
	printf("%.2lf\n", x+a+b+c);
	
	return 0;
}
