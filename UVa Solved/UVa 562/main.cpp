#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dp[50005][105];
int cases[105];
int max(int a,int b)
{
	return(a>b)?a:b;
}
int min(int a,int b)
{
	return (a<b)?a:b;
}
int weight(int w,int n)
{
	if(n<0)
		return 0;
	else if(dp[w][n]!=-1)
		return dp[w][n];
	else
		return dp[w][n] = (w>=cases[n])?max(cases[n]+weight(w-cases[n],n-1),weight(w,n-1)):weight(w,n-1);
}
int main()
{
	int i,j,c,top,sum,n;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d",&n);
		top = 0;
		while(top<n)
			scanf("%d",cases+top++);
		sum = 0;
		for(i=0;i<n;i++)
			sum+=cases[i];
		for(i=0;i<=sum/2;i++)
			for(j=0;j<=n;j++)
				dp[i][j]=-1;
		printf("%d\n",sum-2*weight(sum/2,n-1));
	}
	return 0;
}
