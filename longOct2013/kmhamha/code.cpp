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
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

#define source 0
#define dest 2001

typedef long long int lli;
typedef pair<int,int> pi;

vector<int> g[2005];
int edge[2005][2005] = {0};
int prev[2005];
int cost;

int maxflow()
{
	
	while(1)
	{
		queue<int> q;
		int last,back,v,minm;
		char visited[2005] = {0};
		vector<int>::iterator it;
		q.push(source);
		visited[source] = 1;
		while(!q.empty())
		{
			v = q.front();
			if(v == dest)
			{
				break;
			}
			
			q.pop();
			for(it = g[v].begin(); it!=g[v].end();it++)
			{
				if((!visited[*it]) && (edge[v][*it]!=0))
				{
					q.push(*it);
					visited[*it] = 1;
					prev[*it] = v;
				}
			}		
		}
		if(q.empty())
		{
			return cost;
		}
		back = prev[dest];
		minm = edge[back][dest];
		while(back!=source)
		{
			last = prev[back];
			if(edge[last][back] < minm)
				minm = edge[last][back];
			back = last;
		}
	
		back = prev[dest];
		edge[back][dest] -= minm;
		edge[dest][back] += minm;
		while(back!=source)
		{
			last = prev[back];
			edge[last][back] -= minm;
			edge[back][last] += minm;
			back = last;
		}
		cost+=minm;
	}
	
}



int main ()
{
	int n,t,i;
	scanf("%d",&t);
	while(t--)
	{
		pi a[1005];
		scanf("%d",&n);
		for(i = 0;i < n;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			a[i].first = x;
			a[i].second = y;
		}
		for(i = 0;i < 2005;i++)
		{
			g[i].clear();
		}
		sort(a,a+n);
		int inx = 1;
		
		int temp = a[0].first;
		a[0].first = inx;
		for(i = 1;i < n;i++)
		{
			if(a[i].first==temp)
			{
				a[i].first = inx;
			}
			else
			{
				temp = a[i].first;
				a[i].first = ++inx;
			}
		}
		
		for(i = 0;i < n;i++)
		{
			int temp = a[i].first;
			a[i].first = a[i].second;
			a[i].second = temp;
		}
		
		sort(a,a+n);
		inx = 1001;
		
		temp = a[0].first;
		a[0].first = inx;
		for(i = 1;i < n;i++)
		{
			if(a[i].first==temp)
			{
				a[i].first = inx;
			}
			else
			{
				temp = a[i].first;
				a[i].first = ++inx;
			}
		}

		memset(edge,0,sizeof(int)*2005*2005);
		for(i = 1001;i <= 2000;i++)
		{
			edge[i][dest] = 1;
			g[i].pb(dest);
			g[dest].pb(i);
		}

		for(i = 1;i <= 1000;i++)
		{
			edge[source][i] = 1;
			g[i].pb(source);
			g[source].pb(i);
		}
		for ( i = 0; i < n; i += 1)
		{
			edge[a[i].second][a[i].first] = 1;
			g[a[i].second].pb(a[i].first);
			g[a[i].first].pb(a[i].second);
		}
		cost = 0;
		printf("%d\n",maxflow());
		
	}
	return 0;
}
