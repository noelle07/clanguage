#include <stdio.h>
//borrowing money
int main(){
	int n,a,sum=0;
	//how many numbers yo want to input
	scanf("%d",&n);
	for(int i=1;i<=n;i++){		
		scanf("%d",&a);
		sum=sum+a;		
	}
	printf("%d\n", sum);
	return 0;
}

