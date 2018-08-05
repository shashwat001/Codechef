#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>

using namespace std;
typedef long long int lli;

bool dfs(int node, int parent, vector<bool> &visited, vector<bool> &cycle, vector<vector<int>> &edges)
{
    if(visited[node] == true)
    {
        return cycle[node] = true;
    }
    visited[node] = true;
    bool involvedincycle = false;
    for(int i = 0;i < edges[node].size();i++)
    {
        if(edges[node][i] == parent)
            continue;

        involvedincycle |= dfs(edges[node][i], node, visited, cycle, edges);
    }

    return cycle[node] = involvedincycle;

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> edges(n);
        vector<bool> cycle(n,false);
        vector<bool> visited(n, false);

        for(int i = 0;i < m;i++)
        {
            int x,y;
            cin>>x>>y;
            x--;y--;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        for(int i = 0;i < n;i++)
        {
            if(!visited[i])
                dfs(i, -1, visited, cycle, edges);
        }

        for(int i = 0;i < n;i++)
        {
            cout<<i+1<<" "<<cycle[i]<<endl;
        }

        // int maxcount = 1;
        // bool twotree = false;
        // for(int i = 0;i < n;i++)
        // {
        //     int count = 0;
        //
        //     for(int j = 0;j < edges[i].size();j++)
        //     {
        //         twotree = true;
        //         if(cycle[edges[i][j]])
        //             count++;
        //     }
        //     maxcount = max(maxcount, count+1);
        // }
        //
        // if(twotree)
        //     maxcount = max(maxcount, 2);
        // cout<<maxcount<<endl;
    }
    return 0;
}
