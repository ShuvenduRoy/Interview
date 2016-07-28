#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define Edge pair<int,int>
#define Max 100000
using namespace std;

vector <pair<int, Edge> > Graph;
int parent[Max],total;
int findSet(int i, int *parent)
{
    if(i!=parent[i])
        parent[i]=findSet(parent[i],parent);
    return parent[i];
}

int Kruskal(int m)
{
    int pu,pv,total=0;
    sort(Graph.begin(),Graph.end());
    for(int i=0; i<m; i++) parent[i]=i;

    for(int i=0; i<m; i++)
    {
        pu=findSet(Graph[i].second.first,parent);
        pv=findSet(Graph[i].second.second,parent);

        if(pu!=pv)
        {
            total+=Graph[i].first;
            parent[pu]=parent[pv];
        }
    }
    return total;
}

int main()
{
    int n,m,tc,mc,x,y,z;
    while(scanf("%d %d",&n,&m) && (m|n))
    {
        tc=0;
        for(int i=0; i<m; i++)
        {
            cin>>x>>y>>z;
            Graph.push_back(pair <int, Edge> (z, Edge(x,y)));
            tc+=z;
            //Graph.push_back(pair<int, Edge> (z,Edge(x,y)));
        }
        mc=Kruskal(m);
        cout<<tc-mc<<endl;
        Graph.clear();
    }

    return 0;
}
