#include <iostream>
using namespace std;
long long int b,m;

long long int mod(long long int p)
{
    if(p==0) return 1;
    if(p%2==0)
    {
        int a=mod(p/2);
        return ((a%m)*(a%m))%m;
    }
    else return ((b%m)*mod(p-1)%m)%m;
}

int main()
{
    long long int p;
    while(cin>>b>>p>>m)
    {
        long long int ans=mod(p);
        cout<<ans<<endl;
    }
    return 0;
}
