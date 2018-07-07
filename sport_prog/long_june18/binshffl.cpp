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
#include <bitset>
#include <queue>

#define S1(n) scanf("%d", &n)
#define S2(a,b) scanf("%d %d", &a, &b)
#define MOD 163577857
#define SIZE 100
#define LOCAL

typedef long long int lli;

using namespace std;

const int maxsize = 8;
typedef bitset<maxsize> bs;

class Solution
{
public:
    int solve(lli a, lli b)
    {
        int steps;
        int addone = 0;
        if(a==b)
            return 0;
        if(b==a+1)
            return 1;
        if(b==0)
        {
            return -1;
        }
        if(b==1)
        {
            return -1;
        }
        if(b==2)
        {
            if(a && (!(a&(a-1))))
            return 1;
            else
            return 2;
        }

        if((b&1) == 0)
        {
            b--;
            addone = 1;
        }
        bitset<64> ba(a);
        bitset<64> bb(b);

        int ca = ba.count();
        int cb = bb.count();

        if(cb > ca)
        {
            steps = cb-ca;
        }
        else if(cb == ca)
        {
            if(addone == 1)
                steps = 0;
            else
            {
                steps = 2;
            }
        }
        else
        {
            if(addone == 1)
                steps = 1;
            else
                steps = 2;
        }
        return steps + addone;
    }

    vector<int> bruteforce(int start)
    {
        vector<int> minsteps(1<<maxsize, -1);
        vector<bool> bitsdone(maxsize, false);
        bs b(start);
        queue<bs> q;
        q.push(b);
        minsteps[b.to_ulong()] = 0;

        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            int ones = front.count();
            if(bitsdone[ones-1])
            {
                continue;
            }
            bitsdone[ones-1] = true;
            int val = front.to_ulong();
            dfs(bs(0), ones, 0, 0, minsteps, minsteps[val], q);
        }

        // for(int i = 0;i < 1<<maxsize;i++)
        // {
        //     printf("%d : %d\n",i, minsteps[i]);
        // }
        return minsteps;
    }

    void dfs(bs b, int ones, int onesdone, int idx, vector<int> &minsteps, int curval, queue<bs> &q)
    {
        if(ones == onesdone)
        {
            int val = b.to_ulong();
            val++;
            if(minsteps[val] == -1)
            {
                minsteps[val] = curval + 1;
                q.push(bs(val));
            }
            return;
        }
        for(int i = idx;i < maxsize;i++)
        {
            b[idx] = 1;
            dfs(b, ones, onesdone+1, idx+1, minsteps, curval, q);
            b[idx] = 0;
            dfs(b, ones, onesdone, idx+1, minsteps, curval, q);
        }
    }



};

int main()
{
    int t;
    S1(t);
    while(t--)
    {
        lli a,b;
        cin>>a>>b;
        cout<< Solution().solve(a,b)<<endl;
    }
    // int k;
    // cin>>k;
    // Solution s;
    // auto minsteps = s.bruteforce(k);
    // for(int i = 0;i < minsteps.size();i++)
    // {
    //     if(s.solve(k,i) != minsteps[i])
    //         cout<<i<<" "<<s.solve(k,i) <<" "<<minsteps[i]<<endl;
    // }

    return 0;
}
