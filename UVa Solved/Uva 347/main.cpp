#include <iostream>
#include <cstring>
#include <cstdio>
#include <sstream>
using namespace std;

bool RunAround(string s,int n)
{
    bool num[9];
    memset(num,false,sizeof(num));

    int a;
    a=s[0]-48;//8
    int i=0;
    for(int k=0; k<n; k++)
    {
        i=(i+a)%n;
        a=s[i]-48;
    }
    if(a==s[0]-48) return true;
    return false;
}

int main()
{
    string s;
    int cases=0;
    while(cin>>s)
    {
        cases++;
        if(s[0]-48==0) break;
        while(!RunAround(s,s.length()))
        {
            int n=0,i=1;
            char a[10];
            int p=s.length();
            for(int j=0; j<p; j++)
            {
                int x=s[j]-48;
                n=n*10;
                n+=x;
            }
            n++;

            stringstream ss;
            ss<<n;
            s=ss.str();
        }
        cout<<"Case "<<cases<<": "<<s<<endl;
    }
    return 0;
}
