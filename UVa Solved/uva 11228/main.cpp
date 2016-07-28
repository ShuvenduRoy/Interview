#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
#define maxi 5000
#define INF 1000000000
using namespace std;

typedef struct all
{
    int first,second;
    double cost;
}E;

class UnionFind
{
public:
    int Parent[maxi];
    int size;
public:
    void Intialize(int n)
    {
        for(int i=0; i<n; i++)
            Parent[i]=i;
    }

    int findSet(int index)
    {
        return Parent[index]==index ? index: (Parent[index]=findSet(Parent[index]));
    }

    bool isEqual(int x, int y)
    {
        if(findSet(x)==findSet(y)) return true;
        else return false;
    }

    void Union(int x, int y)
    {
        if(!isEqual(x,y))
            Parent[findSet(x)]=findSet(y), size--;
    }

    int getSize()
    {
        return size;
    }
};

bool comp(const E &a, const E &b)
{
    return a.cost<b.cost;
}

int testcases;
int cities,state,first,second;
int x[maxi],y[maxi];
vector <E> V;

int main()
{
    int cases=1;
    cin>>testcases;
    while(testcases--)
    {
        V.clear();
        cin>>cities>>state;
        int index=0;
        for(int i=0; i<cities; i++)
        {
            cin>>x[i]>>y[i];
        }

        for(int i=0 ;i<cities; i++)
        {
            for(int j=i+1; j<cities; j++)
            {
                V.push_back(E());
                V[index].first=i;
                V[index].second=j;
                V[index].cost=hypot(x[i]-x[j],y[i]-y[j]);
                index++;
            }
        }
        UnionFind X;
        X.Intialize(cities);
        int stateCounter=1;
        double Roads=0;
        double RailRoads=0;
        sort(V.begin(),V.end(),comp);
        for(int i=0; i<V.size() && X.getSize()>0; i++)
        {
            if(!X.isEqual(V[i].first,V[i].second))
            {
                X.Union(V[i].first,V[i].second);
                if(V[i].cost>state) RailRoads+=V[i].cost, stateCounter++;
                else Roads+=V[i].cost;
            }
        }
        printf("Case #%d: %d %.lf %.lf\n", cases++, stateCounter, Roads ,RailRoads);
    }
}
