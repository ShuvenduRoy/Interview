#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<int> graph[101];
int n;

void bfs(int root)
{
    vector <int> visited;
    for(int i=0; i<=n; i++)
        visited.push_back(0);

    queue<int> q;
    q.push(root);
    //visited[root]=1;

    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        for(int i=0; i<graph[top].size(); i++)
        {
            int u=graph[top][i];
            if(!visited[u])
            {
                q.push(u);
                visited[u]=1;
            }
        }
    }

    queue<int> p;
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            p.push(i);
        }
    }

    int j=p.size();
    printf("%d",j);
    for(int i=0; i<j; i++)
    {
        cout<<" "<<p.front();
        p.pop();
    }
    printf("\n");
}

int main()
{
    while(scanf("%d",&n) && n)
    {
        for (int i=0;i<101;++i)
            graph[i].clear();
        int m,root;
        while(scanf("%d",&m) && m)
        {
            int a;
            while(scanf("%d",&a) && a)
            {
                graph[m].push_back(a);
            }
        }

        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            scanf("%d",&root);
            bfs(root);
        }
    }
}
