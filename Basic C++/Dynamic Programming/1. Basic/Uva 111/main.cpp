#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n,a,b;
int ori[50],tmp[50],table[50][50];

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        ori[a-1]=i;
    }
    while(1)
    {
        for(int i=0; i<n;i++)
        {
            if(scanf("%d",&a)!=1)
                return 0;
            tmp[a-1]=i;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n ;j++)
            {
                if(ori[i-1]==tmp[j-1])
                    table[i][j]=table[i-1][j-1]+1;
                else table[i][j]=max(table[i-1][j],table[i][j-1]);
            }
        }
        cout<<table[n][n]<<endl;
    }
    return 0;
}
