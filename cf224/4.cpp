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

int d[2006][2006];
bool visited[2006][2006];
char s[2006][2006];
int dfs(int i,int j)
{
	if(s[i][j]=='#')
		return 0;
	if(visited[i][j])
	{
		if(d[i][j]==-1)
			return 10000000;
		else
			return d[i][j];
	}
	visited[i][j] = true;
	if(s[i][j]=='>')
	{
		d[i][j] = dfs(i,j+1)+1;
	}
	else if(s[i][j]=='<')
	{
		d[i][j] = dfs(i,j-1)+1;
	}
	else if(s[i][j]=='^')
	{
		d[i][j] = dfs(i-1,j)+1;
	}
	else if(s[i][j]=='v')
	{
		d[i][j] = dfs(i+1,j)+1;
	}
	return d[i][j];
}

bool dfs2(int i,int j)
{
	if(s[i][j]=='#')
	
		return true;
	if(visited[i][j])
	{
		return false;
	}
	visited[i][j] = true;
	bool dec;
	if(s[i][j]=='>')
	{
		dec = dfs2(i,j+1);
	}
	else if(s[i][j]=='<')
	{
		dec = dfs2(i,j-1);
	}
	else if(s[i][j]=='^')
	{
		dec = dfs2(i-1,j);
	}
	else if(s[i][j]=='v')
	{
		dec = dfs2(i+1,j);
	}
	return dec;
}


int main ()
{
	int i,j,n,m,cc;
	
	cin>>n>>m;
	for(i = 0;i < n;i++)
	{
		cin>>s[i];
	}
	for(i = 0;i < n;i++)
	{
		for ( j = 0; j < m; j += 1)
		{
			d[i][j] = -1;
			visited[i][j] = false;
		}
	}
	for(i = 0;i < n;i++)
	{
		for ( j = 0; j < m; j += 1)
		{
			if(visited[i][j])
				continue;
			if(s[i][j]=='#')
			{
				visited[i][j] = true;
				d[i][j] = 0;
				continue;
			}
			dfs(i,j);
		}
	}
	int maxm = 0;
	for(i = 0;i < n;i++)
	{
		for ( j = 0; j < m; j += 1)
		{
			maxm = max(maxm,d[i][j]);
			visited[i][j] = false;
		}
	}
	if(maxm >= 10000000)
	{
		cout<<"-1";
		return 0;
	}
	cc = 0;
	for(i = 0;i < n;i++)
	{
		for ( j = 0; j < m; j += 1)
		{
			if(d[i][j]==maxm)
			{
				if(dfs2(i,j)==true)
				{ cc++;
					}
			}
		}
	}
	if(cc == 1)
		cout<<max(2*maxm-1,0);
	else cout<<2*maxm;
	return 0;
}
