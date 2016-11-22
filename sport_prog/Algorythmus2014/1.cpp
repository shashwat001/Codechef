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

int a[1005][1005];
bool visited[1004][1005];
int n;
bool inbound(int i,int j)
{
	return i>=0 && i<n && j>=0 && j<n;
}

int di[] = {1,1,1,-1,-1,-1,0,0};
int dj[] = {1,0,-1,1,0,-1,1,-1};
void dfs(int i,int j)
{
	visited[i][j] = true;
	for (unsigned int ii = 0; ii < 8; ii += 1)
	{
		for (unsigned int jj = 0; jj < 8; jj += 1)
		{
			int ci = i+di[ii];
			int cj = j+dj[jj];
		
			if(inbound(ci,cj) && a[ci][cj]==1 && (!visited[ci][cj]))
			{
				dfs(ci,cj);
			}
		}
	}
}

int main ()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		cin>>n;
		for(i = 0;i < n;i++)
		{
			for (unsigned int j = 0; j < n; j += 1)
			{
				cin>>a[i][j];
				visited[i][j] = false;
			}
		}
		int count = 0;
		for(i = 0;i < n;i++)
		{
			for (unsigned int j = 0; j < n; j += 1)
			{
				if((!visited[i][j]) && a[i][j]==1)
				{
					dfs(i,j);
					count++;
				}
			}
		}
		cout<<count<<endl;
		
	}
	return 0;
}
