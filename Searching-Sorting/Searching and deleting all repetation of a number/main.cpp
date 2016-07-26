#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    int arr[5];
    int total=5;
    cout<<"Enter 5 numbers"<<endl;
    for(int i=0; i<5; i++)
        cin>>arr[i];
    int n;
    cout<<"Enter number to delete"<<endl;
    cin>>n;

    for(int i=0; i<total; i++)
    {
        if(arr[i]==n)
        {
            total--;
            for(int j=i; j<total; j++)
                arr[j]=arr[j+1];

            i--;
        }

    }

    for(int i=0; i<total; i++)
        cout<<arr[i]<<" ";
}
