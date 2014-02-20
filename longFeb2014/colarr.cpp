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
int b[1004][1003],c[1009][1004];
int main ()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,k,i,j,a[1004];
		scanf("%d %d %d",&n,&m,&k);
		for ( i = 0; i < n; i += 1)
		{
			scanf("%d",&a[i]);
			a[i]--;
		}
		int sum = 0;
		for(i = 0;i < n;i++)
		{
			for ( j = 0; j < m; j += 1)
			{
				scanf("%d",&b[i][j]);
				if(j==a[i])
				{
					sum+=b[i][a[i]];
				}
			}
		}
		vector<pi > v;
		
		for ( i = 0; i < n; i += 1)
		{
			int maxdiff = 0;
			for ( j = 0; j < m; j += 1)
			{
				scanf("%d",&c[i][j]);
				maxdiff = max(maxdiff,b[i][j]-c[i][j]-b[i][a[i]]);
			}
			v.pb(mp(maxdiff,i));
		}
		int done[1003] = {0};
		sort(v.begin(),v.end(),greater<pi >());
		for(i = 0;i < k  && i<n;i++)
		{
			if(v[i].first>0)
			{
				sum+=v[i].first;
				//done[v[i].second] = 1;
			}
		}
//		for(i = 0;i < n;i++)
//		{
//			if(done[i]==0)
//			{
//				sum+=b[i][a[i]];
//			}
//		}
		cout<<sum<<endl;
	}
	return 0;
}
