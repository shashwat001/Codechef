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
	while(scanf("%d %d",&n,&m) && !(n==0 && m==0))
	{
		vector<vector<pi > > minerals(n,vector<pi >(m));
		for(i = 0;i < n;i++)
		{
			for (j = 0; j < m; j += 1)
			{
				scanf("%d",&minerals[i][j].first);
			}
		}
		for(i = 0;i < n;i++)
		{
			for (j = 0; j < m; j += 1)
			{
				scanf("%d",&minerals[i][j].second);
			}
		}
		for(i = n-1;i >= 0;i--)
		{
			for(j = m-1;j >= 0;j--)
			{
				minerals[i][j].first += minerals[i][j+1].first;
			}
		}
	}
	return 0;
}
