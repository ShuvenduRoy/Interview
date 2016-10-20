#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{

    ofstream myfile;
    myfile.open ("output.txt");


    string e1,e2,e3;
    //cin>>e1>>e2>>e3;
    char x;
    double a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3;

    ifstream inf("data.txt");



    for(int i=0; i<4; i++)
    {
        inf>>e1>>e2>>e3;

        string eqn;
        string buf;
        int n = e1.length();

        for(int i=0; i<n; i++)
        {
            if(e1[i]=='x' || e1[i]=='y' || e1[i]=='z')
            {
                if(e1[i-1]=='+' || e1[i-1]=='-' || i==0)
                {
                    buf+='1';
                    buf+=e1[i];
                }
                else
                {
                    buf+=e1[i];
                }
            }
            else
            {
                buf+=e1[i];
            }
        }
        //cout<<buf<<endl;

        n=buf.length();
        for(int i=0; i<n; i++)
        {
            if(buf[0]=='x')
            {
                eqn+='1';
                eqn+='x';
            }
            if(buf[i]>='0' && buf[i]<='9')
            {

                while(buf[i]>='0' && buf[i]<='9')
                {
                    eqn+=buf[i];
                    i++;
                }
                eqn+='x';
            }

            if( buf[i]=='+' || buf[i]=='-' )
            {
                eqn+=buf[i];
            }

        }
        //cout<<eqn<<endl;

        stringstream ss1(eqn);
        ss1>>a1>>x>>b1>>x>>c1>>x>>d1;






        buf="";
        eqn="";
        n = e2.length();

        for(int i=0; i<n; i++)
        {
            if(e2[i]=='x' || e2[i]=='y' || e2[i]=='z')
            {
                if(e2[i-1]=='+' || e2[i-1]=='-' || i==0)
                {
                    buf+='1';
                    buf+=e2[i];
                }
                else
                {
                    buf+=e2[i];
                }
            }
            else
            {
                buf+=e2[i];
            }
        }
        //cout<<buf<<endl;

        n=buf.length();
        for(int i=0; i<n; i++)
        {
            if(buf[0]=='x')
            {
                eqn+='1';
                eqn+='x';
            }
            if(buf[i]>='0' && buf[i]<='9')
            {

                while(buf[i]>='0' && buf[i]<='9')
                {
                    eqn+=buf[i];
                    i++;
                }
                eqn+='x';
            }

            if( buf[i]=='+' || buf[i]=='-' )
            {
                eqn+=buf[i];
            }

        }
        //cout<<eqn<<endl;

        stringstream ss2(eqn);
        ss2>>a2>>x>>b2>>x>>c2>>x>>d2;




        buf="";
        eqn="";
        n = e3.length();

        for(int i=0; i<n; i++)
        {
            if(e3[i]=='x' ||e3[i]=='y' || e3[i]=='z')
            {
                if(e3[i-1]=='+' || e3[i-1]=='-' || i==0)
                {
                    buf+='1';
                    buf+=e3[i];
                }
                else
                {
                    buf+=e3[i];
                }
            }
            else
            {
                buf+=e3[i];
            }
        }
        //cout<<buf<<endl;

        n=buf.length();
        for(int i=0; i<n; i++)
        {
            if(buf[0]=='x')
            {
                eqn+='1';
                eqn+='x';
            }
            if(buf[i]>='0' && buf[i]<='9')
            {

                while(buf[i]>='0' && buf[i]<='9')
                {
                    eqn+=buf[i];
                    i++;
                }
                eqn+='x';
            }

            if( buf[i]=='+' || buf[i]=='-' )
            {
                eqn+=buf[i];
            }

        }
        //cout<<eqn<<endl;

        stringstream ss3(eqn);
        ss3>>a3>>x>>b3>>x>>c3>>x>>d3;




        double limit, errorX, errorY, errorZ;
        limit = .000001;

        double xo,yo,zo;
        xo=yo=zo=0;

        //cout<<a1<<" "<<b1<<" "<<c1<<" "<<d1<<endl;
        //cout<<a2<<" "<<b2<<" "<<c2<<" "<<d2<<endl;
        //cout<<a3<<" "<<b3<<" "<<c3<<" "<<d3<<endl;

        while(1)
            //for(int i=0; i<3; i++)
        {
            double xn = (d1-b1*yo-c1*zo)/a1;
            errorX = xn-xo;
            if(errorX<0)
                errorX=-errorX;
            xo=xn;

            double yn = (d2-a2*xo-c2*zo)/b2;
            errorY = yn-yo;
            if(errorY<0)
                errorY=-errorY;
            yo=yn;


            double zn = (d3-a3*xo-b3*yo)/c3;
            errorZ = zn-zo;
            if(errorZ<0)
                errorZ=-errorZ;
            zo=zn;

            if(errorX<limit || errorY<limit || errorZ<limit)
                break;
        }



        cout<<"X = "<<xo<<endl;
        cout<<"Y = "<<yo<<endl;
        cout<<"Z = "<<zo<<endl;
        //cout<<xo<<endl<<yo<<endl<<zo<<endl;
        myfile<<"X = "<<xo<<endl;
        myfile<<"Y = "<<yo<<endl;
        myfile<<"Z = "<<zo<<endl;
        //myfile << xo<<endl<<yo<<endl<<zo<<endl;
    }

    myfile.close();
}
