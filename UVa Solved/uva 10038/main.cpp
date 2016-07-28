#include <iostream>
#include <cstdio>
#include<cmath>
using namespace std;

int main()
{
    int n;
    int arr[3100];
    int diff[3100]={0};
    while(scanf("%d",&n))
    {
        bool result=false;
        for(int i=0; i<n; i++)
            scanf("%d",&arr[i]);
        for(int i=0; i<n-1; i++){
                int x=abs(arr[i+1]-arr[i]);
                diff[x-1]=1;
        }

        for(int i=0; i<n-1; i++)
        {
            if(diff[i]==0)
            {
                result=true;
                break;
            }
        }
         if(result==true) printf("Not jolly\n");
         else printf("Jolly\n");
    }
}
