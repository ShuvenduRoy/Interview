#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string s;
    while(1)
    {
        cin>>s;
        if(s=="#") break;

        if(next_permutation(s.begin(),s.end())) cout<<s;
        else cout<<"No Successor"<<endl;

    }
}
