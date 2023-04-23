#include <stdio.h>
//Jojo draws triangles
int main(){
	int t;
	scanf("%d",&t);
	for(int w = 0; w < t; w++){
		int row,k=0;
		scanf("%d",&row);
		for (int i = 1; i <= row; i++,k=0) {
      for (int j = 1; j <= row-i; j++) {
         printf(" ");
      }
      while (k != 2 * i - 1) {
         printf("*");
         k++;
      }
      printf("\n");
   }
	}
	
	return 0;
}
