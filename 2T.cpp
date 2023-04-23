#include <stdio.h>
//bibi class schedule
int main(){
	char c1[100],c2[100],c3[100],c4[100],c5[100];
	int h1,m1,h2,m2;
	int h3,m3,h4,m4;
	int h5,m5,h6,m6;
	int h7,m7,h8,m8;
	int h9,m9,h10,m10;
	
	scanf("%s %02d:%02d-%02d:%02d",&c1,&h1,&m1,&h2,&m2);
	scanf("%s %02d:%02d-%02d:%02d",&c2,&h3,&m3,&h4,&m4);
	scanf("%s %02d:%02d-%02d:%02d",&c3,&h5,&m5,&h6,&m6);
	scanf("%s %02d:%02d-%02d:%02d",&c4,&h7,&m7,&h8,&m8);
	scanf("%s %02d:%02d-%02d:%02d",&c5,&h9,&m9,&h10,&m10);
	
	printf("%s %02d:%02d-%02d:%02d\n",c1,h1-1,m1,h2-1,m2);
	printf("%s %02d:%02d-%02d:%02d\n",c2,h3-1,m3,h4-1,m4);
	printf("%s %02d:%02d-%02d:%02d\n",c3,h5-1,m5,h6-1,m6);
	printf("%s %02d:%02d-%02d:%02d\n",c4,h7-1,m7,h8-1,m8);
	printf("%s %02d:%02d-%02d:%02d\n",c5,h9-1,m9,h10-1,m10);
	return 0;
}
