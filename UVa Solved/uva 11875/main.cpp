#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    int c=0;
    while(t--)
    {
        c++;
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n ;i++)
        {
            cin>>arr[i];
        }
        int mid=(n-1)/2;
        cout<<"Case "<<c<<": "<<arr[mid]<<endl;
    }
    return 0;
}
