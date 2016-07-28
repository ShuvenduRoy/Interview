#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <limits.h>
#include <map>
#define Edge pair<string,string>
using namespace std;
vector <pair <int, Edge> > graph;
map <string,string> parent;
int n,m,w;
string a,b,start,stop;

string findParent(string i)
{
    if(parent[i]!=i)
        parent[i]=findParent(parent[i]);
    return parent[i];
}

int Kruskal()
{
    int minValue=INT_MAX;
    sort(graph.begin(),graph.end());
    for(int i=m-1; i>=0; i--) {
        string pu=findParent(graph[i].second.first);
        string pv=findParent(graph[i].second.second);

        if(pu!=pv){
           parent[pu]=parent[pv];
           if(graph[i].first<minValue) minValue=graph[i].first;
        }
        if(findParent(start)==findParent(stop)) break;
    }
    return minValue;
}

int main()
{
    int cases=0;
    while(scanf("%d %d",&n,&m) && n+m)
    {
        graph.clear();
        parent.clear();
        cases++;

        for(int i=0; i<m; i++) {
            cin>>a>>b>>w;
            graph.push_back(pair <int,Edge> (w,Edge(a,b)));
            parent[a]=a;
            parent[b]=b;
        } // end of taking input
        cin>>start>>stop;

        printf("Scenario #%d\n", cases);
        printf("%d tons\n\n", Kruskal());
    }
    return 0;
}
