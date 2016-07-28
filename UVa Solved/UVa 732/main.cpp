#include <iostream>
#include <cstring>
#include <stack>
#include <cstdio>
using namespace std;

int n;

bool check(char input[200])
{
    stack <char> balance;
    for(int i=0; i<strlen(input);i++)
    {
        if(input[i]=='(' || input[i]=='[')
            balance.push(input[i]);
        else
        {
            if(balance.size()==0) return 0;
            if((input[i]==')' && balance.top()=='(') || (input[i]==']' && balance.top()=='['))
                balance.pop();
            else return false;
        }
    }
    return balance.size()==0;
}

int main() {
    char input[200];
    scanf("%d\n", &n);
    while(n--) {
        gets(input);
        printf("%s\n", check(input)? "Yes" : "No");
    }
}

