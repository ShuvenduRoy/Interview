#include <stdio.h>
#define max(a,b) (a>b)?a:b
int sum[1005][1005];
int SUM(int si,int sj,int ei,int ej)
{
    int res = sum[ei][ej];
    if(sj-1>=0)
        res-=sum[ei][sj-1];
    if(si-1>=0)
        res-=sum[si-1][ej];
    if(si-1>=0&&sj-1>=0)
        res+=sum[si-1][sj-1];
    return res;
}
int main()
{
    int N,m,i,j;
    unsigned long long int total;
    unsigned int cur;
    char newline = 0;
    while(scanf("%d %d",&N,&m)==2)
    {
        if(newline)
            putchar('\n');
        newline=1;
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
                scanf("%d",sum[i]+j);
        for(i=0;i<N;i++)
            for(j=1;j<N;j++)
                sum[i][j]+=sum[i][j-1];
        for(i=0;i<N;i++)
            for(j=1;j<N;j++)
                sum[j][i]+=sum[j-1][i];
        total = 0;
        for(i=0;i<N-m+1;i++)
            for(j=0;j<N-m+1;j++)
            {
                cur = SUM(i,j,i+m-1,j+m-1);
                total+=cur;
                printf("%u\n",cur);
            }
        printf("%llu\n",total);
    }
    return 0;
}
