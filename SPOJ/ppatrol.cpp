#include <cstdio>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
vector<int> v[21];
int visited[21],seq[21],a;
int ca,ccount;

void dfs(int node,int i)
{
	vector<int>::iterator it;
	int j;
	if(node==a)
	{
		ccount++;
		for(j = 0;j < i;j++)
		{
			printf("%d ",seq[j]);
		}
		printf("%d\n",a);
		return ;
	}
	visited[node] = 1;
	seq[i] = node;
	for(it = v[node].begin();it!=v[node].end();it++)
	{
		if(!visited[*it])
			dfs(*it,i+1);
	}
	visited[node] = 0;
}
int main()
{
	int m,n,k,i;
	ca = 1;
	while(scanf("%d",&a)!=-1)
	{
		ccount = 0;
		for(i = 0;i < 21;i++)
		{
			v[i].clear();
		}
		scanf("%d %d",&m,&n);
		while(m!=0)
		{
			v[m].push_back(n);
			v[n].push_back(m);
			scanf("%d %d",&m,&n);	        
		}
		for(i = 0;i < 21;i++)
		{
			sort(v[i].begin(),v[i].end());
		}
		printf("CASE %d:\n",ca);
		dfs(1,0);
		printf("There are %d routes from the police station to street corner %d.\n",ccount,a);
		ca++;
	}		
	return 0;
}
