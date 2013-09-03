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

#define max 100000

int main ()
{
	int i,j,l;
	lli totsum = 0;
	srand(time(NULL));
	int a[100005],b[100005];
	pi range[100005];
	lli sum[100005] = {0};
	int n = rand()%1000+1;
	int m = rand()%1000+1;
	assert(n>=1 && n<=100000 && m>=1 && m<=100000);
	printf("%d %d\n",n,m);
	for(i = 1;i <= n;i++)
	{
		a[i] = rand()%1000+1;
		totsum+=(lli)a[i];
		assert(a[i]>=1 && a[i] <= 100000);
		printf("%d\n",a[i]);
		b[i] = i;
	}
	for(i = 0;i < m;i++)
	{
		range[i].second = rand()%n+1;
		range[i].first = rand()%range[i].second+1;
		assert(range[i].first <= range[i].second && range[i].first >= 1);
		printf("%d %d\n",range[i].first,range[i].second);
		for(j = range[i].first;j <= range[i].second;j++ )
		{
			sum[i]+=(lli)a[j];
		}
	}
	int ans = 0;
	int k = rand()%10000+1;
	//if(k > totsum)
		k = totsum; 
	
	printf("%d\n",k);
	for(i = 0;i < k;i++)
	{
		int j = rand()%n+1;
		assert(a[b[j]]>0);
		printf("%d\n",b[j]-ans);
		a[b[j]]--;
		int cnt = 0;
		for(l = 0;l < m;l++)
		{
			if(b[j]>=range[l].first && b[j]<=range[l].second)
			{
				sum[l]--;
				if(sum[l]==0)
				{
					assert(a[b[j]]==0);
					cnt++;
				}
			}
		}
		if(a[b[j]]==0)
		{
			b[j] = b[n];
			n--;
		}
		ans+=cnt;
	}
	
	return 0;
}
