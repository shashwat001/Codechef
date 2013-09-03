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

int main ()
{

	int i,t,j,m,n,p[10005],b[105],x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		priority_queue<int> vol[105];
		for(i = 0;i < m;i++)
		{
			scanf("%d",&p[i]);
		}
		for(i = 0;i < n;i++)
		{
			scanf("%d",&b[i]);
			for(j = 0;j < b[i];j++)
			{
				scanf("%d",&x);
				vol[i].push(x);
			}
		}
		lli sum = 0;
		for(i = 0;i < m;i++)
		{
			if(!vol[p[i]].empty())
			{
				sum+=(lli)vol[p[i]].top();
				vol[p[i]].pop();
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
