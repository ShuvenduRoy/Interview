#include <iostream>
using namespace std;

int Partition(int A[],int start,int end)
{
    int partition_index=start;
    int pivot=A[end];
    for(int i=start; i<end; i++)
    {
        if(A[i]<=pivot)
        {
            int temp=A[i];
            A[i]=A[partition_index];
            A[partition_index]=temp;
            partition_index++;
        }
    }
    int temp=A[end];
    A[end]=A[partition_index];
    A[partition_index]=temp;
    return partition_index;
}
void Quick_sort(int A[],int start, int end)
{
    if(start<end)
    {
        int partition_index=Partition(A,start,end);
        Quick_sort(A,start,partition_index-1);
        Quick_sort(A,partition_index+1,end);
    }
}

int main()
{
    int A[6]={1,5,6,4,2,3};
    Quick_sort(A,0,5);
    for(int i=0; i<6; i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}
