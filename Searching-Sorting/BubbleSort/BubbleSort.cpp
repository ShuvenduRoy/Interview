#include <iostream>
using namespace std;

void Bubble_Sort(int A[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(A[j]>A[j+1])
            {
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}

int main()
{
    int A[6]={2,6,4,1,3,5};
    Bubble_Sort(A,6);
    for(int i=0; i<6; i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}
