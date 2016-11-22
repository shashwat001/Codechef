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
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		vector<vector<lli> > a(n,vector<lli>(m));
		for(j = 0;j < n;j++)
		{
			a[j][0] = 1;
		}
		for(i = 1;i < m;i++)
		{
			a[0][i] = a[1][i-1];
			for(j = 1;j < n-1;j++)
			{
				a[j][i] = (a[j-1][i-1] + a[j+1][i-1])%MOD;				
			}
			a[n-1][i] = a[n-2][i-1];
		}
		lli sum = 0;
		for(j = 0;j < n;j++)
		{
			sum = (sum+a[j][m-1])%MOD;
		}	
	}
	return 0;
}
