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

int ones,ntree;
bool visited[100004] = {false};
vector<int> edge[100005];
int a[100000];


pair<int,int> dfs(int root)
{
	ntree++;
	ones+=a[root];
	visited[root] = true;
	pair<int,int > ret;
	ret.first = 0;
	ret.second = a[root];
	vector<int>::iterator it;
	for(it = edge[root].begin();it!=edge[root].end();it++)
	{
		if(visited[*it])
			continue;
		pair<int,int> p = dfs(*it);
		ret.second |= p.second;
		ret.first+=p.first;
	}
	if(ret.second == 0)
	{
		ret.first++;
	}
	return ret;
}

int main ()
{
	int n,m,i;
	cin>>n>>m;
	
	for(i = 0;i < n;i++)
	{
		cin>>a[i];

	}
	for(i = 0;i < m;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		edge[x].pb(y);
		edge[y].pb(x);
	}
	lli totways = 0;
	int totpass = 0;
	for(i = 0;i < n;i++)
	{
		if(visited[i])
			continue;
		if(a[i]==1)
		{
			ntree = 0;
			ones = 0;
			pair<int,int> p = dfs(i);
			if(ones > 1)
			{
				lli ways = ones;
				ways = (ways*(ways-1))/2;
				int dpass = ntree-p.first;
				totways+=ways;
				totpass +=dpass;
			}
		}
	}
	cout<<totways<<" "<<totpass<<endl;
	return 0;
}
