#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define LEFT 1
#define RIGHT 2

int main()
{
    int cases,l,m,len;
    string side;
    cin>>cases;
    while(cases--)
    {
        queue <int> left,right;
        cin>>l>>m;
        l*=100;
        for(int i=0; i<m; i++)
        {
            cin>>len>>side;
            if(side=="left") left.push(len);
            else if(side=="right") right.push(len);
        }

        int state=LEFT;
        int result=0;
        len=0;

        while(!left.empty() || !right.empty())
        {
            result++;
            if(state==LEFT)
            {
                len=0;
                while(!left.empty())
                {
                    if(len+left.front()>l) break;
                    len+=left.front();
                    left.pop();
                }
                state=RIGHT;
            }
            else
            {
                len=0;
                while(!right.empty())
                {
                    if(len+right.front()>l) break;
                    len+=right.front();
                    right.pop();
                }
                state=LEFT;
            }
        }
        cout<<result<<endl;
    }
    return 0;
}
