#include <iostream>
using namespace std;

void Selection_Sort(int A[],int n)
{
    int i,min;
    for(i=0; i<n-1; i++)
    {
        min=i;
        for(int j=i+1; j<n; j++)
        {
            if(A[j]<A[min])
                min=j;
        }
        int temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
}

int main()
{
    int A[6]={2,7,4,1,5,3};
    Selection_Sort(A,6);
    for(int i=0; i<6; i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}
