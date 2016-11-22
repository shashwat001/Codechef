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

int isoverlucky(int n)
{
	while(n>0)
	{
		int r = n%10;
		if(r==4 || r==7)
		{
			return 1;
		}
		n = n/10;
	}
	return 0;
}

int main ()
{
	int i,n,t,ans;
	scanf("%d",&t);
	while(t--)
	{
		ans = 0;
		scanf("%d",&n);
		for(i = 1;i*i < n;i++)
		{
			if(n%i==0)
			{
				ans+=isoverlucky(i);
				ans+=isoverlucky(n/i);
			}
		}
		if(i*i==n)
		{
			ans+= isoverlucky(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}
