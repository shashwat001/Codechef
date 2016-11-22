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
int dob[105][105],a[200];
int dfs(int b,int e)
{
	int i;
	if(e<b)
		return 0;
	if(dob[b][e]!=-1)
		return dob[b][e];
	if(b==e)
	{
		return a[b+1] - a[b-1] - 2;
	}
	int minleft = INF,minright = INF,minval=INF;
	for(i = b;i <= e;i++)
	{
	
		minleft = dfs(b,i-1);
		minright = dfs(i+1,e);
		minval = min(minval,minleft+minright);
	}
	dob[b][e] = minval + a[e+1] -a[b-1]- 2;
	return dob[b][e];
}

int main ()
{
	int i,j,	t,n,m,z,cum[200],left[200],right[200],minm;
	scanf("%d",&t);
	
	while(t--)
	{
		int minm = INF;
		for(i = 0;i < 105;i++)
		{
			for(j = 0;j < 105;j++)
			{
				dob[i][j] = -1;
			}
		}
		scanf("%d %d",&n,&z);
		for(i = 1;i <= z;i++)
		{
			scanf("%d",&a[i]);
		}
		a[0] = 0;
		a[z+1] = n+1;
		printf("%d\n",dfs(1,z));
	}
	return 0;
}
