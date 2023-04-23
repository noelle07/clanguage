#include<stdio.h>

int main(){
	int t, N, ice[111], kel, luas; // declare testcase, stacks, ice, perimeter and area
	int i,j;
	
	FILE *file;
	file = fopen("testdata.in", "r"); // open the file and read the file
	fscanf(file, "%d\n", &t);  // scan the test case
	
	for(i=1; i<=t; i++){
		luas = 0; kel = 0;
		fscanf(file, "%d\n", &N); // scan the stacks
		for(j=0; j<N; j++){
			fscanf(file, "%d", &ice[j]); // scan the ice
		}
		
		for(j=0; j<N; j++){
			kel = kel + (8*ice[j] - (4*(ice[j]-1))); // calculate the perimeter
			luas = luas + (4*ice[j]); // calculate the area
			
			if(j != N-1){
				
				if(ice[j] <= ice[j+1]){
					
					kel=kel - (4*ice[j]);
					
				}else{
					
				kel=kel - (4*ice[j+1]);
				}
			}
		}
	
	printf("Case #%d: %d %d\n", i, kel, luas); //display the output
	}
	return 0;
}
