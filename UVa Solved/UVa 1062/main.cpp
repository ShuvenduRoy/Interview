#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
#include <cstring>
using namespace std;

int n,t=0;
char inp[1500];
stack <char> empty;
vector <stack<char> > container;

int addToStack(int i)
{
    for(int j=0; j<container.size(); j++)
    {
        if(inp[i]<=container[j].top())
        {
            container[j].push(inp[i]);
            return 0;
        }
    }
    container.push_back(empty);
    container[container.size()-1].push(inp[i]);
    return 1;
}

int main()
{
    while(gets(inp) && strcmp(inp, "end")!=0)
    {
        t++;
        container.clear();
        int n=strlen(inp);

        int ans=0;
        for(int i=0; i<n; i++)
        {
            ans+=addToStack(i);
        }
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
