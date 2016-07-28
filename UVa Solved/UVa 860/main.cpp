#include <iostream>
 #include <cstring> //strtok
 #include <map>
 #include <cmath> //log
 #include <iomanip> //setprecision
 using namespace std;
 string normalize(string str)
 {
     string tmp="";
     for(int i=0;i<str.size();i++)
     {
         tmp+=tolower(str[i]);
     }
     return tmp;
 }
 int main()
 {
     string str;
     while(getline(cin,str) and str!="****END_OF_INPUT****")
     {
         int lambda=0;
         double ET=0,Erel=0,Emax=0;
         map<string,int> Map;
         char *pch=strtok((char*)str.c_str(),",.:;!?\"() ");
         while(pch)
         {
             string tmp;
             tmp=normalize(pch);
             Map[tmp]++;
             lambda++;
             pch=strtok(NULL,",.:;!?\"() ");
         }
         while(getline(cin,str) and str!="****END_OF_TEXT****")
         {
             pch=strtok((char*)str.c_str(),",.:;!?\"() ");
             while(pch)
             {
                 string tmp=normalize(pch);
                 Map[tmp]++;
                 lambda++;
                 pch=strtok(NULL,",.:;!?\"() ");
             }
         }
         double sum=0;
         for(map<string,int>::iterator it=Map.begin();it!=Map.end();++it)
         {
             int pi=it->second;
             sum+=(pi)*(log10(lambda)-log10(pi));
         }
         ET=sum/lambda;

         Emax=log10(lambda);
         Erel=ET/Emax*100;

         cout<<lambda;
         cout<<fixed<<setprecision(1)<<" "<<ET<<" ";
         cout<<fixed<<setprecision(0)<<Erel<<endl;
     }
     return 0;
 }
