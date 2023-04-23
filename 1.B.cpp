#include <stdio.h>
//late night counting
int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	for(int i=1;i<=m;i++){
		printf("%d\n", n);
		n++;
	}
	return 0;
}

// kalau i<=m brati di mulai dari 1 
// yang kita print itu n karena kita mulai dari angka 1
// n nya kita ++ in biar dia jalan smpe batas m nya smpe berapa
