#include <stdio.h>
//PERCENTAGE
int main(){
	int t;
	scanf("%d", &t);
	float p1,n1,p2,n2,p3,n3;
	scanf("%f %f", &p1, &n1);
	scanf("%f %f", &p2, &n2);
	scanf("%f %f", &p3, &n3);
	
	printf("%.2f\n", p1/100*n1);
	printf("%.2f\n", p2/100*n2);
	printf("%.2f\n", p3/100*n3);
	
	return 0;
}
