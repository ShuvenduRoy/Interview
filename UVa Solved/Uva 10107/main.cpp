#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    int sum=0;
    vector <int> v;

    while(cin>>n)
    {
        v.push_back(n);
        sort(v.begin(),v.end());

        if(v.size()%2==1) cout<<v[(v.size()+1)/2-1]<<endl;
        else cout<<(v[(v.size()+1)/2-1]+v[(v.size()+1)/2])/2<<endl;
    }
    return 0;
}
