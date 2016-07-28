#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    while(1)
    {
        int n;cin>>n;
        unsigned long long int fac=1;
        if(n<0)
        {
            n=-n;
            if((n%2)==1)
            {
                cout<<"Overflow!"<<endl;
            }
            else cout<<"Underflow!"<<endl;
            continue;
        }
        if(n<8) cout<<"Underflow!"<<endl;
        else if(n>13) cout<<"Overflow!"<<endl;
        else
        {
            for(int i=1; i<=n; i++)
            {
                fac*=i;
            }
            cout<<fac<<endl;
        }
    }
    return 0;
}
