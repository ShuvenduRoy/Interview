#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int compare(pair<char,int> a, pair<char,int> b)
{
    if(a.second>b.second) return true;
    if(a.second<b.second) return false;
    return a.first<b.first;
}

int main()
{
    int n;
    string line;
    scanf("%d\n",&n);
    pair<char,int> alph[256];
    for(int i=0; i<256; i++)
        alph[i].first=i;

    while(n--)
    {
        getline(cin,line);
        for(int i=0; i<line.length(); i++)
        {
            if(line[i]>='a' && line[i]<='z')
                alph[line[i]+'A'-'a'].second++;
            else if(line[i]>='A' && line[i]<='Z')
                alph[line[i]].second++;
        }
    }

    sort(alph,alph+256,compare);
    for(int i=0; i<256; i++)
    {
        if(alph[i].second==0) break;
        printf("%c %d\n",alph[i].first,alph[i].second);
    }
    return 0;
}
