#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int s,p,b, r1,r2,c1,c2,i,j,k;
    cin>>p;
    while(p--)
    {
        cin>>s>>b;
        char map[101][101]={};
        while(b--)
        {
            cin>>r1>>r2>>c1>>c2;
            for(i=r1; i<=r2; i++)
                for(j=c1; j<=c2; j++)
                    map[i][j]=1;
        }
        int length, width, tmp=0, ans=0;
        for(i=0; i<=s; i++)
        {

        }
    }
    return 0;
}
