#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <queue>
#include <cstring>
#include <cstdio>
#define Max 30
using namespace std;
typedef pair<int,int> ii;
int parent[30];
int graph[Max][Max];
int dist[Max];
int N,K;

void printPath(int from, int to)
{
    if(from==to) {
        cout<<to; return;
    }
    printPath(parent[from], to);
    cout<<" "<<from;
}

void dijkstra(int from)
{

    memset(dist,63,sizeof(dist));
    dist[from]=0;
    memset(parent,-1, sizeof(parent));
    priority_queue <ii, vector <ii> , greater<ii> > MST;
    MST.push(ii(0,from)); // first is the length of SPT, second is last added
    while(!MST.empty())
    {
        ii front=MST.top();      MST.pop(); //taking the top means taking the lowest lost so far
        int spt_length=front.first, u=front.second;
        if(spt_length==dist[u]) //if not it is added in this queue letter
        {
            for(int j=0; j<N; j++)
            {
                if(graph[u][j])
                {
                    if(dist[u]+graph[u][j]<dist[j])
                    {
                        dist[j]=dist[u]+graph[u][j];
                        parent[j]=u;
                        MST.push(ii(dist[j],j));
                    }
                }
            }
        }
    }
}

int main()
{
    int N,cases=1;
    while(scanf("%d",&N) && N)
    {
        memset(parent,-1, sizeof(parent));
        for(int i=1; i<=N; i++)
        {
            int relation, v, w;
            cin>>relation;
            for(int j=0; j<relation; j++)
            {
                cin>>v>>w;
                graph[i][v]=w;
            }
        }
        int s,t;
        cin>>s>>t;
        dijkstra(s);
        printf("Case %d: Path = ",cases++);
        printPath(t,s);
        printf("; %d second delay\n",dist[t]);
    }
}
