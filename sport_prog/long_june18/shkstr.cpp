#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <sys/time.h>
#include <unistd.h>
#include <chrono>
#include <set>

#define S1(n) scanf("%d", &n)
#define S2(a,b) scanf("%d %d", &a, &b)
#define MOD 163577857
#define SIZE 100

#define LOCAL

using namespace std;

struct query
{
    int idx;
    string p;
    int r;
} ;

class Solution
{
public:
    void solve(vector<string> &s, vector<query> qr)
    {
        sort(qr.begin(), qr.end(), [](query l, query r)
        {
            return l.r < r.r;
        });
        set<string> sset;

        vector<string> solution(qr.size());

        int si = 0;

        for(auto &qri: qr)
        {
            while(si <= qri.r)
            {
                sset.insert(s[si++]);
            }

            auto it = sset.lower_bound(qri.p);
            int bm = -1;
            if(it != sset.begin())
            {
                auto itprev = prev(it);
                bm = getMatch(*(itprev), qri.p);
                string sub = qri.p.substr(0, bm);
                auto it2 = sset.lower_bound(sub);
                solution[qri.idx] = *(it2);
            }
            if(it != sset.end())
            {
                if(getMatch(*it, qri.p) > bm)
                {
                    solution[qri.idx] = *it;
                }
            }

        }

        for(int i = 0;i < solution.size();i++)
        {
            cout<<solution[i]<<endl;
        }
    }

    int getMatch(string s1, string s2)
    {
        int count = 0;
        for(int i = 0;i < min(s1.size(), s2.size());i++)
        {
            if(s1[i] == s2[i])
                count++;
            else
                break;
        }
        return count;
    }
};

int main()
{
    int n,q;
    S1(n);
    vector<string> s(n);
    for(int i = 0;i < n;i++)
    {
        cin>>s[i];
    }
    S1(q);

    vector<query> qr(q);
    for(int i = 0;i < q;i++)
    {
        cin>>qr[i].r>>qr[i].p;
        qr[i].r--;
        qr[i].idx = i;
    }
    Solution().solve(s,qr);

    return 0;
}
