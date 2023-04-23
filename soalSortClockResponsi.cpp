#include <stdio.h>
#include <string.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int findPartition(int hour[], int minute[], int left, int right){	
	int pivot = hour[right];
	int indexLaser = left - 1;
	
	for(int i = left; i < right; i++){
		if(hour[i] < pivot){
			indexLaser++;
			swap(&hour[i], &hour[indexLaser]);
			swap(&minute[i], &minute[indexLaser]);
		}
		else if(hour[i] == pivot && minute[i] < minute[right]){
			indexLaser++;
			swap(&hour[i], &hour[indexLaser]);
			swap(&minute[i], &minute[indexLaser]);
		}
	}	
	swap(&hour[indexLaser + 1], &hour[right]);
	swap(&minute[indexLaser + 1], &minute[right]);
	return indexLaser + 1;
}

void quickSort(int hour[], int minute[], int left, int right){ 
	if(left >= right) return;
	int partition = findPartition(hour, minute, left, right);
	quickSort(hour, minute, left, partition - 1);
	quickSort(hour, minute, partition + 1, right);
}

void printAll(int hour[],int minute[], int size){
	for(int i = 0; i <= size; i++){
		printf("%02d:%02d\n", hour[i], minute[i]);
	}
}

int main(){
	int t;
	scanf("%d", &t);
	getchar();
	
	int hour[t];
	int minute[t];
	
	for(int i = 0; i < t; i++){
		char aa[3];
		
		scanf("%02d:%02d %s", &hour[i], &minute[i], aa);
		getchar();
		
		if(strcmp (aa, "pm") == 0){
			hour[i] += 12;
			
		}
	}
	quickSort(hour, minute, 0, t-1);
	printAll(hour, minute, t-1);
	
	return 0;
}

//5
//07:00 am
//02:00 pm
//08:20 am
//04:00 pm
//11:20 am
