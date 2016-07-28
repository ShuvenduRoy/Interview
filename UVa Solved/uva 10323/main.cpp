#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    while(1)
    {
        int n;cin>>n;
        double fac=1;
        for(int i=1; i<=n; i++)
        {
            fac*=i;
        }
        if(fac<10000) cout<<"Underflow!"<<endl;
        else if(fac>6227020800) cout<<"Overflow!"<<endl;
        else printf("%.0lf\n",fac);
    }
}
