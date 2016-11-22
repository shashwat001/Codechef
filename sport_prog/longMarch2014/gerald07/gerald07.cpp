//shashwat001  
//Thursday 13 March 2014 11:58:55 PM IST

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back
#define MAXN 200003

typedef long long int lli;
typedef pair<int,int> pi;


vector<pi > a,edge;
vector<pi >::iterator it;
int P[30][MAXN],R[30][MAXN],size[30][MAXN];
int edgelevel[MAXN],tree[30][MAXN];
int maxle;
void init(int N) 
{
    for(int j = 0;j < 30;j++)
    {
        for(int i=1;i<=N;i++) 
        {
            P[j][i] = i;
            size[j][i] = 1;
            R[j][i] = 0;
        }
    }
}
int find(int level,int n) 
{
    if(P[level][n] == n) return n;
    int k = find(level,P[level][n]);
    return k;
}

void addlength(int level,int n, int num)
{
    size[level][n] += num;
    while(P[level][n]!=n)
    {
        n = P[level][n];
        size[level][n] += num;
    }
}

void join(int level,int a, int b)
{
    a = find(level,a);
    b = find(level,b);
    if(a == b) return;
    if(R[level][a] < R[level][b]) 
    {
        P[level][a] = b;
        addlength(level,b,size[level][a]);
    }
    else 
    {
        P[level][b] = a;
        addlength(level,a,size[level][b]);
        if(R[level][a] == R[level][b]) R[level][a]++;
    }
}


void insert(int index)
{
   int u = edge[index].first;
   int v = edge[index].second;
    int l;
   for(l = maxle;l >= 0;l--)
   {
        int uindex = find(l,u);
        int vindex = find(l,v);
        if(uindex == vindex)
        {
            //in same tree already
        }
        else
        {
            join(l,u,v);
            tree[l][index] = 1;
        }
   }
}

void increaselevel(int level, int root)
{
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(it = edgelist[level][u].begin();it != edgelist[level][u].end();it++)
        {
            q.push(it->first);
            edgelevel[it->second] = level+1;
            P[level+1][it->first] = u;
            edgelist[level+1][u].pb(*it);
        }
    }
}

void reconnect(int index,int level)
{
    int u = edge[index].first;
    int v = edge[index].second;
    int uroot = find(level,u);
    int vroot = find(level,v);

    if(size[level][uroot] < size[level][vroot])
    {
        increaselevel(level,uroot);
    }
}

void deleteedge(int level,int index)
{
    int u = edge[index].first;
    int v = edge[index].second;
    int l;
    if(tree[level][index] == 0)
    {
        //not a tree index tree index nothing to do
    }
    else
    {
        if(P[level][u] == v)
        {
            parent = v;
            child = u;
        }
        else
        {
            parent = u;
            child = v;
        }
        P[level][child] = child;
        addlength(level,parent,-size[level][child]);
        tree[level][index] = 0;
        reconnect(index,level);
        deleteedge(level-1,index);

    }
}
void solve()
{
    int inserted = 0;
    int removed = 0;
    for(it = a.begin();it != a.end();it++)
    {
        while(inserted <= it->second)
        {
            insert(inserted+1);
        }
    }
}
int main(int argc, char *argv[])
{
    int n,m,q,i,x,y;
    cin>>n>>m>>q;
//    for(i = 1;i <= n;i++)
//        parent[0][i] = i;
    edge.pb(mp(0,0));
    init(n);
    for (i = 0; i < m; i++) 
    {
        cin>>x>>y;
        edge.pb(mp(x,y));    
    }
    for (i = 0; i < q; i++) 
    {
        cin>>x>>y;
        a[i] = mp(x,y);
    }
    sort(a.begin(),a.end());
    solve();
    return 0;
}
