#include <stdio.h>

int main(){
	int tc;
	int rows, cols, rowCounter, colCounter;
	int n[1005][1005], rowSum[50] = {0}, colSum[50] = {0};
	scanf("%d", &tc);
	for(int i =0; i<tc; i++){
		scanf("%d", &n);	
		for(rowCounter = 0; rowCounter < rows; rowCounter++){
        for(colCounter = 0; colCounter < cols; colCounter++){
            scanf("%d", &n[rowCounter][colCounter]);
        }
    }
    /* Calculate sum of each row and column */
    for(rowCounter = 0; rowCounter < rows; rowCounter++){
        for(colCounter = 0; colCounter < cols; colCounter++){
            /* Add this element in it's row sum */
            rowSum[rowCounter] += n[rowCounter][colCounter];
            /* Add this element in it's column sum */
            colSum[colCounter] += n[rowCounter][colCounter];
        }
    }
     
    /* Print columns sum */
    for(colCounter = 0; colCounter < cols; colCounter++){
        printf("Case #%d : %d\n", tc, colSum[colCounter]);
    }
}
	return 0;
}
