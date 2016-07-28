#include <iostream>
#include <cstdio>
using namespace std;

int func(int n)
{
    int d=0;
    for(int i=1; i<=n/2; i++)
    {
        if(n%i == 0)
            d+=i;
    }
    return n-d;
}

int main()
{
    printf("PERFECTION OUTPUT\n");
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        int d=func(n);
        printf("%5d  %s\n",n,(d==0)?"PERFECT" : d>0?"DEFICIENT":"ABUNDANT");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
