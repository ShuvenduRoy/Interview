#include<bits/stdc++.h>
using namespace std;
long long int area,maxi,n,m,k,arr2[105],arr[105][105];
void kadane(long long int j)
{
    long long int a,l,i;
    //area=0;
    for(l=1; l<=m; l++)
    {
        a=0;
        for(i=l; i<=m; i++)
        {
            a+=arr2[i];
            if(a<=k && (i-l+1)*j>area)
            {
                maxi=a;
                area=(i-l+1)*j;
            }
            else if((i-l+1)*j==area && a<maxi)
            {
                maxi=a;
            }
            else if(a>k)
                break;
        }
    }
    //return maxi;
}
int main()
{
    long long int t,T,i,j,l,a,b;
    scanf("%lld",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld %lld %lld",&n,&m,&k);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                scanf("%lld",&arr[i][j]);
            }
        }
        maxi=0;
        area=0;
        for(l=1; l<=n; l++)
        {
            memset(arr2,0,sizeof arr2);
            for(i=l; i<=n; i++)
            {
                for(j=1; j<=m; j++)
                    arr2[j]+=arr[i][j];
                kadane(i-l+1);
            }
        }
        printf("Case #%lld: %lld %lld\n",t,area,maxi);
    }
    return 0;
}

