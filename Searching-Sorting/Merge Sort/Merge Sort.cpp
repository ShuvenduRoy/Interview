#include <iostream>
#include <string>
using namespace std;

void Merge(int L[], int R[], int A[])
{
    int nl=sizeof(L);
    int nr=sizeof(R);
    int i,j,k;
    i=j=k=0;
    while(i<nl && j<nr)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<nl)
    {
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<nr)
    {
        A[k]=R[j];
        j++;
        k++;
    }
}

void Merge_sort(int A[])
{
    int n=sizeof(A);

    if(n<2)
        return;

    int mid=n/2;
    int left[mid];
    int right[n-mid];

    for(int i=0; i<mid; i++)
    {
        left[i]=A[i];
    }
    for(int i=mid; i<n; i++)
    {
        right[i-mid]=A[i];
    }

    Merge_sort(left);
    Merge_sort(right);
    Merge(left, right, A);
}

int main()
{
    int A[6]={5,4,6,2,3,1};
    Merge_sort(A);
    for(int i=0; i<6; i++ )
    {
        cout<<A[i]<<" ";
    }
}
