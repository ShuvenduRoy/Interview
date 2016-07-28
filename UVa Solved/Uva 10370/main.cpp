#include <iostream>
#include<cstdio>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t;i ++)
    {
        int n;
        double sum=0;
        cin>>n;
        double ar[n];
        for(int j=0; j<n; j++)
        {
            cin>>ar[j];
            sum+=ar[j];
        }
        double ave=sum/n;
        double ans=0;
        for(int j=0; j<n; j++)
        {
            if(ar[j]>ave) ans+=1;
        }
        printf("%.3lf%c\n",ans/n*100,37);

    }
    return 0;
}
