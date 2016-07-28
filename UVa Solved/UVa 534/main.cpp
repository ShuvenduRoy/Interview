#include <algorithm>
#include <cstdio>
#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;


int main()
{
    int node[1000][2];
    double dist[205][205];
    int n,cases=0,a,b;
    while(cin>>n && n)
    {
        for(int i=0; i<n; i++)
        {
            cin>>a>>b;
            node[i][0]=a;
            node[i][1]=b;
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                dist[i][j]= sqrt( pow(node[i][0]-node[j][0],2) + pow(node[i][1]-node[j][1],2) );
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                for(int k=0; k<n; k++)
                {
                    dist[j][k]=min(dist[j][k], max(dist[j][i],dist[i][k]));
                }
            }
        }
//     for(i=0;i<n;i++)
//            for(j=0;j<n;j++)
//                for(k=0;k<n;k++)
//                    dist[j][k]=min(dist[j][k],max(dist[j][i],dist[i][k]));

        printf("Scenario #%d\n",++cases);
        printf("Frog Distance = %.3lf\n\n",dist[0][1]);
    }
}
