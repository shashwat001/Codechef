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

int main ()
{
	int d[100],t,n,i,j,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i = 0;i < n;i++)
		{
			scanf("%d",&d[i]);
		}
		int sum = 0;
		for(i = 0;i < n;i++)
		{
			scanf("%d",&x);
			d[i] = d[i]-x;
			sum -= d[i];
		}
		if(n==1)
		{
			if(d[0]>=0)
			{
				printf("%d\n",d[0]);
			}
			else
			{
				printf("-1\n");
			}
			continue;
		}
		if(n==2)
		{
			if(d[0]==-d[1])
			{
				printf("%d\n",abs(d[0]));
			}
			else
			{
				printf("-1\n");
			}
			continue;
		}
		if(sum%(n-2)!=0)
		{
			printf("-1\n");
			continue;
		}
		int k = sum/(n-2);
		for(i = 0;i < k;i++)
		{
			int minv = -10000;
			int minidx;
			for (j = 0; j < n; j += 1)
			{
				if(minv < d[j])
				{
					minv = d[j];
					minidx = j;
				}
			}
			for (j = 0; j < n; j += 1)
			{
				if(j==minidx)
				{
					d[j]-=1;
				}
				else
				{
					d[j]+=1;
				}
			}
		}
		for(i = 0;i < n;i++)
		{
			if(d[i]!=0)
			{
				printf("-1\n");
				break;
			}
		}
		if(i==n)
		{
			printf("%d\n",k);
		}
	}
	return 0;
}
