#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    int max_len=0,i;
    char word[102],max[102],end[]="E-N-D",temp[102];
    while(1)
    {
        int count=0;
        scanf("%s",&word);
        int n=strlen(word);
        int x=strcmp(word,end);
        if(x==0) break;
        if(n<= max_len) continue;

        for(i=0;i<n;i++)
        {
            if((word[i]>=65 && word[i]<=90) || (word[i]>=97 && word[i]<=122) || word[i]==45){
                temp[count]=word[i];
                count++;
            }
            else{
                if(count>max_len) {
                temp[count]='\0';
                max_len=count;
                strcpy(max,temp);
                count=0;
                }
            }
        }
            if(count>max_len) {
                temp[count]='\0';
                max_len=count;
                strcpy(max,temp);
                count=0;
                }

    }
    for(i=0;i<max_len;i++)
    {
        max[i]=tolower(max[i]);
    }
    printf("%s\n",max);
    return 0;
}
