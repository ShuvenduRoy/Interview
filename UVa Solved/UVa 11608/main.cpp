#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int s,n;
    int cases=1;
    while(cin>>s, s>=0)
    {
        int month[12];
        int need[12];
        for(int i=0; i<12; i++)
        {
            scanf("%d",&month[i]);
        }
        for(int i=0; i<12; i++)
        {
            scanf("%d",&need[i]);
        }
        int inhand=s;
        cout << "Case " << cases++ << ":" << endl;
        if(inhand>=need[0]){
            cout << "No problem! :D" << endl;
            inhand-=need[0];
        }
        else cout << "No problem. :(" << endl;

        for(int i=1; i<12; i++)
        {
            inhand+=month[i-1];
            if(inhand>=need[i]){
                cout << "No problem! :D" << endl;
                inhand-=need[i];
            }
            else cout << "No problem. :(" << endl;
        }
    }
}
