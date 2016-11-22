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

typedef long long int lli;
typedef pair<int,int> pi;

#define source 901
#define dest 902
vector<int> g[1000];
float edge[2010][2010] = {0};
int prev[1000];
int cost;
int maxflow()
{
	
	while(1)
	{
		queue<int> q;
		int last,back,v,minm;
		char visited[1000] = {0};
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

int inbounds(int x,int y,int m,int n)
{
	return (x>=0 && x<m && y>=0 && y<n);
}


int main ()
{
	int n;
	cin>>n;
	for(i = 1;i <= n;i++)
	{
		cin>>x[i]>>y[i]>>t[i]>>p[i];
		
	}
	for (unsigned int i = 1; i <= n; i += 1)
	{
		for (unsigned int j = 1; j <= n; j += 1)
		{
			if(i!=j)
			{
				int dist = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
				if(dist <= t[i]*t[i])
				{
					g[i].pb(j);
					g[j].pb(i);
					edge[i][j+n] = p[i];
					edge[j][i+n] = p[j];
				}
			}
		}
	}
	return 0;
}
