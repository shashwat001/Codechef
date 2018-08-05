#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>

using namespace std;
typedef long long int lli;
typedef pair<int, pair<int, int>> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void preprocess(int root, vector<vector<pii>> &edges, vector<bool> &visited, vector<vector<int>> &dp, vi &depth, vi &parent)
{
    queue<pii> q;
    q.push({root, {0,0}});

    dp[root] = {0,0,0,0,-1,-1};

    while(!q.empty())
    {
        pii front = q.front();
        q.pop();

        int node = front.first;
        pair<int, int> parcolor = front.second;

        visited[node] = true;


        for(int i = 0;i < edges[node].size();i++)
        {
            int cur = edges[node][i].first;
            if(!visited[cur])
            {
                depth[cur] = depth[node] + 1;
                parent[cur] = node;
                pair<int, int> color = edges[node][i].second;

                int val = max(dp[node][0], dp[node][1]);
                dp[cur] = {val, val, val, val,0,0};

                if(color.first != parcolor.first && parcolor.first != 0)
                {
                    if(dp[node][0] + 1 > val)
                    {
                        dp[cur][0] = dp[node][0] + 1;
                        dp[cur][4] = 1;
                    }
                }
                if(color.first != parcolor.second && parcolor.second != 0)
                {
                    if(dp[node][1] + 1 > val)
                    {
                        dp[cur][0] = dp[node][1] + 1;
                        dp[cur][5] = 1;
                    }
                }

                if(color.second != parcolor.first && parcolor.first != 0)
                {
                    if(dp[node][0] + 1 > val)
                    {
                        dp[cur][1] = dp[node][0] + 1;
                        dp[cur][4] = 1;
                    }
                }
                if(color.second != parcolor.second && parcolor.second != 0)
                {
                    if(dp[node][1] + 1 > val)
                    {
                        dp[cur][1] = dp[node][1] + 1;
                        dp[cur][5] = 1;
                    }
                }

                if(dp[cur][5] == 1 && dp[cur][4] == 1)
                {
                    if(parcolor.first != parcolor.second)
                        dp[cur][5] = dp[cur][4] = 0;
                }
                else if(dp[cur][5] == 1)
                {
                    dp[cur][4] = -1;
                }
                else if(dp[cur][4] == 1)
                {
                    dp[cur][5] = -1;
                }

                q.push(edges[node][i]);
            }
        }
    }
}

int directparentequal(const vector<vector<pii>> &edges, const vvi &dp, const vi &depth, const vi& parent, int U, int V)
{
    int lca = parent[U];
    pair<int, int> color1 = lower_bound(edges[lca].begin(), edges[lca].end(), make_pair(U, make_pair(0,0)))->second;
    pair<int, int> color2 = lower_bound(edges[lca].begin(), edges[lca].end(), make_pair(V, make_pair(0,0)))->second;
    bool addnew = false;
    if(color1.first != 0)
    {
        if(color2.first != 0 && color1.first != color2.first) addnew = true;
        if(color2.second != 0 || color1.first != color2.second) addnew = true;
    }

    if(color1.second != 0)
    {
        if(color2.first != 0 && color1.second != color2.first) addnew = true;
        if(color2.second != 0 || color1.second != color2.second) addnew = true;
    }

    if(addnew) return 1;
    return 0;
}

int directpath(const vector<vector<pii>> &edges, const vvi &dp, const vi &depth, const vi& parent, int U, int V)
{
    int lca = V;
    int u = U;
    while(parent[u] != V)
    {
        u = parent[u];
    }
    return max(dp[U][0], dp[U][1]) - dp[u][2];
}

int getlca(const vi &depth, const vi&parent, int u, int v)
{
    if(depth[u] < depth[v])
        swap(u,v);
    while(depth[u] > depth[v])
    {
        u = parent[u];
    }

    while(u != v)
    {
        u = parent[u];
        v = parent[v];
    }

    return u;
}

