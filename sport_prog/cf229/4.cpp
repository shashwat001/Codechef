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

int n,m,mx,my;
bool visited[56][56] = {false};
bool inbound(int x,int y)
{
	return (x>=1 && x<= n && y>=0 && y<=m);
}
void dfs(int x,int y,int steps)
{
	if(steps==0)
	{
		printf("(%d,%d) ",x,y);
		return;
	}
	if(!visited[x+1][y])
	{
		visited[x+1][y] = true;
		printf("(%d,%d) ",x,y);
		dfs(x+1,y,steps-1);
		return;
	}
	if(inbound(x,y+1) && !visited[x][y+1])
	{
		
		visited[x][y+1] = true;
		printf("(%d,%d) ",x,y);
		dfs(x,y+1,steps-1);
	}
	
}

int main ()
{
	int k,i,j;
	
	vector<int> v;
	cin>>n>>m>>k;
	int minm = min(m,n);
	int maxm = max(m,n);
	for (unsigned int i = 0; i < maxm+minm; i += 1)
	{
		if(i<minm)
		{
			v.pb(i+1);
			continue;
		}
		if(i<maxm)
		{
			v.pb(minm);
			continue;
		}
		v.pb(maxm+minm-i-1);
	}
	int sum = 0,tot = 0;;
	for ( i = 0; i < maxm+minm; i += 1)
	{
		sum+=v[i];
		if(k>sum)
		{
			tot += v[i]*(i+1);
		}
		else
			break;
	}
	int last = (k-(sum-v[i]));
	tot+=last*(i+1);
	cout<<tot<<endl;
	for(j = i;j >= 0;j--)
	{
		if(j==i)
		{
			for (unsigned int k = 0; k < last; k += 1)
			{
				dfs(1,1,j);
			}
		}
		else
		{
			for (unsigned int k = 0; k < v[j]; k += 1)
			{
				dfs(1,1,j);
				
			}
		}
		cout<<endl;
	}
	return 0;
}
