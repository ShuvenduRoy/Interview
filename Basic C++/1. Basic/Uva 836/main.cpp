#include <iostream>
#include <cstring>
using namespace std;

string matrix[1000];
bool is1(int i, int i_end, int j)
{
    for(i; i<=i_end; i++)
    {
        if(matrix[i][j]!='1') return false;
    }
    return true;
}

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        cin>>matrix[0];
        int N=matrix[0].size();

        for(int i=1; i<N ;i++)
        {
            cin>>matrix[i];
        }
        int MSS=0, Max=0;

        for(int len=1; len<=N; len++)
        {
            for(int i=0 ;i+len-1<N;i++)
            {
                MSS=0;
                for(int j=0; j<N; j++)
                {
                    if(is1(i,i+len-1,j))
                    {
                        MSS+=len;
                    }
                    else MSS=0;
                    if(MSS>Max) Max=MSS;
                }
            }
        }
        cout<<Max<<endl;
        if(cases) cout<<endl;
    }
    return 0;
}
