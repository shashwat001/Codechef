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
#define mod 1000000007

typedef long long int lli;
typedef pair<lli,lli> pi;

int main ()
{
	lli t,m,n,i,a;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		vector<pi > p;
		vector<pi >::iterator it;
		for(i = 0;i < m-1;i++)
		{
			cin>>a;
			p.pb(mp(a,0));
		}
		for(i = 0;i < n-1;i++)
		{
			cin>>a;
			p.pb(mp(a,1));
		}
		lli cost = 0;
		sort(p.begin(),p.end(),greater<pi >());
		lli cnth = 1;
		lli cntv = 1;
		for(it = p.begin();it != p.end();it++)
		{
			if(it->second == 1)
			{
				lli curcost = (it->first * cnth)%mod;
				cost = (cost + curcost)%mod;
				cntv++;
			}
			else
			{
				lli curcost = (it->first * cntv)%mod;
				cost = (cost + curcost)%mod;
				cnth++;
			}
		}
		cout<<cost<<endl;
	}
	return 0;
}
