#include <iostream>
#define arr_size(a) sizeof(a)/sizeof(a[0])
using namespace std;

int lis(int a[], int n)
{
    int l[n];
    for(int i=0; i<n; i++)
    {
        l[i]=1;
    }

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(a[i]>a[j] && l[j]+1>l[i])
                l[i]=l[j]+1;
        }
    }
    int max=0;

    for(int i=0; i<n; i++)
    {
        if(l[i]>max) max=l[i];
    }
    return max;
}

int main()
{
    int a[]={1,2,5,3,4,8,9,20,11,19,23};
    int n=arr_size(a);
    cout<<lis(a,n);
    return 0;
}
