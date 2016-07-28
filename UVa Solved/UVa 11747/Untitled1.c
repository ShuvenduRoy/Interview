#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define Edge pair<int, int>
using namespace std;

vector <pair<int,Edge> > graph;
int parent[1005];
bool notForest[1005];
int n,m;

int findParent(int i)
{
    if(i!=parent[i])

    {
        parent[i]=findParent(parent[i]);
    }

    return parent[i];
}

void Krusral()
{
    int pu,pv,u,v;
    sort(graph.begin(),graph.end());
    for(int i=0; i<m; i++)
    {
        u = graph[i].second.first;
        v = graph[i].second.second;
        pu=findParent(graph[i].second.first);
        pv=findParent(graph[i].second.second);

        if(pu!=pv)
        {
            parent[pu]=parent[pv];
        }
        else
            printf("%d ",graph[i].first);
    }
}

int main()
{
    while(scanf("%d %d",&n, &m) && n+m)
    {
        graph.clear();
        for(int i=0; i<n; i++)
        {
            parent[i]=i;
            notForest[i]=false;
        }
        for(int i=0; i<m; i++)
        {
            int a,b,w;
            scanf("%d %d %d",&a,&b,&w);
            graph.push_back(pair<int,Edge> (w,Edge(a,b)));
            notForest[a]=notForest[b]=true;
        }

        bool flag=false;
        for(int i=0; i<n; i++)
        {
            if(notForest[i]==false) flag=true;
        }
        if(flag==true)
        {
            printf("forest\n");
            continue;
        }

        Krusral();
        printf("\n");
    }
}

