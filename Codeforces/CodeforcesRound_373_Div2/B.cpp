#include <bits/stdc++.h>
using namespace std;

char s[100010];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    int res = n + 1;
    for (int i = 0; i < 2; i++) {
        int now = i;
        int diff1 = 0, diff2 = 0;
        for (int j = 0; j < n; j++) {
            int val;
            if (s[j] == 'r') {
                val = 0;
            } else {
                val = 1;
            }
            if (val != now) {
                if (now == 0) {
                    diff1++;
                } else {
                    diff2++;
                }
            }
            now = 1 - now;
        }
        int tres = max(diff1, diff2);
        res = min(res, tres);
    }
    printf("%d\n", res);
    return 0;
}