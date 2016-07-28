#include <iostream>

using namespace std;

int main()
{
    int t; cin>>t;
    for(int c=0; c<t; c++)
    {
        int empty;
        int x,y,n,ans=0;
        cin>>x>>y>>n;
        empty=x+y;

        while(empty>=n)
        {
            int z=empty/n;
            int m=empty%n;
            empty-=z*n;
            empty+=z;
            ans+=z;
        }
        //if(empty==n-1)
            //ans++;
        cout<<ans<<endl;
    }
}
