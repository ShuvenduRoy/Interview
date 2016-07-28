#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        double ar[7];
        double sum=0;
        for(int i=0; i<7; i++){
            cin>>ar[i];
        }
        for(int i=0; i<4; i++)
            sum+=ar[i];
        int mini=min(ar[4],min(ar[5],ar[6]));

        for(int i=4; i<7; i++)
        {
                sum+=ar[i]/2.0;
        }
        sum-=mini/2.0;

        cout<<"Case "<<i<<": ";
        if(sum>=90) cout<<"A"<<endl;
        else if(sum>=80 && sum<90) cout<<"B"<<endl;
        else if(sum>=70 && sum<80) cout<<"C"<<endl;
        else if(sum>=60 && sum<70) cout<<"D"<<endl;
        else cout<<"F"<<endl;
    }
    return 0;
}
