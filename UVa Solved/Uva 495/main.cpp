#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long int n;
    while(~scanf("%lld",&n))
    {
        long long int j=0;
        long long int k=1;
        long long int ans=0;
        if(n==1)
        {
            printf("The Fibonacci number for 1 is 1\n");
            break;
        }
        for(long long int i=1; i<n; i++)
        {
            ans=j+k;
            j=k;
            k=ans;
        }
        printf("The Fibonacci number for %lld is %lld\n",n,ans);
    }
}
