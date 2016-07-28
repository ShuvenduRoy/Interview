#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;
#define Edge pair<int,int>
vector <pair <int,Edge> > graph;
int parent[1005];
int n,m,a,b,w;
bool flag;

int findParent(int i)
{
    if(parent[i]!=i)
        parent[i]=findParent(parent[i]);
    return parent[i];
}

int main()
{
    ofstream c_out;
    c_out.open("main.txt");
    while(scanf("%d %d",&n,&m) && n+m)
    {
        graph.clear(); flag=false;
        for(int i=0; i<n; i++) {parent[i]=i;} //initialization;
        for(int i=0; i<m; i++) {scanf("%d %d %d",&a,&b,&w); graph.push_back(pair<int,Edge> (w,Edge(a,b)));}
        int pu,pv;
        sort(graph.begin(),graph.end());
        for(int i=0; i<m; i++) {
            pu=findParent(graph[i].second.first);
            pv=findParent(graph[i].second.second);
            if(pu!=pv) parent[pv]=parent[pu];
            else {
                if(flag) cout<<" ";
                cout<<graph[i].first;
                //printf("%d",graph[i].first);
                flag=true;
            }
        }
        if(!flag) cout<<"forest";//printf("forest");
        cout<<endl; //printf("\n");
    } //end of each test case (while loop)
    return 0;
}
