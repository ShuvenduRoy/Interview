#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        double l;
        cin>>l;
        double w,r;
        w=(l/10)*6;
        r=(l/5);
        double red,green;
        red=acos(-1)*r*r;
        green=(l*w)-red;
        printf("%.2lf %.2lf\n",red,green);
    }
    return 0;
}
