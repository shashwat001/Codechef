#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>

using namespace std;
typedef long long int lli;
typedef pair<int, pair<int, int>> ppi;

int getuv(vector<vector<ppi>> &edges, int u, int v)
{
    vector<bool> visited(edges.size());
    vector<ppi> parent(edges.size(), {-1,{0,0}});

    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        visited[top] = true;
        if(top == v)
            break;
        for(int i = 0;i < edges[top].size();i++)
        {
            int cur = edges[top][i].first;
            if(!visited[cur])
            {
                parent[cur] = edges[top][i];
                parent[cur].first = top;
                q.push(cur);
            }
        }

    }

    u = parent[v].first;
    vector<pair<int, int>> path;

    while(u != -1)
    {
        path.push_back(parent[v].second);
        v = u;
        u = parent[v].first;
    }

    int dp[path.size()][2];
    dp[0][0] = 0;
    dp[0][1] = 0;
    for(int i = 1;i < path.size();i++)
    {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = max(dp[i-1][0], dp[i-1][1]);

        if(path[i].first != 0 && path[i-1].first != 0 && path[i].first != path[i-1].first)
        {
            dp[i][0] = dp[i-1][0] + 1;
        }
        else if(path[i].first != 0 && path[i-1].second != 0 && path[i].first != path[i-1].second)
        {
            dp[i][0] = max(dp[i][0], dp[i-1][1]+1);
        }

        if(path[i].second != 0 && path[i-1].first != 0 && path[i].second != path[i-1].first)
        {
            dp[i][1] = dp[i-1][0] + 1;
        }
        else if(path[i].second != 0 && path[i-1].second != 0 && path[i].second != path[i-1].second)
        {
            dp[i][1] = max(dp[i][1], dp[i-1][1]+1);
        }
    }

    if(path.size() == 0) return 0;
    return max(dp[path.size()-1][0], dp[path.size()-1][1]);

}

int main()
{
    int n,m,u,v,w,q;
    cin>>n>>m;

    vector<vector<pair<int, pair<int, int>>>> edges(n);

    vector<pair<int, pair<int, int>>> input(m);

    for(int i = 0;i < m;i++)
    {
        cin>>u>>v>>w;
        u--;v--;
        if(u>v)
            swap(u,v);
        input[i] = {u,{v,w}};
    }

    sort(input.begin(), input.end());
    int i;
    for(i = 0;i < m-1;i++)
    {
        u = input[i].first;
        v = input[i].second.first;
        if(input[i+1].first == u && input[i+1].second.first == v)
        {
            edges[u].push_back({v,{input[i].second.second, input[i+1].second.second}});
            edges[v].push_back({u,{input[i].second.second, input[i+1].second.second}});
            i++;
        }
        else
        {
            edges[u].push_back({v,{input[i].second.second, 0}});
            edges[v].push_back({u,{input[i].second.second, 0}});
        }
    }

    if(i == m-1)
    {
        u = input[i].first;
        v = input[i].second.first;
        edges[u].push_back({v,{input[i].second.second, 0}});
        edges[v].push_back({u,{input[i].second.second, 0}});
    }


    cin>>q;
    for(int i = 0;i < q;i++)
    {
        cin>>u>>v;
        u--;v--;
        cout<<getuv(edges, u, v)<<endl;
    }


    return 0;
}
