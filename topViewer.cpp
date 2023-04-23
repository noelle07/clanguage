#include <stdio.h>
#include <string.h>
FILE *fp;
//template
struct movies{
	char videoTitle[1005];
	char artistname[1005];
	int viewCount;
};

struct movies mv[105];

void swap(struct movies *a, struct movies *b)
{
	struct movies temp=*a;
	*a=*b;
	*b=temp;
}

void bubbleSort(int n)//kalau saya punya n data, maka membutuhkan n-1 iterasi
{
	for(int i=0; i<n-1; i++) // jumlah iterasi
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(mv[j].viewCount<mv[j+1].viewCount)
			{
				swap(&mv[j], &mv[j+1]);
			}
			else if(mv[j].viewCount==mv[j+1].viewCount)
			{
				if(strcmp(mv[j].videoTitle, mv[j+1].videoTitle)>0)
					swap(&mv[j], &mv[j+1]);
			}
		}
	}
}


int main()
{
	int n = 0;
	fp=fopen("testdata.in", "r");
	// feof (file end of file
	while(!feof(fp))
	{
		fscanf(fp, "%[^#]#%[^#]#%d\n", mv[n].videoTitle, mv[n].artistname, &mv[n].viewCount);
		n++;
	}
	bubbleSort(n);
	for(int i=0; i<n; i++)
	{
		printf("%s by %s - %d\n", mv[i].videoTitle, mv[i].artistname, mv[i].viewCount);
	}
	return 0;
}
