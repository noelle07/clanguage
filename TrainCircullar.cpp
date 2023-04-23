#include <stdio.h>

int main(){
	int m,n;
	scanf("%d %d", &m, &n);
	getchar();
	
// 3 1
// 4 1
// 3 2
// 2 4	
	
	int u, v, counter[100005]={0};
	for(int i=0; i<n; i++){
		scanf("%d %d", &u, &v);
		getchar();
		
		counter[u]++;
		counter[v]++;
	}
	
	int flag = 0;
	for(int i=1; i<=n; i++){
		if(counter[i]!=2){
			flag = 1;
			break;
		}
	}
	
	if(flag ==0)puts("YES");
	else puts("NO");
	
	
	
	
	return 0;
}
