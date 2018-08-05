#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>

using namespace std;
typedef long long int lli;

class Solution
{
public:
    vector<int> a;
    vector<vector<int>> edges;
    vector<bool> blocked;
    vector<bool> visited;

    void solve()
    {

        int n,m,x,y,v,t;
        scanf("%d %d", &n,&m);

        a.resize(n);
        edges.resize(n);
        blocked.resize(n, false);
        visited.resize(n);

        for(int i = 0;i < n;i++)
        {
            scanf("%d", &a[i]);
        }

        for(int i = 0;i < m;i++)
        {
            scanf("%d", &t);
            if(t == 1)
            {
                scanf("%d %d", &x,&y);
                x--;
                change(x,y);
            }

            else if(t == 2)
            {
                scanf("%d %d", &x,&y);
                x--;y--;
                connect(x,y);
            }

            else if(t == 3)
            {
                scanf("%d %d %d", &x,&y,&v);
                x--;y--;
                findspeed(x,y,v);
            }
        }
    }

    void change(int gear, int count)
    {
        a[gear] = count;
    }

    void connect(int gear1, int gear2)
    {
        if(blocked[gear1] && !blocked[gear2])
        {
            block(gear2);
            return;
        }

        if(blocked[gear2] && !blocked[gear1])
        {
            block(gear1);
            return;
        }

        int distance = connected(gear1, gear2);
        if(!distance)
        {
            edges[gear1].push_back(gear2);
            edges[gear2].push_back(gear1);
        }
        else
        {
            if(distance%2 == 0)
            {
                block(gear1);
            }
        }
    }

    void block(int gear)
    {
        fill(visited.begin(), visited.end(), false);
        queue<pair<int, int>> q;
        q.push({gear,0});
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            visited[top.first] = true;
            blocked[top.first] = true;

            for(int i = 0;i < edges[top.first].size();i++)
            {
                if(!visited[edges[top.first][i]])
                {
                    q.push({edges[top.first][i], top.second+1});
                }
            }
        }
    }

    int connected(int src, int dest)
    {
        fill(visited.begin(), visited.end(), false);
        queue<pair<int, int>> q;
        q.push({src,0});
        while(!q.empty())
        {
            auto top = q.front();
            if(top.first == dest)
                return top.second;
            q.pop();
            visited[top.first] = true;

            for(int i = 0;i < edges[top.first].size();i++)
            {
                if(!visited[edges[top.first][i]])
                {
                    q.push({edges[top.first][i], top.second+1});
                }
            }
        }
        return 0;
    }

    void findspeed(int gear1, int gear2, int speed1)
    {
        if(blocked[gear1] || blocked[gear2])
        {
            printf("%d\n", 0);
        }
        else
        {
            int distance = connected(gear1, gear2);
            if(distance == 0)
            {
                printf("%d\n", 0);
                return;
            }
            lli num = (lli)speed1*a[gear1];
            lli den = (lli)a[gear2];
            lli gcd = getgcd(num, den);
            if(distance%2 == 0)
            {
                printf("%lld/%lld\n",num/gcd,den/gcd);
            }
            else
            {
                printf("-%lld/%lld\n",num/gcd,den/gcd);
            }
        }
    }

    lli getgcd(lli a, lli b)
    {
        if(a%b)
            return getgcd(b, a%b);
        return b;
    }
};

int main()
{
    Solution s;
    s.solve();
    return 0;
}
