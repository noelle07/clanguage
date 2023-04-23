#include <stdio.h>
//basic in out
int main(){
	char s[101];
	int a;
	scanf("%[^\n]", &s); getchar();
	scanf("%d", &a); getchar();
	printf("%s\n", s);
	printf("%d\n", a);
	
	return 0;
}
//kalo char harus pake array [101] 
//[^\n] = baca sampe enter cukup di scanf aja 
//getchar buat ngambil semua kalimat smpe spasi-spasinya
