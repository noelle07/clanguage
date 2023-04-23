#include <stdio.h>

int function(int x){
	if(x==0)
		return 0;
	else
		return function(x-1)+1;
}; 

int main(){
	int x;
	scanf("%d",&x);
	getchar();
	printf("%d",function(x));
	
	return 0;
}
