#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>

#define S1(n) scanf("%d", &n)
#define S2(a,b) scanf("%d %d", &a, &b)

using namespace std;

int v[4000000] = {0};

typedef struct nodeinfo
{
    int color;
    int count;

    bool operator=(const nodeinfo &a)
    {
        return color==a.color;
    }

    nodeinfo(int color, int count):color(color),count(count)
    {}
} nodeinfo;

class Solution
{
public:



    void solve()
    {
        int n,m;
        S2(n,m);

        bool isalldifferent = true;

        vector<vector<int>> a(n, vector<int>(m));
        vector<vector<vector<nodeinfo>>> s(n, vector<vector<nodeinfo>>(m));

        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                S1(a[i][j]);
                a[i][j]--;
                if(v[a[i][j]] != 0)
                {
                    isalldifferent = false;
                    break;
                }
                v[a[i][j]]++;
            }
            if(!isalldifferent)
                break;
        }

        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(i==0 && j == 0)
                {
                    s[i][j].push_back(nodeinfo(a[i][j], 1));
                }
//////////////////////////////////////////////////////////////////////////////////
                else if(i == 0)
                {
                    if(a[i][j] != a[i][j-1])
                    {
                        auto it = find(s[i][j-1].begin(), s[i][j-1].end(), nodeinfo(a[i][j], 0));
                        if(it != s[i][j-1].end())
                        {
                            s[i][j].push_back(nodeinfo(a[i][j-1], it->count+1));
                        }
                        else
                        {
                            s[i][j].push_back(nodeinfo(a[i][j-1], 2));
                        }

                        s[i][j].push_back(nodeinfo(a[i][j], 1));
                    }
                    else
                    {
                        s[i][j] = s[i][j-1];
                        for(auto &ni : s[i][j])
                        {
                            ni.count++;
                        }
                    }
                }
////////////////////////////////////////////////////////////////////////////////
                else if(j == 0)
                {
                    if(a[i][j] != a[i-1][j])
                    {
                        auto it = find(s[i-1][j].begin(), s[i-1][j].end(), nodeinfo(a[i][j], 0));
                        if(it != s[i-1][j].end())
                        {
                            s[i][j].push_back(nodeinfo(a[i-1][j], it->count+1));
                        }
                        else
                        {
                            s[i][j].push_back(nodeinfo(a[i-1][j], 2));
                        }

                        s[i][j].push_back(nodeinfo(a[i][j], 1));
                    }
                    else
                    {
                        s[i][j] = s[i-1][j];
                        for(auto &ni : s[i][j])
                        {
                            ni.count++;
                        }
                    }
                }
////////////////////////////////////////////////////////////////////////////////
                else
                {
                    if(a[i][j] != a[i][j-1])
                    {
                        auto it = find(s[i][j-1].begin(), s[i][j-1].end(), nodeinfo(a[i][j], 0));
                        if(it != s[i][j-1].end())
                        {
                            s[i][j].push_back(nodeinfo(a[i][j-1], it->count+1));
                        }
                        else
                        {
                            s[i][j].push_back(nodeinfo(a[i][j-1], 2));
                        }

                        s[i][j].push_back(nodeinfo(a[i][j], 1));
                    }
                    else
                    {
                        s[i][j] = s[i][j-1];
                        for(auto &ni : s[i][j])
                        {
                            ni.count++;
                        }
                    }
                }
            }
        }

        if(isalldifferent)
        {
            printf("2");
        }
        else
        {
            assert(false);
        }
    }
};

int main()
{
    Solution().solve();
    return 0;
}
