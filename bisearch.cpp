#include<stdio.h>
void swap (int *a, int *b){

	int temp = *a;
    *a = *b;
    *b = temp;
}

int pratition (int arr[], int left, int right){
    int pivot = arr[right];
    int il = left-1;
    
    for(int i = left;i<right;i++){
        if(arr[i]< pivot){
            il++;
    swap(&arr[i], &arr[il]);
        }
    }
    swap(&arr[il+1], &arr[right]);
    return il++;
}
void quicksort(int arr[], int left, int right){
    if (left>= right) return ;
    int findpratition = pratition (arr,  left,right);
    quicksort(arr,left,findpratition-1);
    quicksort(arr,findpratition+1,right);
}
int print(int arr[], int size){
    for(int i=1;i<= size; i++){
        printf("%d\t", arr[i]);
    }
}
int main (){
    int arr[]={14, 1, 70, 2, 9};
    
    quicksort(arr,0,5);
    print(arr,5);
    return 0;
}
