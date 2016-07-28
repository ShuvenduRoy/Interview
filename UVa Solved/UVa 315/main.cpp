#include <cstdio>
#include <cstring>
#include <sstream>
#include <iostream>
using namespace std;

int n;
bool vis[100], con[100][100];

void travel(int v)
{
    if (vis[v])
    {
        return;
    }
    vis[v] = true;
    for (int i = 1; i <= n; i++)
    {
        if (con[v][i])
        {
            travel(i);
        }
    }
}

int main()
{
    char s[99];
    while (gets(s))
    {
        sscanf(s, "%d", &n);
        if (!n)
        {
            break;
        }
        memset(con, 0, sizeof(con));
        while (gets(s) && s[0] != '0')
        {
            istringstream ss(s);
            int a, b;
            ss >> a;
            while (ss >> b)
            {
                con[a][b] = con[b][a] = true;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            memset(vis, 0, sizeof(vis));
            vis[i] = true;
            travel(i == 1 ? 2 : 1);
            int ok = 0;
            for (int i = 1; i <= n; i++)
            {
                ok += vis[i];
            }
            ans += (ok != n);
        }
        cout<<ans<<endl;
    }
    return 0;
}
