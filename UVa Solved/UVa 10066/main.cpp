#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int lcs(int *A, int *B, int m, int n)
{
    int L[m+1][n+1];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0 || j==0) L[i][j]=0;
            else if(A[i-1]==B[j-1])
                L[i][j]=L[i-1][j-1]+1;
            else L[i][j]=max(L[i][j-1],L[i-1][j]);
        }
    }
    return L[m][n]
}

int main()
{
    int m,n,A[110],B[110],L[110][110];
    for(int t=1;;t++)
    {
        cin>>m>>n;
        if(m==0 && n==0) break;

        for(int i=0; i<m; i++) cin>>A[i];
        for(int i=0; i<n; i++) cin>>B[i];

        printf("Twin Towers #%d\nNumber of Tiles : %d",t,lcs(A,B,m,n));
    }
    return 0;
}
