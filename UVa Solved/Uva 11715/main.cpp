#include <iostream>
#include <cstdio>
#include <cmath>
#include <limits.h>
using namespace std;

int main()
{
    int n,c=0;
    double u,v,a,s,t;
    while(1)
    {
        c++;
        cin>>n;
        if(n==0) break;

        if(n==1)
        {
            scanf("%lf %lf %lf",&u,&v,&t);
            a=(v-u)/t;
            s=(u*t)+(.5*a*t*t);
            printf("Case %d: ",c);
            cout.precision(3);
            cout<<fixed<<s<<" "<<fixed<<a<<endl;

        }
        else if(n==2)
        {
            cin>>u>>v>>a;
            t=(v-u)/a;
            s=(u*t)+(.5*a*t*t);
            printf("Case %d: ",c);
            cout.precision(3);
            cout<<fixed<<s<<" "<<fixed<<t<<endl;
        }
        else if(n==3)
        {
            cin>>u>>a>>s;
            v=sqrt((u*u)+(2*a*s));
            t=(v-u)/a;
            printf("Case %d: ",c);
            cout.precision(3);
            cout<<fixed<<v<<" "<<fixed<<t<<endl;
        }
        else if(n==4)
        {
            cin>>v>>a>>s;
            u=sqrt((v*v)-(2*a*s));
            t=(v-u)/a;
            printf("Case %d: ",c);
            cout.precision(3);
            cout<<fixed<<u<<" "<<fixed<<t<<endl;
        }
    }
    return 0;
}
