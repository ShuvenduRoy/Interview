#include <iostream>
#include <cstring>
//#include <fstream>
using namespace std;

int main()
{
    //ofstream c_out;
    //c_out.open("ans.txt");
    int n,cases=0;
    cin>>n;
    while(n--)
    {
        cases++;
        int area,ans=0;
        char a;
        cin>>area;
        int field[105];
        memset(field,0,sizeof(field));

        for(int i=0; i<area; i++)
        {
            cin>>a;
            if(a=='.')
            {
                field[i]=1;
                ans++;
            }
            else field[i]=0;
        }
        for(int i=0; i<area; i++)
        {
            if(field[i]==1)
            {
                if(field[i+1]==0)
                {
                    if(field[i+2]==0)
                    {
                        i+=2;
                    }
                    else
                    {
                        ans-=1;
                        i+=2;
                    }
                }
                else
                {
                    if(field[i+2]==0)
                    {
                        ans-=1;
                        i+=2;
                    }
                    else
                    {
                        ans-=2;
                        i+=2;
                    }
                }
            }
        }

        cout<<"Case "<<cases<<": "<<ans<<endl;
    }
    return 0;
}
