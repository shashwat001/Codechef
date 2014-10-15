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
#define MOD 1000000007
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef pair<int,int> pi;

inline lli modexp(lli a,int n)
{
	lli res = 1;
	while(n>0)
	{
		if(n&1)
		{
			res = (res*a)%MOD;
		}
		a = (a*a)%MOD;
		n>>=1;
	}
	return res;
}

int main ()
{
	int t,n;
	int k,m;
	lli q;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %lld %d",&n,&m,&q,&k);
		if(n==1 || (m-q)<=0)
			{printf("0\n");continue;}
			
		lli a = q+1;
		int 
		lli res = 1;
		while(n>0)
		{
			if(n&1)
			{
				res = (res*a)%MOD;
			}
			a = (a*a)%MOD;
			n>>=1;
		}
		lli res = (modexp(q+1,n)+modexp(q-1,n))%MOD;
		res = (res-modexp(q,n)+MOD)%MOD;
		res = (res-modexp(q,n)+MOD)%MOD;
		res = (res*(m-q))%MOD;
		
			printf("%lld\n",res);
	}
	return 0;
}
