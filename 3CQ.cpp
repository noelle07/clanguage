#include <stdio.h>
// BITSHIFTING
int main(){
	int t;
	scanf("%d", &t);
	int a,b,c,d,e,f;
	scanf("%d %d",&a,&b);
	scanf("%d %d",&c,&d);
	scanf("%d %d",&e,&f);
	printf("%d\n", ((a/b)<<b));
	printf("%d\n", ((c/d)<<d));
	printf("%d\n", ((e/f)<<f));
	
	return 0;
}
