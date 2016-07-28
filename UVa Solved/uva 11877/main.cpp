#include <iostream>

using namespace std;

int main()
{
    int empty,remaining=0,get,ans;
    while(cin>>empty)
    {
        if(empty==0) break;
        remaining=0;
        ans=0;

        while(empty>=3)
        {
            int i=empty/3;
            ans+=i;
            empty-=i*3;
            empty+=i;
        }
        if(empty==2) ans++;
        cout<<ans<<endl;
    }
    return 0;
}
