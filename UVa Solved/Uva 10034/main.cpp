#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
double sum;
double p[100][2];

void dikjstra()
{
    double ax,min;
    double dist[100];
    bool visited[100];
    memset(visited,0,sizeof(visited));
    for(int i=0; i<100; i++) dist[i]=1000000.0;
    dist[0]=0;
    int v=0;
    sum=0;

    while(!visited[v])
    {
        visited[v]=1;
        sum+=dist[v];
        for(int i=0; i<n ; i++)
        {
            if(!visited[i])
            {
                ax=sqrt(pow(p[v][0]-p[i][0],2)+pow(p[v][1]-p[i][1],2));
                if(dist[i]>ax) dist[i]=ax;
            }
        }

        min=1000000.0;
        for(int i=0 ; i<n; i++)
        {
            if(!visited[i])
            {
                if(dist[i]<min)
                {
                    min=dist[i];
                    v=i;
                }
            }
        }
    }
    printf("%.2f\n",sum);
}

int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        double a,b;
        cin>>n;
        for(int j=0; j<n; j++)
        {
            cin>>a>>b;
            p[j][0]=a;
            p[j][1]=b;
        }
        dikjstra();
        if(i!=t-1) cout<<endl;
    }
    return 0;
}
