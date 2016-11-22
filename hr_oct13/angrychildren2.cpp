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
#define LINF 9223372036854775807LL
#define mp make_pair
#define pb push_back
#define s1(t) scanf("%d",&t)
#define s2(a,b) scanf("%d %d",&a,&b)
#define sa(a,n) for(i = 0;i < (n);i++) scanf("%d",&a[i])
#define pf(t) printf("%d\n",t)


typedef long long int lli;
typedef pair<int,int> pi;

lli findsum(lli a[],lli begin,lli k)
{
	lli sum = 0;
	for(lli j = -k,p = begin;j <= k;j+=2,p++)
	{
		sum+=j*a[p];
	}
	return sum;
}

int main ()
{
	lli a[100006],n,i,k,b[100006];
	scanf("%lld %lld",&n,&k);
	for(i = 0;i < (n);i++) scanf("%lld",&a[i]);
	sort(a,a+n);
	b[0] = a[0];
	for(i = 1;i < n;i++)
	{
		b[i] = a[i]+b[i-1];
	}
	lli term = k-1;
	lli sum = findsum(a,0,term);
	assert(sum>=0);
	lli mindiff = sum;
	for(i = 1;i <= n-k;i++)
	{
		sum = sum - 2*(b[i+k-2]-b[i-1]) + term * a[i-1] + term*a[i+k-1];
		mindiff = min(sum,mindiff);
	}
	printf("%lld\n",mindiff);
	return 0;
}
