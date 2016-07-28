#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <fstream>
#include <limits.h>
#include <math.h>
#define maxi 10000
using namespace std;

typedef struct All{
    int first, second, cost;
} E;

class Kruskal
{
public:
    int parent[maxi];
    int size;
public:
    void initialize(int n)
    {
        for(int i=1; i<=n; i++) parent[i]=i;
        size=n;
    }

    int findSet(int i)
    {
        return parent[i]==i ? i : parent[i]=findSet(parent[i]);
    }

    bool isEqual(int x, int y)
    {
        return findSet(x)==findSet(y);
        return false;
    }

    void Union(int x, int y)
    {
        if(!isEqual(x,y))
        {
            parent[findSet(x)]= findSet(y);
        }
    }

    int getSize()
    {
        return size;
    }
};

int Comp(const E &a, const E &b)
{
    return a.cost<b.cost;
}

vector <E> v;

int main()
{
    int cases;
    cin>>cases;
    for(int test=1; test<=cases; test++)
    {
        int n,m,air_cost,air=0,total=0,from, to, weight;
        v.clear();
        cin>>n>>m>>air_cost;
        Kruskal X;

        for(int i=0; i<m; i++)
        {
            cin>>from>>to>>weight;
            v.push_back(E());
            v[i].first=from;
            v[i].second=to;
            v[i].cost=weight;
        }
        X.initialize(n);
        sort(v.begin(), v.end(), Comp);

        int j=0;
        for(int i=0; i<v.size() && j<n-1 &&v[i].cost<air_cost; i++)
        {
            if(!X.isEqual(v[i].first,v[i].second))
            {
                X.Union(v[i].first,v[i].second);
                total+=v[i].cost;
                j++;
            }
        }
        for(int i=1; i<=n; i++)
        {
            total+=air_cost*(X.parent[i]==i);
            air+=(X.parent[i]==i);
        }
        cout<<"Case #"<<test<<": "<<total<<" "<<air<<endl;
    }
    return 0;
}
