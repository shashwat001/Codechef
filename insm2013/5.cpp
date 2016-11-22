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
	int t,n,a[100007],i,j,b[100007],c[100007];
	pi p[100007];
int main ()
{

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
			p[i] = mp(a[i],i);
		}
		sort(p,p+n);
		int cb = 0;
		for ( i = 0; i < n; i += 1)
		{
			if(i!=p[n-1].second && i!=p[n-2].second)
			{
				b[cb++] = a[i];	
			}
		}
		int side = cb/3;
		sort(b,b+side-1);
		sort(b+cb-side+1,b+cb);
		for(i = 0;i < side;i++)
		{
			c[i] = b[i];
		}
		c[i] = p[n-2].second > p[n-1].second ? p[n-1].first : p[n-2].first;
		
		for(i = side+1;i<n-side-1;i++)
		{
			c[i] = 0;
		}
		c[n-side-1] = p[n-2].second < p[n-1].second ? p[n-1].first : p[n-2].first;
		for(i = n-side;i < n;i++)
		{
			c[i] = b[--cb];
		}
		for(i = 0;i < n;i++)
		{
			printf("%d ",c[i]);
		}
		printf("\n");
		
	}
	return 0;
}
