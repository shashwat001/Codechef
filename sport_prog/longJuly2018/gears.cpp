#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>

using namespace std;
typedef long long int lli;


const int MAXL = 18;
const int MAXN = 1<<MAXL;

int a[MAXN];
int sparsetable[MAXN][MAXL];
vector<int> edges[MAXN];
int depth[MAXN];
bool blocked[MAXN];
int size[MAXN];
int prec_lg2[MAXN];
int n;


class Solution
{
public:

    void solve()
    {

        int m,x,y,v,t;
        scanf("%d %d", &n,&m);
        prec_lg2[1] = 1;
        for(int i = 2; i < MAXN; i++)
            prec_lg2[i] = prec_lg2[i >> 1] + 1;
        for(int i = 0;i < MAXN;i++)
        {
            for(int j = 0;j < MAXL;j++)
            {
                sparsetable[i][j] = -1;
            }
            depth[i] = 0;
            blocked[i] = false;
            size[i] = 1;
        }

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

    int getroot(int gear)
    {
        while(depth[gear] > 0)
        {
            gear = sparsetable[gear][prec_lg2[depth[gear]] - 1];
        }
        return gear;
    }

    void attach(int big, int small)
    {
        set<int> visited;
        int st = 0;
        sparsetable[small][st++] = big;
        depth[small] = depth[big]+1;

        int par = big;

        while(prec_lg2[depth[par]] > st-1)
        {
            sparsetable[small][st] = sparsetable[par][st-1];
            par = sparsetable[par][st-1];
            st++;
        }

        queue<int> q;
        q.push(small);

        while(!q.empty())
        {
            int top = q.front();
            visited.insert(top);
            q.pop();

            for(int j = 0;j < edges[top].size();j++)
            {
                int curr = edges[top][j];
                int parr = top;

                if(visited.find(curr) == visited.end())
                {
                    int stn = 0;
                    sparsetable[curr][stn++] = parr;
                    depth[curr] = depth[parr]+1;
                    int i = 0;
                    while(prec_lg2[depth[parr]] > stn-1)
                    {
                        sparsetable[curr][stn] = sparsetable[parr][stn-1];
                        parr = sparsetable[parr][stn-1];
                        stn++;
                    }

                    q.push(curr);
                }
            }


        }

        edges[big].push_back(small);
        edges[small].push_back(big);
    }

    void connectwhennotconnected(int gear1, int gear2)
    {
        int gear1root = getroot(gear1);
        int gear2root = getroot(gear2);
        if(size[gear1root] >= size[gear2root])
        {
            attach(gear1, gear2);
            size[gear1root] += size[gear2root];
        }
        else
        {
            attach(gear2, gear1);
            size[gear2root] += size[gear1root];
        }
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
            connectwhennotconnected(gear1, gear2);
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
        set<int> visited;
        queue<int> q;
        q.push(gear);
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            visited.insert(top);
            blocked[top] = true;

            for(int i = 0;i < edges[top].size();i++)
            {
                if(visited.find(edges[top][i]) == visited.end())
                {
                    q.push(edges[top][i]);
                }
            }
        }
    }

    int lca_special(int u, int v)
    {
        int i;
        // assert(depth[u] == depth[v]);
        // assert(sparsetable[u].size() == sparsetable[v].size());
    	for (i = prec_lg2[depth[u]] - 1;i >= 0 ;i--)
        {
    		if (sparsetable[u][i] != sparsetable[v][i])
            {
    			u = sparsetable[u][i];
    			v = sparsetable[v][i];
            }
        }
        if(depth[u] == 0)
            return -1;
    	return sparsetable[u][0];
    }

    int lca_general(int u, int v)
    {
    	if (depth[u] < depth[v])
    		swap(u, v);

    	for (int i = prec_lg2[depth[u]] - 1;i >= 0 ;i--)
        {
    		if ((depth[u] - (1<<i)) >= depth[v])
                u = sparsetable[u][i];
        }

    	if (u == v)
            return u ;

    	return lca_special(u, v);
    }

    int connected(int src, int dest)
    {
        if(getroot(src) == getroot(dest))
        {
            int lca = lca_general(src, dest);
            return depth[src]+depth[dest]-2*depth[lca];
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
