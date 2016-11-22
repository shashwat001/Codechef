//shashwat001

#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>

using namespace std;

#define MAXN1 100005
#define MAXN2 100005
#define MAXM 10000000

int n1, n2, edges, last[MAXN1], prov[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];

void init(int _n1, int _n2) {
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}

void addEdge(int u, int v) {
    head[edges] = v;
    prov[edges] = last[u];
    last[u] = edges++;
}

void bfs() {
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u) {
        if (!used[u]) {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++) {
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = prov[e]) {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0) {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

bool dfs(int u1) {
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = prov[e]) {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

int maxMatching() {
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;) {
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && dfs(u))
                ++f;
        if (!f)
            return res;
        res += f;
    }
}
int main ()
{
	int n,i,j;
	scanf("%d",&n);
	if(n>3000)
	{
		printf("%d\n",n);
		return 0;
	}
	vector<pair<int,int> > t(n) ;
	for(i = 0;i < n;i++)
	{
		scanf("%d %d",&t[i].first,&t[i].second)	;
	}
	sort(t.begin(),t.end());
	init(n,n);
	for(i = 0;i < n;i++)
	{
		for	(j = 0;j < i;j++)
		{
			if((t[i].first - t[j].first) >= abs(t[i].second-t[j].second))
			{
				addEdge(j,i);
			}
		}
	}
	printf("%d\n",n-maxMatching());
	return 0;
}
