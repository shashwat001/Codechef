#include <bits/stdc++.h>

using namespace::std;

typedef long long int lli;

long long int mod = 1000000007ULL;
long long int LIMIT = 2000000;
lli fact[2000005];

lli modexpo(lli a,lli y)
{
	lli ret = 1;
	while(y > 0)
	{
		if(y&1)
		{
			ret = (ret*a)%mod;
		}
		y >>= 1;
		a = (a*a)%mod;
	}
	return ret;
}

int main()
{

	fact[1] = 1;
	for (long long int i = 2; i <= LIMIT; i++)
		fact[i] = (i * fact[i - 1]) % mod;

	int t;
	scanf("%d", &t);

	while(t--)
	{
		lli n,m;
		scanf("%lld %lld", &n,&m);


		long long int ans = fact[m-n];
		ans = (ans * modexpo(m - n, (2 * n - m)/2)) % mod;
		ans = (ans * modexpo(m - n + 1, (2 * n - m + 1) / 2)) % mod;

		printf("%lld\n", ans);
	}
	return 0;
}
