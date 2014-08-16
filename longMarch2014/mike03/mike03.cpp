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

int a[20006][25] = {{0}};

int edge[20][20] = {{0}};
int n,m,i,j;
int s[20] = {0};
int maxcnt = 0;

void dfs(int offer)
{
	if(offer == m)
	{
		int cnt = 0;
		for(i = 0;i < m;i++)
		{
			if(s[i]==1)
			{
				for(j = 0;j < m;j++)
				{
					if(edge[i][j]==1 && s[j]==1)
					{
						return ;
					}
				}
				cnt++;
			}
		}
		maxcnt = max(maxcnt,cnt);
		
		return;
	}
	s[offer] = 1;
	dfs(offer+1);
	s[offer] = 0;
	dfs(offer+1);
}

int main ()
{
	int k,temp,l;
	cin>>n>>m;
	for(i = 0;i < m;i++)
	{
		cin>>k;
		for (j = 0; j < k; j += 1)
		{
			cin>>temp;
			temp--;
			for(l = 0;l < i;l++)
			{
				if(a[temp][l]==1)
				{
					edge[i][l] = 1;
					edge[l][i] = 1;
				}
			}
			a[temp][i] = 1;
		}
	}
	dfs(0);
	cout<<maxcnt<<endl;
	return 0;
}
