//Finding longest path in undirected tree

#include <bits/stdc++.h>
using namespace std;



int main()
{
	int n,u,v,i,h,maxh,htl;
	vector<int> ht;
	scanf("%d",&n);
	vector<int> graph[10001];
	vector<int>::iterator cur[10001] = graph[0].end();
	vector<int>::iterator it,it1;
	vector<bool> visited(n+1,false);
	for(i = 1;i < n;i++)
	{
		scanf("%d %d",&u,&v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	stack<pair<int,int> > s;
	pair<int,int> p;
	visited[2] = true;
	for(it = graph[2].begin();it!=graph[2].end();it++)
	{
		maxh = 0;
		s.push(make_pair(*it,1));
		while(!s.empty())
		{
			p = s.top();
			u = p.first;
			h = p.second;
			maxh = max(h,maxh);


			visited[u] = true;
			for(it1 = graph[u].begin();it1!=graph[u].end();it1++)
			{
				if(!visited[*it1])
				{
					s.push(make_pair(*it1,h+1));
					break;
				}
			}
			if(it1 == graph[u].end())
				s.pop();
		}
		ht.push_back(maxh);
		
	}
	sort(ht.begin(),ht.end());
	htl = ht.size();
	switch(htl)
	{
		case 0:
			printf("0\n");
			break;
		case 1:
			printf("%d\n",ht[0]);
			break;
		default:
			printf("%d\n",ht[htl-1]+ht[htl-2]);
	}
	
	
	return 0;
}
