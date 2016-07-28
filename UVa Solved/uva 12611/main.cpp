#include<iostream>
#include<cstdio>

using namespace std;
main()
{
    int t;
    cin>>t;
    int c=1;
    for(int i=0;i<t;i++)
    {
        int r;
        cin>>r;
        int l=5*r;
        int w=3*r;
        int xl=(9*l)/20;
        int xr=(11*l)/20;
        int w_m=w/2;
        printf("Case %d:\n",c);
        printf("-%d %d\n",xl,w_m);
        printf("%d %d\n",xr,w_m);
        printf("%d -%d\n",xr,w_m);
        printf("-%d -%d\n",xl,w_m);
        c++;
    }
    return 0;
}
