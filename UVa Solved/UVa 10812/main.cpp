#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
    long long int a,b;
    int t,x,y;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        cin>>a>>b;
        y=abs(a-b)/2;
        x=a-y;
        if((x+y)==a && (x-y)==b)
            cout<<max(x,y)<<" "<<min(x,y)<<endl;
        else cout<<"impossible"<<endl;
    }
    return 0;
}
