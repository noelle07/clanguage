#include<stdio.h>
#include<string.h>


struct data{
	char loc1[3940], loc2[3940], type[3940], furnish[3940];
	long int price, rooms, bathroom, carParks, area;
} housing;


int main(){
	FILE* fp = fopen("file(2)).csv","r");
	char test[100];
	char dataX[100], columnName[100];
	if(fp != NULL){
		while(!feof(fp)){
			fscanf(fp,"%[^\;]%s;%d;%d;%d;%s;%d;%s\n", housing.loc1, housing.loc2, &housing.price, &housing.rooms, &housing.bathroom,
			 &housing.carParks, housing.type, &housing.area, housing.furnish);
		}
	}

	
	for(int i = 0; i < 3940; i++){
		printf("%s\n", housing.loc1);
	}
	
	
//	scanf("%s", dataX);
//	scanf("%s", columnName);getchar();
	
	for(int i = 0; i < 3940; i++){
//		if(strcmp(dataX, housing.loc1) == 0) {
//			printf("%s", housing.loc1);
//		}
//		else{
//			printf("error");
//		}
	}
	return 0;
}
