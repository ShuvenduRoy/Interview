#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define Edge pair<int,int>
using namespace std;
vector < pair<int,Edge> > graph;
int parent[1000005];
int n,m,a,b,w;

int findParent(int i)
{
    if(i!=parent[i])
        parent[i]=findParent(parent[i]);
    return parent[i];
}

int Kruskal()
{
    int pu,pv;
    sort(graph.begin(),graph.end());
    int max=-1;
    for(int i=0; i<m; i++) {
        pu=findParent(graph[i].second.first);
        pv=findParent(graph[i].second.second);
        if(pv!=pu){
            parent[pv]=parent[pu];
            if(graph[i].first>max) max=graph[i].first;
        }
    }

    return max;
}

int main()
{
    while(scanf("%d %d",&n,&m) && n+m)
    {
        bool flag=false;
        vector<int> edge[n];
        queue <int> q;
        bool visited[n];
        for(int i=0; i<n ;i++) { parent[i]=i; visited[i]=false; }
        graph.clear();
        for(int i=0; i<m ;i++) {
            scanf("%d %d %d",&a, &b, &w);
            graph.push_back(pair <int,Edge> (w,Edge(a,b)));
            edge[a].push_back(b); edge[b].push_back(a);
            if(i==0) { q.push(a); visited[a]=true; }
        }

        while(!q.empty())
        {
            int top=q.front(); q.pop();
            for(int i=0; i<edge[top].size(); i++) {
                    int v=edge[top][i];
                if(!visited[v]) {
                    q.push(v);
                    visited[v]=true;
                }
            }
        }

        for(int i=0; i<n; i++) {
            if(!visited[i]){
                printf("IMPOSSIBLE\n");
                flag=true;
                break;
            }
        }
        if(flag) continue;
        printf("%d\n",Kruskal());
    }
    return 0;
}
