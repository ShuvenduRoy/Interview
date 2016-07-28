#include <iostream>
#include <cstring>
using namespace std;

const int MX=1200000;
char sieve[MX];

void genSieve()
{
    sieve[0]=sieve[1]=1;
    int i,j;

    for(i=2; i*i<=MX; i++)
    {
        if(!sieve[i])
        {
            for(j=i*i; j<MX; j+=i)
            {
                sieve[j]=1;
            }
        }
    }
}

int main()
{
    genSieve();
    int n,divN,total,i;
    bool found;

    while(cin>>n)
    {
        if(n==0) break;
        found = false;
        cout<<n<<":"<<endl;
        divN=n/2;

        for(int i=1; i<=divN; i++)
        {
            if(sieve[i]==0 && sieve[n-i]==0)
            {
                total=i+(n-i);
                if(total==n)
                {
                    cout<<i<<"+"<<(n-i)<<endl;
                    found=true;
                    break;
                }
            }
        }
        if(!found)
            cout<<"NO WAY!"<<endl;
    }
    return 0;
}
