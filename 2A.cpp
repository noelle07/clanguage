#include <stdio.h>
//FINAL SCORE
int main(){
	int a,m,f;
	float result;
	scanf("%d %d %d", &a,&m,&f);
	result = (a*0.2)+(m*0.3)+(f*0.5);
	printf("%.2f\n",result);
	return 0;
}
