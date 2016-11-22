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

lli gcd(lli a,lli b)
{
	while(b>0)
	{
		lli r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main ()
{
	lli t,n,x,y,a,b;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld %lld %lld",&a,&b,&x,&y);
		a = abs(a-x);
		b = abs(b-y);
		if(a<b)
		{
			lli t = a;
			a = b;
			 b = t;
		}
		lli f = gcd(a,b);
		a = a/f;
		b = b/f;
		lli res = a+b-1;
		res = res*f;
		printf("%lld\n",res);
	}
	return 0;
}
