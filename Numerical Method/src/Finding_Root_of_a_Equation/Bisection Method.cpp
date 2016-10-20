#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    ifstream file("data.txt");
    file>>s;

    int a1,b1,c1;
    int p;
    char x;
    stringstream ss(s);
    ss>>a1>>x>>x>>p>>b1>>x>>c1;
    //cout<<a1<<" "<<b1<<" "<<c1<<endl;

    double a = a1*1.0;
    double b = b1*1.0;
    double c = c1*1.0;

    double inter1 = ((b/a)*(b/a));
    double xmax = sqrt(abs( inter1 - 2*(c/a)));
    //cout<<xmax<<endl;

    double r1[2];
    double r2[2];


    double xx1 = -xmax;
    double xx2 = xmax;
    int k=0;

    //condition for finding the limit
    double i = -xmax;
    while(i<=xmax+1)
    {

        int j=i+1;

        double fx0 = i*i*a + b*i + c;
        double fx1 = j*j*a + b*j + c;

        if((fx0<0 && fx1>0) || (fx0>0 && fx1<0) )
        {
            r1[k] = i;
            r2[k] = j;
            k++;
            i++;
        }
        i+=.5;
    }

    //cout<<r1[0]<<" "<<r2[0]<<" "<<r1[1]<<" "<<r2[1]<<endl;

    double roote[2];


    for(int i=0; i<2; i++)
    {
        double x1 = r1[i];
        double x2 = r2[i];

        double x0 = (x1+x2)/2;
        double xn = 0.0;


        while(1)
        {
            double fx0 = x0*x0*a + b*x0 + c;
            double fx1 = x1*x1*a + b*x1 + c;

            if(fx0==0)
            {
                cout<<x0<<endl;
            }
            if(fx1*fx0 < 0)
            {
                x2 = x0;
            }
            else
            {
                x1 = x0;
            }

            cout<<x0<<endl;
            xn = x0;
            x0 = (x1+x2)/2;
            if(abs(xn-x0)<.0001)
                break;
        }

        roote[i] = x0;
        //cout<<x0<<endl;
    }

    cout<<endl<<roote[0]<<endl<<roote[1];

}
