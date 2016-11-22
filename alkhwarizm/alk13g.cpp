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
lli n,i,j,k,l,sum[100006],rsum[100006],b[100006],a[100006],idx[100006];
int main ()
{
    lli t;
	scanf("%lld",&t);
	while(t--)
	{

		scanf("%lld",&n);
		sum[0] = 0;
		for(i = 1;i <= n;i++)
		{
			scanf("%lld",&a[i]);
			sum[i] = sum[i-1]+a[i];
		}
		rsum[n+1] = 0;
		for(i = n;i > 0;i--)
		{
			rsum[i] = a[i]+rsum[i+1];
		}
		b[0] = 0;
		idx[0] = -1;
		for(i = 1;i <= n;i++)
		{
			b[i] = a[i]+b[i-1];
			if(b[i]>=0)
			{
				b[i] = 0;
				idx[i] = -1;
			}
			else
			{
				if(idx[i-1]!=-1)
				{
					idx[i] = idx[i-1];
				}
				else
				{
					idx[i] = i;
				}
			}
		}
		lli maxval = INF,minidx;
		for ( i = 1; i <= n; i += 1)
		{
			if(b[i]<maxval)
			{
				maxval = b[i];
				minidx = i;
			}
		}
		if(maxval>=0)
		{
			printf("%lld\n",sum[n]);
			continue;
		}
		i = minidx;
		lli maxsum = -b[i]+sum[idx[i]-1]+rsum[i+1];

		printf("%lld\n",maxsum);
		
	}
	return 0;
}
