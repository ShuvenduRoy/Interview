#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);

    int cases=0;
    for(int k=0; k<n; k++)
    {
        char name[21];
        cases++;
        int num[26]={0};
        scanf("%s",name);
        int l=strlen(name);
        for(int j=0; j<l; j++) num[name[j]-'A']++;

        long long int ans=1;
        for(int i=0; i<l; i++)
                ans*=(i+1);
        for(int i=0; i<l; i++)
        {
            for(int j=0, sz=num[name[i]-'A']; j<sz; j++)
                {
                    ans/=(j+1);
                    num[name[i]-'A']--;
                }
        }
        printf("Data set %d: %lld\n",cases,ans);
    }
}
