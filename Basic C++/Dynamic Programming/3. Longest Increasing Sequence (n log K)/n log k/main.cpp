#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#define Array_size(A) sizeof(A)/sizeof(A[0])

using namespace std;

int ceilIndex(int A[], int l, int r, int key)
{
    while(r-l>1)
    {
        int m=l+(r-l)/2;
        if(A[m]>=key) r=m;
        else l=m;
    }
    return r;
}

int main()
{
    int A[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    int n=Array_size(A);
    int tailetable[n];
    int len,r,l;

    memset(tailetable,0,n);
    tailetable[0]=A[0];
    len=1;

    for(int i=0; i<n; i++)
    {
        if(A[i]<tailetable[0]) tailetable[0]=A[i];
        else if(A[i]>tailetable[len-1]) tailetable[len++]=A[i];
        else
        {
            int r=ceilIndex(tailetable,-1,len-1,A[i]);
            tailetable[r]=A[i];
        }

    }
    for(int i=0; i<len; i++)
        cout<<tailetable[i]<<" ";
    cout<<endl;
    cout<<len;
}
