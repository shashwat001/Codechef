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

lli findgcd(lli a,lli b)
{
	lli r;
	while(b>0)
	{
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}


int main ()
{
	int i,k,t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int k = sqrt(n);
		lli sumc = 0;
		for(i = 1;i <= k;i++)
		{
			sumc+=(lli)(n/i);
		}
		sumc = 2*sumc - k*k;
		lli maxval = ((lli)n*(lli)(n));
		lli gcd = findgcd(maxval,sumc);
		printf("%lld/%lld\n",sumc/gcd,maxval/gcd);
	}
	return 0;
}
