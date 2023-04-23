#include <stdio.h>

int main(){
	float x,y;
	scanf("%f %f", &x,&y);
	printf("%.2f%\%", 100*(x-y)/x);
	
	return 0;
}
