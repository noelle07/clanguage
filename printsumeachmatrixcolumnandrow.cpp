#include <stdio.h>
 
int main(){
    int rows, cols, rowCounter, colCounter;
    int inputMatrix[50][50], rowSum[50] = {0}, colSum[50] = {0};
    printf("Enter size of a matrix\n");
    scanf("%d %d", &rows, &cols);
     
    printf("Enter matrix of size %dX%d\n", rows, cols);
    /* Input matrix */
    for(rowCounter = 0; rowCounter < rows; rowCounter++){
        for(colCounter = 0; colCounter < cols; colCounter++){
            scanf("%d", &inputMatrix[rowCounter][colCounter]);
        }
    }
    /* Calculate sum of each row and column */
    for(rowCounter = 0; rowCounter < rows; rowCounter++){
        for(colCounter = 0; colCounter < cols; colCounter++){
            /* Add this element in it's row sum */
            rowSum[rowCounter] += inputMatrix[rowCounter][colCounter];
            /* Add this element in it's column sum */
            colSum[colCounter] += inputMatrix[rowCounter][colCounter];
        }
    }
     
    /* Print rows sum */
    for(rowCounter = 0; rowCounter < rows; rowCounter++){
        printf("Sum of row number %d is %d\n",
            rowCounter, rowSum[rowCounter]);
    }
    printf("\n");
    /* Print columns sum */
    for(colCounter = 0; colCounter < cols; colCounter++){
        printf("Sum of column number %d is %d\n",
            colCounter, colSum[colCounter]);
    }
     
    return 0;
}
