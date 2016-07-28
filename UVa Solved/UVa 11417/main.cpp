#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    while(1)
    {
        if(n%m == 0){
            cout<<m<<endl;
            break;
        }
        int temp=n;
        n=m;
        m=temp%m;

    }
}
