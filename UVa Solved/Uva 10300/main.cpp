#include <iostream>

using namespace std;

int main()
{
    int t; cin>>t;
    for(int d=0; d<t; d++)
    {
        int n,a,b,c,ans=0;cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>a>>b>>c;
            ans+=a*c;
        }
        cout<<ans<<endl;
    }
    return 0;
}
