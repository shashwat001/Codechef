//shashwat001

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
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

#define MAXN 100006
#define LOGMAXN 20
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef pair<int,int> pi;

int P[MAXN][LOGMAXN],L[100006];
void process3(int N, int T[MAXN] )
  {
      int i, j;
   
  //we initialize every element in P with -1
      for (i = 0; i <= N; i++)
          for (j = 0; 1 << j <= N; j++)
              P[i][j] = -1;
   
  //the first ancestor of every node i is T[i]
      for (i = 1; i <= N; i++)
          P[i][0] = T[i];
   
  //bottom up dynamic programing
      for (j = 1; 1 << j <= N; j++)
         for (i = 1; i <= N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
  }
  
   int query(int N, int T[],  int p, int q)
  {
      int tmp, log, i;
   
  //if p is situated on a higher level than q then we swap them
      if (L[p] < L[q])
          tmp = p, p = q, q = tmp;
  
  //we compute the value of [log(L[p)]
      for (log = 1; 1 << log <= L[p]; log++);
      log--;
   
  //we find the ancestor of node p situated on the same level
  //with q using the values in P
      for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];
   
      if (p == q)
          return p;
   
  //we compute LCA(p, q) using the values in P
      for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];
   
      return T[p];
  }
int main ()
{
	int i,n,m,a,b,c,d,parent[100006] = {0},p[100006],y,x;
	scanf("%d %d %d" ,&n,&m,&d);
	vector<int> neigh[100005];
	pi range[100006];
	for(i = 0;i < 100006;i++)
		range[i] = mp(100006,100006);
	int root[100006] = {0},rot;
	for(i = 0;i < m;i++)
	{
		scanf("%d",&p[i]);
		range[p[i]] = mp(d,d);
	}
	for(i = 0;i < n-1;i++)
	{
		scanf("%d %d",&x,&y);
		parent[x] = y;
		root[x] = 1;
		neigh[y].pb(x);
	}
	for(i = 1;i<=n;i++)
	{
		if(root[i]==0)
		{
			rot = i;
			break;
		}
	}
	stack<int> s;
	s.push(rot);
	L[rot] = 1;
	while(!s.empty())
	{
		int u = s.top();
		s.pop();
		for(int j = 0;j < neigh[u].size();j++)
		{
			s.push(neigh[u][j]);
			L[neigh[u][j]] = L[u]+1;
		}		
	}
	
	process3(n,parent);
	int lca;
	for(i = 1;i < m;i++)
	{
		lca = query(n,parent,p[i-1],p[i]);
		int minup = min(range[lca].first  , range[p[i]].first - L[p[i]]+L[lca]);
		minup = min(minup,range[p[i-1]].first - L[p[i-1]]+L[lca]);
		
		int mindown = min(range[lca].second, range[p[i]].second+L[p[i]]-L[lca]);
		mindown = min(mindown, range[p[i]].second+L[p[i]]-L[lca]);
		range[lca] = mp(minup,mindown);
	}

	s.push(lca);
	L[lca] = 0;
	int cnt = 0; 
	while(!s.empty())
	{
		int u = s.top();
		s.pop();
		if(L[u]<range[lca].second)
		{
			for(int j = 0;j < neigh[u].size();j++)
			{
				s.push(neigh[u][j]);
				L[neigh[u][j]] = L[u]+1;
				cnt++;
			}	
		}	
	}
	printf("%d",cnt+range[lca].first);
	return 0;
}
