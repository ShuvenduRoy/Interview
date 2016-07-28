#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;
#define Edge pair<int,int>

vector <pair <int, Edge> > graph;
int parent[50000];

int findset(int x)
{
    if(parent[x]!=x)
        parent[x]=findset(parent[x]);
    return parent[x];
}

map <string, int> Map;

int Transform(char *C)
{
    if(Map.find(C) != Map.end())
        return Map[C];
    else
        return Map[C] = Map.size();
}


int kruskal(int n)
{
    int pu,pv;
    sort(graph.begin(),graph.end());
    int total=0;

    for(int i=0; i<n; i++)
    {
        pu=findset(graph[i].second.first);
        pv=findset(graph[i].second.second);

        if(pu!=pv)
        {
            total+=graph[i].first;
            parent[pu]=parent[pv];
        }
    }
    return total;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Map.clear();
        char a[10],b[10];
        int n,m,d;
        cin>>m>>n;

        for(int i=0; i<m ;i++)
        {
            parent[i]=i;
        }

        for(int i=0; i<n; i++)
        {
            scanf("%s %s %d",a,b,&d);
            graph.push_back(pair<int, Edge>(d,Edge(Transform(a),Transform(b))));
        }
        cout<<kruskal(n)<<endl;
        if(t)   puts("");
    }
}
