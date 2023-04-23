// Bubble Sort
#include <stdio.h>

	int arr[] = {14, 6, 23, 18, 7, 47, 2, 83, 16, 38};
	int n=10;
	// untuk mengganti isi ditukarkan dengan posisi yang sebenarnya
	// swap harus menggunakan addres supaya bisa mendeteksi isi dari angka yang dituju
	void swap (int *a, int *b){
		int temp = *a;
		*a = *b;
		*b = temp;
	}
	// Untuk print data
	void Data(){
		for(int x = 0; x < n; x++){
			printf("%d ",arr[x]);
		}
		printf("\n");
	}
	
	void BubbleSort(int *DataArr, int n){
		for(int i = 1; i < n; i++){
			for(int j = n - 1; j <= i; j--){
			// Jika data yang ditampilkan angka pertama > angka selanjutnya maka akan dilakukan swap
				if(DataArr[j-1] > DataArr[j]){
					swap(&DataArr[j-1], &DataArr[j]);
				}
			}
		}		
	}
	
	void bubble_Flag(int *Arr, int n){
		int i,j;
		int flag;
		flag =0; i=1;
		// Untuk mengecek array yang ada sesuai dengan flag atau tidak 
		while ((i<n) && (!flag)){
			flag = 1; 	//jika tidak maka akan masuk ke for yang kedua, jika berhasil di swap maka flag akan kemabali ke 0
			for(j=n-1; j>=i; j--){
				if(Arr[j-1] > Arr[j]){
					swap(&Arr[j-1], &Arr[j]);
					flag = 0;
				}
			}
			i+=1; // while nya diulang sampai batas array maksimal
		}
	}	
	
	int main(){
		// Untuk menampilkan data sebelum sorting
		printf("Before sort:\n");
		Data();		
//		Bubble (arr,n);
		// Untuk menampilkan data setelah sorting
		bubble_Flag(arr,n);
		printf("After sort:\n");
		Data();
		
	return 0;	
	}
	



//// Selection Sort
//#include <stdio.h>
//
//int
	

