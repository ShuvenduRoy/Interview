#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int ar[n];
        for(int i=0; i<n; i++) ar[i]=0;

        if(n==0) break;
        for(int i=1; i<=sqrt(n)+1; i++)
        {
            for(int j=1; i*j<=n; j++)
            {
                ar[i*j]=1;
            }
        }

        if(ar[n]==0) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
}
