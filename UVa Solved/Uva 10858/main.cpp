#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>
using namespace std;

vector <deque<int> > result;

void solve(int n, int div, deque<int> &q)
{
    for(int i=div; i*i<=n; i++)
    {
        if(n%i==0)
        {
            q.push_back(i);
            solve(n/i,i,q);
            q.pop_back();
        }
    }
    q.push_back(n);
    result.push_back(q);
    q.pop_back();
}

int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        deque <int> q;

        result.clear();
        solve(n,2,q);

        printf("%d\n",result.size()-1);
        for(int i=0; i<result.size()-1; i++)
        {
            for(int j=0; j<result[i].size(); j++)
            {
                if(j>0) printf(" ");
                printf("%d",result[i][j]);
            }
            printf("\n");
        }
    }
}
