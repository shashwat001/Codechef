#include <bits/stdc++.h>
struct edge
{
	int wt,u,v;
};
int main()
{
	priority_queue<edge> p;
	vector<int> mst[1001];
	bool taken[1001] = {false};
	edge temp;
	int a[1001][1001];
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j] == 0)
				a[i][j] = INF;
		}
	}
	while(1)
	{
		temp = p.top();
		if(!taken[temp.v])
		{
			v = temp.v;
			mst[temp.u].push_back(v);
		}
		else
		{
			p.pop();
		}
		taken[v] = true;
		for(i = 0;i < n;i++)
		{
			if(!taken[i])
			{
				temp.wt = a[v][i];
				temp.u = v;
				temp.v = i;
				p.push(temp);
			}
		}
		
	}
	return 0;
}
