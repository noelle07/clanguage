#include <stdio.h>
//countingclocks
int main(){
	int t;
	float a,b,c,d,e,f;
	scanf("%d", &t);
	scanf("%f %f", &a, &b);
	scanf("%f %f", &c, &d);
	scanf("%f %f", &e, &f);
	printf("%.2f\n",(a*b)/360);
	printf("%.2f\n",(c*d)/360);
	printf("%.2f\n",(e*f)/360);
	
	return 0;
}
