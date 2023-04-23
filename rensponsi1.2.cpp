#include <stdio.h>
#include <string.h>
FILE *fp;
//template
struct plants{
	char namaSiswa[50];
	char namaPlant[50];	
};
//array of structs = punya array dalemnya bbrapa struct
struct plants pl[105];

int searches(int n, char questions[])
{
	for(int i=0; i<n; i++)
	{
		if(strcmp(pl[i].namaSiswa, questions) == 0)
		return i;
	}
	return -1;
}

int main()
{
	int n,t,res;
	char questions[50];
	fp=fopen("testdata.in", "r");
	fscanf(fp, "%d\n", &n);
	for(int i=0; i<n; i++)
	{
		fscanf(fp, "%[^#]#%[^\n]\n", pl[i].namaSiswa, pl[i]);
	}
	fscanf(fp, "%d\n", &t);
	for (int i=1; i<=t; i++)
	{
		fscanf(fp, "%[^\n]\n", questions);
		res=searches(n, questions);
		printf("Case #%d: ",i);
		if(res!=-1)
			printf("%s\n", pl[res].namaPlant);
		else
			printf("N/A\n");
	}
	return 0;
}
