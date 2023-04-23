#include <stdio.h>
//lenght
int main(){
	int tc;
	scanf("%d",&tc); 
	for(int i=1;i<=tc;i++){
		long long int n, count=0;
		scanf("%lld",&n);
		
		//iterate at least once, the until n becomes 0
		// remove last digit from n in each iteration
		//increase count by one in each iteration
		do{
			n/=10;
			++count;
		}
		while(n!=0);
		printf("Case #%d: %d\n",i,count);	
	}		
	return 0;
}
//#include <stdio.h>
//
//int main(){
//	int n,count=0;
//	scanf("%d",&n);
//	while(n!=0){
//		n=n/10;
//		count++;
//	}
//	printf("%d",count);
//	return 0;
//}
