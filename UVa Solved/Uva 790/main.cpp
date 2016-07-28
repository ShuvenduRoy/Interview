#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

int time_to_minutes(const string &time);

struct submission{
    int team;
    string problem;
    string time;
    string status;

    bool operator< (const submission &s) const
    {
        int t1=time_to_minutes(time);
        int t2=time_to_minutes(s.time);
        if(t1!=t2) return t1<t2;
        return status<s.status;
    }
};

struct team
{
    int num;
    int solved;
    int time;
};

bool theTruthIsOutThere(const team &t1, const team &t2)
{
    if(t1.solved>t2.solved) return true;
    if(t1.solved<t2.solved) return false;

    if(t1.time<t2.time) return true;
    if(t1.time>t2.time) return false;

    return t1.num<t2.num;
}


int time_to_minutes(const string &time)
{
    int h,m;
    sscanf(time.c_str(),"%d:%d",&h,&m);

    return h*60+m;
}



int main()
{
    int cases;
    team t;
    string input;
    submission tmp;

    cin>>cases;
    cin.ignore(100,'\n');
    getline(cin, input);

    while(cases--)
    {
        int max_team =0;
        vector <submission> submissions;

        while(getline(cin,input))
        {
            if(input==("")) break;
            istringstream iss(input);
            iss >> tmp.team >> tmp.problem >> tmp.time >> tmp.status;
            submissions.push_back(tmp);

            if(tmp.team>max_team) max_team=tmp.team;
        }

        sort(submissions.begin(),submissions.end());

        vector <team> teams;

        for(int i=0; i<max_team; i++)
        {
            t.num=i;
            t.solved=0;
            t.time=0;
        }

        map<pair<int,string>,int> attempts;
        map<pair<int,string>,bool> solved;

        for(int i=0; i<submissions.size(); i++)
        {
            pair <int, string> team_problem = make_pair(submissions[i].team, submissions[i].problem);
            if(solved.find(team_problem)!=solved.end())
            {
                continue;
            }

            if(submissions[i].status=="y")
            {
                if(attempts.find(team_problem)!=attempts.end())
                {
                    teams[submissions[i].team].time+=20*attempts[team_problem];
                }
                solved[team_problem]=true;
                teams[submissions[i].team].solved+=1;
                teams[submissions[i].team].time+=time_to_minutes(submissions[i].time);
            }
            else
            {
                if(attempts.find(team_problem)!=attempts.end())
                {
                    attempts[team_problem]+=1;
                }
                else
                {
                    attempts[team_problem]=1;
                }
            }
        }
        teams.erase(teams.begin());

        sort(teams.begin(), teams.end(),theTruthIsOutThere);

        int rank=0;
        cout<<"RANK TEAM PRO/SOLVED TIME"<<endl;
        for(int i=0; i<teams.size(); i++)
        {
            if(i == 0 || teams[i].solved != teams[i-1].solved || (teams[i].solved == teams[i-1].solved && teams[i].time != teams[i-1].time)) rank = i + 1;
            printf("%4d %4d",rank,teams[i].num);
            if(teams[i].solved>0) printf(" %4d %10d", teams[i].solved, teams[i].time);
            cout<<endl;

        }
        if(cases) cout<<endl;
    }

    return 0;
}
