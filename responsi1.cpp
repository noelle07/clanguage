//// FUNCTION
//#include <stdio.h>
//// global variable = variable ini bisa diakses oleh  semua function
////int a, b, res;
//
////tipe data yang tidak punya return value = void
//
////passing by prefference = passing alamatnya (biasanya swap)
//
//void penjumlahan(int c, int d)// boleh pake c sama d soalnya yg kita passing nilainya aja (passing by value)
//{
//	int res =c+d;
//	printf("%d\n", res);
//}
//
//// fungsi pointer = untuk mengakses alamat/ untuk menampung alamat dari value yang diambil
//void swap (int *a, int *b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//	printf("dari fungsi swap: a=%d b=%d\n", a, b);
//}
//
//int main()
//{
//	// local variable = variable hanya bisa diakses dalam function itu (kalo ini cuma function main)
//	int a, b, res;
//	scanf("%d %d", &a,&b);
//	penjumlahan(a, b);
//	
//	swap(&a, &b);
//	printf("a=%d b=%d\n", a, b);
////	printf("%d\n", res);
//	return 0;
//}

// RECURSIVE = ketika kita miliki sebuah itteration yg berulang2
// RECURSIVE FUNCTION = FUNCTION YG MEMANGGIL DIRINYA SENDIRI
//
//#include <stdio.h>
//
//void prints(int a) // n juga gapapa
//{
//	if(a>0)
//	{
//		printf("%d ", a);
//		// kita decreament
//		prints(a-1);
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
////	for(int i =n ; i>0; i--)
////	{
////		printf("%d ", i);
////	}
//	prints(n);
//	printf("\n");
//	return 0;
//}

//fibonacci

#include <stdio.h>

int fibonacci(int n)
{
	if(n==1)
		return 0;
	if(n==2)
		return 1;
	else 
		return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
	int a=0, b=1, res;
//	printf("%d %d ", a,b);
//	for(int i =3;i<=5;i++)
//	{
//		res=a+b;
//		printf("%d ", res);
//		a=b;
//		b=res;
//		
//	}
	printf("%d\n",fibonacci(5));
	return 0;
}

