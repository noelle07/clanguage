#include<stdio.h>

int min;
void searchings(long long num[], int left, int right, long long ask)
{
    if(left<=right)
    {
        int mid=(left+right)/2;
        if(num[mid]==ask)
        {
            if(min>mid)
                min=mid;
        }
        
        if(ask<=num[mid])
            searchings(num, left, mid-1, ask);
        else
            searchings(num, mid+1, right, ask);
    }
}

int main()
{
    int t, n;
    long long num[100005];
    long long q;

    scanf("%d %d", &n, &t);
    for(int i=0; i<n; i++)
    {
        scanf("%lld", &num[i]);
    }
    for(int i=1; i<=t; i++)
    {
        min=100005;
        scanf("%lld", &q);
        searchings(num, 0, n-1, q);
        // printf("Case #%d: ", i);
        if(min==100005)
            printf("-1\n");
        else   
            printf("%d\n", min+1);
    }
    return 0;
}
