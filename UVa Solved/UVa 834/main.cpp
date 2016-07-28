#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        cout<<"["<<a/b<<";";
        a%=b;
        while(a!=1)
        {
            cout<<b/a<<",";
            b%=a;
            swap(a,b);
        }
        cout<<b<<"]"<<endl;
    }
    return 0;
}
