#include <stdio.h>
//thermostater
int main(){
	int t;
	double a,b,c;
	scanf("%d",&t);
	scanf("%lf", &a);
	scanf("%lf", &b);
	scanf("%lf", &c);
	
	printf("%.2lf %.2lf %.2lf\n",a*4/5,a*9/5+32,a+273);
	printf("%.2lf %.2lf %.2lf\n",b*4/5, b*9/5+32,b+273);
	printf("%.2lf %.2lf %.2lf",c*4/5,c*9/5+32,c+273);
	
	return 0;
}
