#include <stdio.h>
#include <string.h>

	char checkS[6] = "binus";
	
	int isPresent (int c){
		int i;
		for(i = 0; i < 5; i++){
			if(checkS[i] == c){
					return 1;
			}
		
		}return 0;
	}
	


int countChar(char s[]){
	int count = 0;
	int i;
	for(i = 0; i < strlen(s); i++){
		if(isPresent(s[i])){
			count ++;
		}
		
	}return count;
}

int main(){
	int n;
	char arrS[100][20];
	int countC[100];
	scanf("%d", &n);
	int i, j;
	for(i = 0; i<n;i++){
		scanf("%s", arrS[i]);
		
	}
	for(j=0;j<n;j++){
		printf("%s", arrS[j]);
	}
	for(j=0;j<n;j++){
		countC[j]==countChar(arrS[j]);
	}
	for(j=0;j<n;j++){
		printf("%d\n", countC[j]);
	}
	
	for(int i = 0; i <n-1; i++){
		for(j=i+1; j<n;j++){
			if(countC[j]<countC[i]){
				int temp;
				int tempS[20];
				temp = countC[j];
				countC[j]=countC[i];
				countC[i]=temp;
				
				//swap string
				
				strcpy(tempS,arrS[j]);
                strcpy(arrS[j],arrS[i]);
                strcpy(arrS[i],tempS);
			}
			else if(countC[j]=countC[i]){
				int temp;
				int tempS[20];
				temp = countC[j];
				countC[j]=countC[i];
				countC[i]=temp;
				
				//swap string
				
				strcpy(tempS, countC[j]);
				strcpy(countC[j],countC[i]);
				strcpy(countC[i],tempS);
			}
			}
		}
		for(int j = 0; j<n; j++){
			printf("%s",countC[j]);
		}
		return 0;
	}
}

