#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

#define mod 1000000007ULL
#define inf 10000000

lli c[2][10000005];
lli a[10000005];

int main()
{
	int t,n,i;
	lli invi;
	invi = (mod+1)/2;
	a[3] = 1;
	a[4] = 13;
	a[5] = 205;



	c[0][5] = 10;
	c[1][5] = (15*invi) % mod;

	for (i = 6; i <= inf; i++)
	{
		c[0][i] = (c[0][i - 1] + i - 1)%mod;

		c[1][i] = (c[1][i - 1] * i) % mod;
		c[1][i] = (c[1][i] * (i - 2)) % mod;
		c[1][i] = (c[1][i] * invi) % mod;

		a[i] = (c[0][i] * a[i-1] + c[1][i] * (3*i-5)) % mod;
	}

	scanf("%d", &t);

	while(t--)
	{
		scanf("%d", &n);

		printf("%lld\n",a[n]);
	}
	return 0;
}
