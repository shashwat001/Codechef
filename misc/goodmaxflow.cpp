#include <bits/stdc++.h>

bool bfs(int source, int sink, vector<int>& edge[], int *prev, int n)
{
	vector<bool> visited(n,false);
	queue<int> q;
	q.push(source);
	while(!q.empty())
	{
		v = q.top();
		visited[v] = true;
		if(v == sink)
		{
			return true;
		}
		for(it = edge[v].begin();it != edge[v].end();it++)
		{
			if(!visited[*it])
			{
				q.push(*it);
				prev[*it] = v;
			}
		}
	}
	return false;
}

int main()
{
	int n;
	scanf("%d %d",&n,&m);
	for(i = 0;i < m;i++)
	{
		scanf("%d %d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	return 0;
}
