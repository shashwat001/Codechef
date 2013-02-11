#include <stdio.h>
#define MOD 1000000007


long long modmulinverse(long long a,long long m)
{
    long long x = 0,y = 1,u = 1,v = 0; 
    long long e = m,f = a;
    long long c,d,q,r;
    while(f != 1)
    {
        q = e/f;
        r = e%f;
        c = x-q*u;
        d = y-q*v;
        x = u;
        y = v;
        u = c;
        v = d;
        e = f;
        f = r;
    } 
    u = (u+m)%m;
    return u;
}
int main()
{
	long long a[1001],b[1001],t,n,k,i;
	a[0] = 1;
	for(i = 1;i <= 1000;i++)
	{
		a[i] = (a[i-1]<<1)%MOD;
	}
	b[1] = 1;
	for(i = 2;i <= 500;i++)
	{
		b[i] = (((b[i-1]*2*(2*i-1))%MOD)*modmulinverse(i,MOD))%MOD;
	}
	
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i = 0;i < n;i++)
		{
			scanf("%lld",&k);
		}
		if(n&1)
		{
			printf("%lld\n",a[n-1]);
		}
		else
		{
			printf("%lld\n",(a[n-1]-b[n/2]+MOD)%MOD);
		}
	}
	return 0;
}
