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
typedef pair<lli,int> pi;
class comp
{
	public:
	bool operator()(const pi& lhs, const pi& rhs)
	{
		if(lhs.first < rhs.first)
			return true;
		if(lhs.first==rhs.first)
		{
			if(lhs.second>rhs.second)
				return true;
		}
		return false;
	}
};
lli c[1000000];

lli a[1000000];
int main ()
{
	int n,k,i;
	scanf("%d %d",&n,&k);
	for(i = 0;i < n;i++)
	{
		//scanf("%lld",&a[i]);
		cin>>a[i];
		
	}
	lli s = 0;
	for(i = 0;i < k;i++)
	{
		s+=(lli)a[i];
	}

	c[0] = s;
	for(i = 1;i<n-k+1;i++)
	{
		s+=(lli)a[i-1+k] - (lli)a[i-1];
		c[i] = s;
	}
	int cc = n-k+1;
	priority_queue<pi ,vector<pi >, comp> p;
	for(i = k;i < cc;i++)
	{
		p.push(mp(c[i],i));
	}
	lli maxm = 0;
	int maxi,maxf;
	for(i = 0;i < cc-k;i++)
	{
		pi val = p.top();
		if(val.second < i+k)
		{
			p.pop();
			i--;
			continue;
		}
		lli oval = val.first;
		lli sumd = oval+c[i];
		if(maxm<sumd)
		{
			maxm = sumd;
			maxi = i;
			maxf = val.second;
		}
	}
	printf("%d %d",maxi+1,maxf+1);
	return 0;
}
