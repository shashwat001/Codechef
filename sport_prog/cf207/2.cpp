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

void dfs(vector<int> edge[], int curtemporary, vector<set<int> > possibilities, vector<int>& mapping,int n,vector<int>& visited)
{
	int i;
	
	if(curtemporary >= n)
	{
		return ;
	}
	visited[curtemporary] = true;
	set<int>::iterator it;
	it = possibilities[curtemporary].begin();
	

	mapping[curtemporary] = *it;
	for(i = 0;i < (int)edge[curtemporary].size();i++)
	{
		if(!visited[edge[curtemporary][i]])
			possibilities[edge[curtemporary][i]].erase(*it);
	}
	for(i = 0;i < (int)edge[curtemporary].size();i++)
	{
		if(!visited[edge[curtemporary][i]])
		{
			dfs(edge,edge[curtemporary][i],possibilities,mapping,n,visited);
		}
	}
}

void ForwardChecking(vector<int> edge[], vector<int>& mapping,int n)
{
	int c;
	set<int> registerSet;
	for(c = 1; c<=3 ;c++)
	{
		registerSet.insert(c);
	}
	vector<int> visited(n);
	vector<set<int> > possibilities(n, registerSet);
	dfs(edge,0, possibilities,mapping,n,visited);
}

int main ()
{
	int n,m,i,a[3],j;
	
	scanf("%d %d",&n,&m);
	vector<int> mapping(n);	
	vector<int> edge[300004];
	for(i = 0;i < m;i++)
	{
		for (unsigned int j = 0; j < 3; j += 1)
		{
			scanf("%d",&a[j]);	
			a[j]--;
		}
		for (unsigned int j = 0; j < 3; j += 1)
		{
			edge[a[j]].pb(a[(j+1)%3]);
			edge[a[(j+1)%3]].pb(a[j]);
		}
	}
	ForwardChecking(edge,mapping,n);
	for(i = 0;i < n;i++)
	{
		printf("%d ",mapping[i]);
	}
	printf("\n");
	
	return 0;
}
