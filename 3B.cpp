#include <stdio.h>
//instant ramen life hack
int main(){
	int t;
	int k,n,m;
	scanf("%d",&t);
	
	for(int i=0;i<t;i++){
	scanf("%d %d %d",&k,&n,&m);
		if(m+n>k){
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
	
	return 0;
}