int onedirectparent(const vector<vector<pii>> &edges, const vvi &dp, const vi &depth, const vi& parent, int u, int U, int V)
{

    int lca = parent[parent[u]];
    pair<int, int> left1 = lower_bound(edges[lca].begin(), edges[lca].end(), make_pair(parent[u], make_pair(0,0)))->second;
    pair<int, int> right = lower_bound(edges[lca].begin(), edges[lca].end(), make_pair(V, make_pair(0,0)))->second;

    bool addnew = false;

    if(dp[u][4] == 1)
    {
        if(left1.first != right.first || left1.first != right.second)
        {
            addnew = true;
        }
    }

    if(dp[u][5] == 1)
    {
        if(left1.second != right.first || left1.second != right.second)
        {
            addnew = true;
        }
    }

    return max(dp[U][0], dp[U][1]) - dp[lca][2] + (addnew?1:0);
}

int nodirectparent(const vector<vector<pii>> &edges, const vvi &dp, const vi &depth, const vi& parent, int u, int v, int U, int V)
{

    int lca = parent[parent[u]];
    pair<int, int> left1 = lower_bound(edges[lca].begin(), edges[lca].end(), make_pair(parent[u], make_pair(0,0)))->second;
    pair<int, int> right1 = lower_bound(edges[lca].begin(), edges[lca].end(), make_pair(parent[v], make_pair(0,0)))->second;

    bool addnew = false;
    if((dp[u][4] == 1 || dp[u][4] == 0 )&& (dp[v][4] == 1 || dp[v][4] == 0))
    {
        if(left1.first != right1.first)
        {
            addnew = true;
        }
    }

    if((dp[u][4] == 1 || dp[u][4] == 0) && (dp[v][5] == 1 || dp[v][5] == 0))
    {
        if(left1.first != right1.second)
        {
            addnew = true;
        }
    }

    if((dp[u][5] == 1 || dp[u][5] == 0) && (dp[v][4] == 1 || dp[v][4] == 0))
    {
        if(left1.second != right1.first)
        {
            addnew = true;
        }
    }

    if((dp[u][5] == 1 || dp[u][5] == 0) && (dp[v][5] == 1 || dp[v][5] == 0))
    {
        if(left1.second != right1.second)
        {
            addnew = true;
        }
    }

    return max(dp[U][0], dp[U][1]) - dp[lca][2] + max(dp[V][0], dp[V][1]) - dp[lca][2] + (addnew?1:0);
}

int getuv(const vector<vector<pii>> &edges, const vvi &dp, const vi &depth, const vi& parent, int u, int v)
{
    int lca = getlca(depth, parent, u, v);
    if(lca == u || lca == v)
    {
        return directpath(edges, dp, depth, parent, lca^u^v, lca);
    }
    if(parent[u] == parent[v])
    {
        return directparentequal(edges, dp, depth, parent, u, v);
    }

    if(depth[u] < depth[v])
        swap(u,v);


    int U = u;
    int V = v;

    while(depth[u] > depth[lca]+2)
    {
        u = parent[u];
    }

    if(depth[v] == depth[lca]+1)
    {
        return onedirectparent(edges, dp, depth, parent, u, U, v);
    }

    while(depth[v] > depth[lca]+2)
    {
        v = parent[v];
    }

    return nodirectparent(edges, dp, depth, parent, u, v, U, V);

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
            edges[u].push_back({v,{input[i].second.second, input[i].second.second}});
            edges[v].push_back({u,{input[i].second.second, input[i].second.second}});
        }
    }

    if(i == m-1)
    {
        u = input[i].first;
        v = input[i].second.first;
        edges[u].push_back({v,{input[i].second.second, input[i].second.second}});
        edges[v].push_back({u,{input[i].second.second, input[i].second.second}});
    }

    vector<bool> visited(n,false);
    vector<vector<int>> dp(n, vector<int>(6));
    vector<int> depth(n, 0);
    vector<int> parent(n, -1);

    int trees = -1;
    for(int i = 0;i < n;i++)
    {
        //parent[i] = trees;
        //trees--;
        if(!visited[i])
        {
            preprocess(i, edges, visited, dp, depth, parent);
        }
    }

    // for(int i = 0;i < n;i++)
    // {
    //     printf("%d %d %d %d %d %d %d\n", i+1, dp[i][0], dp[i][1], dp[i][2], dp[i][3], dp[i][4], dp[i][5]);
    // }

    cin>>q;
    for(int i = 0;i < q;i++)
    {
        cin>>u>>v;
        u--;v--;
        cout<<getuv(edges, dp, depth, parent, u, v)<<endl;
    }


    return 0;
}
