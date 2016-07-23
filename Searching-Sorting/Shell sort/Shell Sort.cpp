#include <iostream>
using namespace std;

void Shell_Sort(int A[],int n)
{
    int d=n/2;
    while(d>0)
    {
        for(int i=0; i<n; i=i+d)
        {
            int value=A[i];
            int hole=i;

            while(hole>0 && A[hole-d]>value)
            {
                A[hole]=A[hole-d];
                hole=hole-d;
            }
            A[hole]=value;
        }
        d=d/2;
    }
}

int main()
{
    int A[10]={2,6,4,1,5,3};
    Shell_Sort(A,6);
    for(int i=0; i<6; i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}
