#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <fstream>
using namespace std;
int n,m;
int graph[1001][1001];

void dfsUtil(int u, bool visited[], int disc[], int low[], int parent[])
{
    static int time=0;
    visited[u]=true;
    disc[u]=low[u]=++time;

    for(int i=0; i<n; i++)
    {
        if(graph[u][i])
        {
            int v=graph[u][i];
            if(!visited[v])
            {
                parent[v]=u;
                dfsUtil(v,visited,disc,low,parent);

                low[u]=min(low[u],low[v]);

                if(low[v]<=disc[u])
                {
                    graph[u][v]=0;
                }
            }
            else if (parent[u]!=v)
            {
                //graph[v][u]=0;
                low[u]=min(low[u],disc[v]);
            }

        }
    }
}

void dfs()
{
    bool *visited=new bool[n];
    int *disc=new int[n];
    int *low=new int[n];
    int *parent=new int[n];

    for(int i=0; i<n; i++)
    {
        visited[i]=false;
        parent[i]=-1;
    }
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
            dfsUtil(i,visited,disc,low,parent);
    }
}

int main()
{
    //ofstream c_out;
    //c_out.open("ans.txt");
    int cases=0;
    while(cin>>n>>m)
    {
        cases++;
        int a,b;
        if(n==0 && m==0) break;
        int graph[n][n];
        memset(graph,0,sizeof(graph));
        //int g[n][n];
        //memset(g,0,sizeof(g));
        for(int i=0; i<m; i++)
        {
            cin>>a>>b;
            a--;
            b--;
            graph[a][b]=1;
            graph[b][a]=1;
            //g[a][b]=1;
        }
        cout<<cases<<endl<<endl;
        dfs();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(graph[i][j] )//&& g[i][j]
                {
                    cout<<i+1<<" "<<j+1<<endl;
                    //graph[j][i]=0;
                }
            }
        }
        cout<<"#"<<endl;
    }
}
