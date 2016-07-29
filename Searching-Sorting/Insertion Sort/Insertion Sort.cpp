#include <iostream>
using namespace std;

void Insertion_sort(int A[],int n)
{
    for(int i=1; i<n; i++)
    {
        int value=A[i];
        int hole=i;

        while(hole>0 && A[hole-1]>value)
        {
            A[hole]=A[hole-1];
            hole=hole-1;
        }
        A[hole]=value;
    }
}

int main()
{
    int A[6]={2,6,4,1,5,3};
    Insertion_sort(A,6);
    for(int i=0; i<6; i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}
