#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int main()
{
    unsigned long int n=18446744073709551615;
    unsigned long int arr[n];
    unsigned long int i,j;
    for(i=0; i<n; i++) arr[i]=0;
    for(i=0; i<=sqrt(n); i++)
    {
        for(j=0; pow(j,i)<=n; j++)
        {
            unsigned long int m=pow(j,i);
            arr[m]++;
        }
    }
    for(i=0; i<=n; i++)
    {
        if(arr[i]>1) printf("%ld\n",i);
    }
}
