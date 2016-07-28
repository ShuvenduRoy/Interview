#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <sstream>
#include <cstdio>
using namespace std;

struct Contestant
{
    bool solved[10];
    int attempt[10];
    int count,penalty;
};

map<int, Contestant> Contest;
vector< int > Index;

bool comp(int A, int B) {
	if (Contest[A].count != Contest[B].count)
		return (Contest[A].count > Contest[B].count);
	if (Contest[A].penalty != Contest[B].penalty)
		return (Contest[A].penalty < Contest[B].penalty);
	return (A < B);
}

int main()
{
    int t;
    stringstream ss;
    string str;
    getline(cin, str);
    ss.clear();
    ss<<str;
    ss>>t;
    getline(cin, str);

    while(t--)
    {
        Contest.clear();
        Index.clear();
        while(getline(cin,str))
        {
            if(str.empty()) break;
            int a,b,c;
            string d;
            ss.clear();
            ss<<str;
            ss>> a >> b >> c >>d;

            if(Contest.find(a)==Contest.end())
            {
                Contestant com;
                memset(com.attempt,0 , sizeof com.attempt);
                memset(com.solved, false , sizeof com.solved);
                com.penalty=0;
                com.count=0;

                Index.push_back(a);
                Contest[a]=com;
            }
            if(d=="C"||d=="I")
            {
                if(Contest[a].solved[b]) continue;

                if(d=="C")
                {
                    Contest[a].solved[b]=true;
                    Contest[a].penalty+=(20*Contest[a].attempt[b]);
                    Contest[a].count+=1;
                }
                else Contest[a].attempt[b]+=1;
            }

        }


        sort(Index.begin(), Index.end(), comp);
        for(int i=0; i<Index.size(); i++)
        {
            cout<<Index[i]<<" "<<Contest[Index[i]].count<<" "<<Contest[Index[i]].penalty<<endl;
        }

        if(t) cout<<endl;
    }
    return 0;
}


