#include<stdio.h>
int main()
{
	int arr[100]={4,12,3,7,1,9,15,6};
	int n_data = 8;
	int temp;
	int i,j;
	// separate even and odd elements
	int even_arr[10], odd_arr[10];
	int even_index = 0, odd_index = 0;

	for (i=0; i<n_data; i++){
		if (arr[i] % 2 == 0){
			even_arr[even_index] = arr[i];
			even_index++;
		}
		else{
			 odd_arr[odd_index] = arr[i];
			 odd_index++;
		}
	} 
	
	// Sort even elements in ascending
	 for (i=0; i < even_index; i++){
	 	for(j = even_index - 1; j > i; j--){
	 		if(even_arr[j] < even_arr[j-1]){
	 			temp = even_arr[j];
	 			even_arr[j] = even_arr[j-1];
	 			even_arr[j-1] = temp;
			 }
		 }
	 	
	 }
	 
	 // Sort odd elements in descanding
	 for (i = 0; i < odd_index; i++){
	 	for(j = odd_index - 1; j > i; j--){
	 		if(odd_arr[j] > odd_arr[j-1]){
	 			temp = odd_arr[j];
	 			odd_arr[j] = odd_arr[j-1];
	 			odd_arr[j-1] = temp;
			 } 
		 }
	}
	// print even and odd elements
	for (i = 0; i < even_index; i++){
		printf("%d ", even_arr[i]);
		
	}
	for (i = 0; i < odd_index; i++){
		printf("%d ", odd_arr[i]);
	}
	return 0;	
}
