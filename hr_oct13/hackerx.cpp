//shashwat001

#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <list>
#include <set>

using namespace std;

#define MAXN1 100005
#define MAXN2 100005
#define MAXM 10000000
#define pb push_back

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

typedef struct
{
	int val;
	set<int> parents;
} node;


int main ()
{
	int n,i,j;
	scanf("%d",&n);

	vector<pair<int,int> > t(n) ;
	for(i = 0;i < n;i++)
	{
		scanf("%d %d",&t[i].first,&t[i].second)	;
	}
	sort(t.begin(),t.end());
	init(n,n);
	

	int vertices = n;
	vector<int> parents;
	list<node> right;
	list<node>::iterator lit,tempit;
	for(i = 0;i < n;i++)
	{

		bool assigned = false;
		lit = right.begin();
		for(;lit != right.end();)
		{
			int k = lit->val;
			if((t[i].first - t[k].first) >= abs(t[i].second-t[k].second))
			{
				addEdge(lit->val,lit->val);
				if(!assigned)
				{
					
					lit->val = i;
					//vertices--;
					tempit = lit;
					assigned = true;
					lit++;
					break;
				}
				else
				{
					set<int>::iterator sit;
					for(sit = lit->parents.begin();sit!= lit->parents.end();sit++)
					{
						tempit->parents.insert(*sit);
					}
					//vertices--;
					lit = right.erase(lit);
				}
			}
			else
			{
				lit++;
			}
		}
		for(j = 0;j < parents.size();j++)
		{
			int k = parents[j];
			if((t[i].first - t[k].first) >= abs(t[i].second-t[k].second))
			{
				if(!assigned)
				{
					node tempnode;
					tempnode.val = i;
					tempnode.parents.insert(k);
					right.pb(tempnode);
					assigned = true;
					tempit = right.end();
					tempit--;
				}
				else
				{
					tempit->parents.insert(k);
				}
			}
		}
		if(!assigned)
			parents.pb(i);
	}
	for(lit = right.begin();lit != right.end();lit++)
	{
		set<int>::iterator sit;
		for(sit = lit->parents.begin();sit !=  lit->parents.end();sit++)
		{
			addEdge(*sit,lit->val);
		}
	}
	printf("%d\n",n-maxMatching());
	return 0;
}
