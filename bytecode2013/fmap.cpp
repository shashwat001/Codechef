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

#define INF 2147483647
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef pair<int,int> pi;

int main ()
{
	int n,i,t,h1,h2,u,k,l,x,j,parent[10005];
	scanf("%d",&t);
	while(t--)
	{
		vector<int> par[10007];
		scanf("%d %d %d",&n,&h1,&h2);
		for(i = 1;i <= n;i++)
		{
			if(i!=h1)
			{
				scanf("%d",&x);
				parent[i] = x;
				par[x].pb(i);
			}
			
		}
		stack<int> s;
		s.push(h1);
		vector<int> newpar(n+1);
		while(!s.empty())
		{
			int u = s.top();
			if(u==h2)
				break;
			s.pop();
			for(j = 0;j < par[u].size();j++)
			{
				s.push(par[u][j]);
				newpar[par[u][j]] = u;
			}
		}
		k = h2;
		while(k!=h1)
		{
			l = newpar[k];
			parent[l] = k;
			k = l;
			
		}
		for(i = 1;i <= n;i++)
		{
			if(i!=h2)
			{
				printf("%d ",parent[i]);
			}
		}
	}
	return 0;
}
