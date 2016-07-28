#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char hajj[]="Hajj";
    char umrah[]="Umrah";
    int cases=0;
    char name[10];
    while(cin>>name)
    {
        cases++;
        if(name[0]=='*') break;
        if(strcmp(name,hajj)==0) cout<<"Case "<<cases<<": Hajj-e-Akbar"<<endl;
        if(strcmp(name,umrah)==0) cout<<"Case "<<cases<<": Hajj-e-Asghar"<<endl;
    }
    return 0;
}
