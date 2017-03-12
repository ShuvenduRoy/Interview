#include <stdio.h>
#include <string.h>
#include <array>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    //ifstream cin("../input.txt");

    int i, j;
    int C[50][50] = {};
    C[0][0] = 1;

    /**There is a sequence in every loop, every loop has one extra loop 
    *   First create the pascel table
    */
    for(i = 1; i < 50; i++) {
        C[i][0] = 1;
        for(j = 1; j <= i; j++)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
    }

    string s;
    while(cin>>s) {
        int len = s.length(), idx = 0;
        for(i = 1; i < len; i++) {
            if(s[i] < s[i-1]) {
                puts("0");break;
            }
            /**
            * 1 letter word end with 36
            * 2 letter word end with 351 so 3 letter word start with 352 this sequence is got from this loop
            */
            idx += C[26][i];
        }
        if(i != len)	continue;
        for(i = 0; i < len; i++) {
            /**
            *   For every word from the second one the task is to find what to add as its positional value
            */
            for(j = (i == 0) ? 1 : s[i-1]-'a'+2; j <= s[i]-'a'; j++)
                idx += C[26-j][len-i-1];
        }
        printf("%d\n", idx+1);
    }
    return 0;
}