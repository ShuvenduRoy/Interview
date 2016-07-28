#include <iostream>
#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <cstring>
#define V 30
int N;

using namespace std;
int minDistance(int dist[], bool isSpt[])
{
    int mini=INT_MAX, index;
    for(int v=0; v<V; v++)
    {
        if(dist[v]<mini && !isSpt[v])
        {
            mini=dist[v], index=v;
        }
    }
    return index;
}

void dijkstra(int graph[V][V],int dist[V], int from)
{
    bool isSpt[V];
    int parent[V];

    for(int i=0; i<V; i++)
        dist[i]=INT_MAX, isSpt[i]=false, parent[i]=-1;

    dist[from]=0;
    for(int count=0; count<V-1; count++)
    {
        int u=minDistance(dist,isSpt);
        isSpt[u]=true;

        for(int v=0; v<V; v++)
        {
            if(graph[u][v]!=-1 && !isSpt[v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
            {
                dist[v]=dist[u]+graph[u][v];
                parent[v]=u;
            }
        }
    }
}

int main()
{
    while(cin>>N && N)
    {
        int Graph1[V][V],Graph2[V][V],dist1[V],dist2[V];
        memset(Graph1,-1,sizeof(Graph1));
        memset(Graph2,-1,sizeof(Graph2));
        char a,b,c,d;
        int w;
        for(int i=0; i<N; i++)
        {
            cin>>a>>b>>c>>d>>w;
            if(a=='Y')
            {
                if(b=='B')
                {
                    Graph1[c-'A'][d-'A']=w;
                    Graph1[d-'A'][c-'A']=w;
                }
                else
                    Graph1[c-'A'][d-'A']=w;
            }
            else
            {
                if(b=='B')
                {
                    Graph2[c-'A'][d-'A']=w;
                    Graph2[d-'A'][c-'A']=w;
                }
                else
                    Graph2[c-'A'][d-'A']=w;
            }
        }
        char y,m;
        cin>>y>>m;
        dijkstra(Graph1,dist1,y-'A');
        dijkstra(Graph2,dist2,m-'A');

        int mini=INT_MAX;
        for(int i=0; i<V; i++)
        {
            if(dist1[i]==INT_MAX || dist2[i]==INT_MAX) continue;
            if(dist1[i]+dist2[i]<mini)
                mini=dist1[i]+dist2[i];
        }

        if(mini==INT_MAX)
        {
            cout << "You will never meet." << endl;
        }
        else
        {
            cout<<mini;
            for(int i=0; i<V; i++)
            {
                if(dist1[i]+dist2[i]==mini)
                {
                    cout<<" "<<char(i+'A');
                }
            }
            cout<<endl;
        }
        //end of while (case number)
    }

    return 0;
}
