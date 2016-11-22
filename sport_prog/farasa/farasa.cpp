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

int main ()
{
	int a[100],n,s[100],hash[100000],i;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
	}
	s[0] = 0;
	for(i = 1;i <= n;i++)
	{
		s[i] = s[i-1]+a[i-1];
	}
	int maxsum = 0;
	for(i = 1;i <= n;i++)
	{
		for (int j = i; j <= n; j += 1)
		{
			int sum = s[j] - s[i-1];
			hash[sum] = 1;
			if(maxsum < sum)
				maxsum = sum;
		}
	}
	int c = 0;
	for(i = 0;i <= maxsum;i++)
	{
		if(hash[i]>0)
			c++;
	}
	printf("%d\n",c);
	return 0;
}
