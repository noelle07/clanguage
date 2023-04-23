#include <stdio.h>
//skydiving
int main(){
	char n1[101],n2[101];
	float t1,t2;
	int u1,u2;
	
	scanf("%s %f %d %s %f %d", &n1,&t1,&u1, &n2,&t2,&u2);
	printf("Name 1 : %s\n", n1);
	printf("Height 1 : %.2f\n",t1);
	printf("Age 1 : %d\n", u1);
	printf("Name 2 : %s\n", n2);
	printf("Height 2 : %.2f\n",t2);
	printf("Age 1 : %d\n", u2);
	
	return 0;
}
