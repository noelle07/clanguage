#include <stdio.h>
void merge(int arr[], int low, int mid, int high)
{
	// misahin atau dibagi 2 array jadi array kiri sama kanan 
	//nentuin size array kiri dan kanan
	int leftSize = mid-low+1;
	int rightSize = high-mid;
	// bikin array untuk menampung bagian kiri dan kanan
	int leftArr[leftSize];
	int rightArr[rightSize];
	// isi array kiri 
	for(int i = 0; i  < leftSize; i++)
	{
		leftArr[i] = arr[low+i];
 	}
	// isi array kanan
	for(int i = 0; i < rightSize; i++)
	{
		rightArr[i] = arr[mid+i+1];
	}
	
	//merge leftArr dan rightArr sambil diurutin
	int leftIdx = 0, rightIdx = 0; //kita lagi liat index ke berapa di leftArr & rightArr
	int arrIdx  = low;
	
	while (leftIdx <  leftSize && rightIdx < rightSize)
	{
		// ngebandingin array kiri dan kanan
		if(leftArr[leftIdx] < rightArr[rightIdx])
		{
			arr[arrIdx] = leftArr[leftIdx];
			leftIdx++;
			arrIdx++;
			// Kalau yang kecil itu ada di array kiri
			// masukkin ke array
			// leftIdx++ supaya ga ush dicek lagi di loop selanjutnya'
			// arrIdx++ supaya next loop kita tidak nimpa value yang barusan kita masukkin ke array
		}
		else
		{
			arr[arrIdx] =  rightArr[rightIdx];
			rightIdx++;
			arrIdx++;
		}
	}
	// kalo di array kiri ada elemen yang belum dimasukkin ke array
	while(leftIdx < leftSize)
	{
		arr[arrIdx] = leftArr[leftIdx];
		leftIdx++;
		arrIdx++;
	}
	while(rightIdx < rightSize)
	{
		arr[arrIdx] = rightArr[rightIdx];
		rightIdx++;
		arrIdx++;
	}
	
}
void mergeSort(int arr[], int low, int high)
{
	if(low>=high) return;

	int mid = (low+high)/2;
	mergeSort(arr, low, mid); //Recursive mergesort buat index yang paling kiri sampe mid
	mergeSort(arr, mid+1, high);//Recursive mergesort buat index tengah+1 sampe high
	merge(arr, low, mid, high);// gabungin sambiil urutin
}
int main()
{
	int n;
	scanf("%d", &n); getchar();
	
	int arr[100001];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]); getchar();
	}
	
	mergeSort(arr,0,n-1);
	
	
	int max = 0;
	for(int i = 0; i < n-1; i++)
	{
		if(arr[i+1]-arr[i] > max) max = arr[i+1] - arr[i];
	}
	
	int more = 0;
	for(int i = 0; i < n-1; i++)
	{
		if(arr[i+1]-arr[i]==max) more++;	
	}
	for(int i = 0; i < n-1; i++)
	{
		if(arr[i+1]-arr[i]==max)
		{
		
			printf("%d %d", arr[i], arr[i+1]);
			if(more != 1)
			{
				printf(" ");
				more--;
			}
			else printf("\n");
		}
	}


	
	return 0;
}
