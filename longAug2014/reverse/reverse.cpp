#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

#define INF 100000000
#define LLINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef unsigned int uint;
typedef unsigned long long int ulli;
typedef pair<int,int> pairint;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int> edgeto[n],edgefrom[n];
	bool visited[n];
	int dist[n];
	
	fill(visited,visited+n,false);
	fill(dist,dist+n,INF);
	for(int i = 0;i < m;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		u--;v--;
		if(u == v)
			continue;
		edgeto[u].push_back(v);
		
		edgefrom[v].push_back(u);
	}
	queue<int> q;
	q.push(0);
	dist[0] = 0;
	while(!q.empty())
	{
		int u = q.front();
		
		q.pop();
		if(!visited[u])
			visited[u] =  true;
		else
			continue;
		vector<int>::iterator it;
		for(it = edgeto[u].begin();it != edgeto[u].end();it++)
		{
			if(!visited[*it])
			{
				dist[*it] = min(dist[*it],dist[u]);
				q.push(*it);
			}
		}
		for(it = edgefrom[u].begin();it != edgefrom[u].end();it++)
		{
			if(!visited[*it])
			{
				dist[*it] = min(dist[*it],dist[u]+1);
				q.push(*it);
			}
		}
	}
	if(dist[n-1] == INF)
		printf("-1\n");
	else
		printf("%d\n",dist[n-1]);
	return 0;
}
