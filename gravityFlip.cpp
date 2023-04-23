//#include <stdio.h>
//
//void conquer (int a, int left[], int mid[], int right[]){
//	int temporary[right-left+1];
//	int firstArrayIndex = left;
//	int secondArrayIndex = mid + 1;
//	int temporaryArrayIndex = 0;
//	
//	while (firstArrayIndex <= mid && secondArrayIndex <= right){
//		if (a[firstArrayIndex] < a[secondArrayIndex]){
//			do{
//				temporary[temporaryArrayIndex++] = a[firstArrayIndex++];
//			}
//		}
//		else {
//			do{
//				temporary[temporaryArrayIndex++] = a[secondArrayIndex++];
//			}
//		}		
//	}
//	for (int i = 0; i <= temporaryArrayIndex; i++){
//		a[i + left] = temporary [i];
//	}
//}
//
//void divide (int a, int left[], int mid[], int right[]){
//	if (left != right){
//		int mid = left + (right - left) / 2;
//        divide(a, left, mid);
//        divide(a, mid + 1, right);
//        conquer(a, left, mid, right);
//    }
//}
//
//int main(){
//	int n;
//    scanf("%d", &n);
//    int a[n];
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &a[i]);
//    }
//    
//    divide(a, 0, n - 1);
//    for (int i = 0; i < n; i++)
//    {
//        // last element?
//        printf(i == n - 1? "%d\n" : "%d ", a[i]);
//    }
//	
//	return 0;
//}

#include <stdio.h>

void conquer(int a[], int leftmost, int mid, int rightmost) 
{
    int temporary[rightmost - leftmost + 1];
    int firstArrayIndex = leftmost;
    int secondArrayIndex = mid + 1;
    int temporaryArrayIndex = 0;

    while (firstArrayIndex <= mid && secondArrayIndex <= rightmost) 
    {
        if (a[firstArrayIndex] < a[secondArrayIndex]) 
        {
            temporary[temporaryArrayIndex++] = a[firstArrayIndex++];
        } 
        else 
        {
            temporary[temporaryArrayIndex++] = a[secondArrayIndex++];
        }
    }

    while (firstArrayIndex <= mid) 
    {
        temporary[temporaryArrayIndex++] = a[firstArrayIndex++];
    }

    for (int i = 0; i < temporaryArrayIndex; i++) 
    {
        a[i + leftmost] = temporary[i];
    }
}

void divide (int a[], int leftmost, int rightmost) 
{
    if (leftmost != rightmost)
    {
        int mid = leftmost + (rightmost - leftmost) / 2;
        divide(a, leftmost, mid);
        divide(a, mid + 1, rightmost);
        conquer(a, leftmost, mid, rightmost);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    divide(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        // last element?
        printf(i == n - 1? "%d\n" : "%d ", a[i]);
    }
    
    return 0;
}
