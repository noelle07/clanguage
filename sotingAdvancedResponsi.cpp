#include <stdio.h>

// buat nuker angka yang sekarang dituker sama yang angka yang bener
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
// buat nyari tempat/ index yang seharusnya
int findPartition(int arr[], int left, int right){
	// contoh yang dijadiion pivot sebelah kanan (kalau mau kiri boleh)
	int pivot = arr[right];
	// index laser selalu sebelum angkanya biar bisa ngecekin angka yg sekarang udh sesuai thdp pivot belum
	int indexLaser = left - 1;
	// kita cek dia dari paling kiri ke paling kanan
	for(int i = left; i < right; i++){
		// buat cek index yang sekarang < pivot 
		if(arr[i] < pivot){
			// biar index lasernya jalan terus
			indexLaser++;
			// kalau ketemu angka yg seharusnya di index laser ntar diswap
			swap(&arr[i], &arr[indexLaser]);
		}
	}	
	// swap angka yang ditempatin index Laser sekarang sama angka bener
	swap(&arr[indexLaser + 1], &arr[right]);
	// indexLaser pindah ke angka selanjutnya
	return indexLaser + 1;
}
// kalo sorting pasti pake array, ini buat liat index paling kiri itu berapa kanan berapa
void quickSort(int arr[], int left, int right){
	// kalo kiri >= kanan dia bakal return 
	if(left >= right) return;
	// yang tadinya index Laser sekarang jadi partition 
	int partition = findPartition(arr, left, right);
	// 15, 14, 17v, 25, 20,  18
	// left right	left	right
	quickSort(arr, left, partition - 1);
	quickSort(arr, partition + 1, right);
}
// size buat ngukur ada berapa index
void printAll(int arr[], int size){
	for(int i = 0; i <= size; i++){
		printf("%d ", arr[i]);
	}
}

int main(){
	int numbers[] = {15, 14, 25, 20, 17, 18};
	int size = 6;
	quickSort(numbers, 0, size - 1);
	printAll(numbers, size - 1);
	
	return 0;
}
