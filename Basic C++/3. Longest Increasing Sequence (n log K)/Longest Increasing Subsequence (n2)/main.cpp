#include <iostream>
using namespace std;

int lis_length(int a[],int n)
{
    int lis[n],max=0;
    for(int i=0; i<n; i++) lis[i]=1;

    for(int i=1; i<n ;i++)
    {
        for(int j=0; j<i ; j++)
        {
            if(a[i]>a[j] && lis[j]+1>lis[i]) lis[i]=lis[j]+1;
        }
    }

    max=0;
    for(int i=0; i<n; i++)
    {
        if(lis[i]>max) max=lis[i];
    }
    return max;
}

int main()
{
    int a[5]={2,1,3,4,5};
    int len=lis_length(a,5);
    cout<<len;
    return 0;
}
