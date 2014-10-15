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

double sumprob,prob;
int p[51],a[55][2],n;
int f[20];
void dfs(int idx)
{
	int i;
	if(idx==n)
	{
		int hash[20] = {0};
		for(i = 0;i < n;i++)
		{
			hash[a[i][f[i]]]++;
		}
		for(i = 0;i < 20;i++)
		{
			if(hash[i]>1)
				return;
		}
		prob = 1.0;
		for(i = 0;i < n;i++)
		{
			if(f[i]==0)
			{
				prob = (prob*p[i])/100;
			}
			else
			{
				prob = (prob*(100-p[i]))/100;
			}
		}
		sumprob+=prob;
		return;
	}
	f[idx] = 0;
	dfs(idx+1);
	f[idx] = 1;
	dfs(idx+1);
}

int main ()
{
	int i,j,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i = 0;i < n;i++)
		{
			scanf("%d %d %d",&p[i],&a[i][0],&a[i][1]);
		}
		if(n>16)
		{
			printf("0.00000000\n");
			continue;
		}
		sumprob = 0;
		dfs(0);
		printf("%0.6lf\n",sumprob);
	}
	return 0;
}
