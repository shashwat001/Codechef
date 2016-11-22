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

int getval(int a,int b)
{
	while(b>0)
	{
		a+= (b%10)<<1;
		b=b/10;
	}
	return a;
}

bool xoro(int a,int b)
{
	int i;
	vector<int> aa,bb;
	while(a>0)
	{
		aa.pb(a%10);
		a = a/10;
	}
	while(b>0)
	{
		bb.pb(b%10);
		b = b/10;
	}
	for(i = 0;i < aa.size();i++)
	{
		for (unsigned int j = 0; j < bb.size(); j += 1)
		{
			if(aa[i]==bb[j])
				return false;
		}
	}
	return true;
}
	pi a[100][1025];
int main ()
{
	int t,n,b[1000],i,j,k,l;

	memset(a,0,sizeof(a));
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i = 0;i < n;i++)
		{
			cin>>b[i+1];
		}
		a[0][0] = mp(0,0);
		for(i = 1;i <= n;i++)
		{
			for (unsigned int j = 1; j < 1024; j += 1)
			{
				if(xoro(a[i-1][j].first,b[i]))
				{
					int newval = getval(a[i-1][j].first,b[i]);
					if(a[i-1][newval].first < a[i-1][j].first+b[i])
					{
						a[i][newval] = mp(a[i-1][j].first+b[i],a[i-1][j].second+1);
					}
				}
			}
		}
		int maxs = 0;
		for(i = 1;i<1024;i++)
		{
			maxs = max(maxs,a[n][i].first);
		}
		cout<<maxs;
	}
	return 0;
}
