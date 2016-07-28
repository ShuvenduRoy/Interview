#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
using namespace std;

void calc(long long *max_value, long long *max_position, long long i)
{
    long long j=i;
    long long num=0;
    do
    {
        num++;
        if(i%2==0) i/=2;
        else i=i*3+1;
    }
    while(i!=1);
    if(num>*max_value){
        *max_value=num;
        *max_position=j;
    }
}

int main()
{
    long long l,r;
    while(scanf("%lld %lld",&l,&r) && (l+r) ){
        long long max_value=0;
        long long max_position=l;
        if (l>r){
            int temp=l;
            l=r;
            r=temp;
        }
        for(long long i=l; i<=r; i++) {
            calc(&max_value,&max_position,i);
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",l,r,max_position,max_value);
    }
}
