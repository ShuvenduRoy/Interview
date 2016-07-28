#include <iostream>
using namespace std;

int minimum(int k, int *front, int *right) {
    int result = 0;
    bool front_taken[8] = { false };
    bool right_taken[8] = { false };

    for(int i=0; i<k; i++) {
        for(int j=0; j<k; j++) {
            if (front[i] == right[j] && !front_taken[i] && !right_taken[j]) {
                result += front[i];
                front_taken[i] = true;
                right_taken[j] = true;
            }
        }
    }

    for(int i=0; i<k; i++) {
        if (!front_taken[i])
            result += front[i];
        if (!right_taken[i])
            result += right[i];
    }

    return result;
}


int maximum(int n, int *front, int *right)
{
    int result=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            result+=min(front[i],right[j]);
        }
    }
    return result;
}

int main()
{
    int t;
    cin>>t;
    int front[8];
    int right[8];
    for(int test=1; test<=t; t++)
    {
        int n;
        cin>>n;

        for(int i=0; i<n; i++) cin>>front[i];
        for(int i=0; i<n; i++) cin>>right[i];

        pair<int,int> result = make_pair(minimum(n, front, right), maximum(n, front, right));
        cout << "Matty needs at least " << result.first << " blocks, and can add at most " << result.second - result.first << " extra blocks." << endl;

    }
}
