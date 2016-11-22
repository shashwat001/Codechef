#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define MOD 3046201

lli tree[100005],n;
lli modmulinverse(lli a,lli m)
{
    lli x = 0,y = 1,u = 1,v = 0; 
    lli e = m,f = a;
    lli c,d,q,r;
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

lli modexpo(lli a,lli y,lli m)
{
	lli ret = 1;
	while(y > 0)
	{
		if(y&1)
		{
			ret = (ret*a)%MOD;
		}
		y >>= 1;
		a = (a*a)%MOD;
	}
	return (lli)ret;
}

lli read(lli idx)
{
	lli sumc = 0;
	while (idx > 0){
		sumc += tree[idx];
		idx -= (idx & -idx);
	}
	return sumc;
}


void update(lli idx ,lli val)
{
	while (idx <= n)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

lli l;
lli a[3000007];

int main()
{
	lli p,x,i,q,val[100005],diff,tsum,k,nn,r;
	char s[10];
	lli num,den;
	a[1] = 1;
	a[0] = 1;
	for(i = 2;i <= 3000000;i++)
	{
		l = ((lli)a[i-1]*(lli)i) % MOD;
		a[i] = (lli)l;
	}
	scanf("%lld",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%lld",&p);
		update(i+1,p);
		val[i+1] = p;
	}
	scanf("%lld",&q);
	for(i = 0;i < q;i++)
	{
		scanf("%s",s);
		switch(s[0])
		{
			case 'c':
				scanf("%lld %lld",&x,&p);
				diff = p-val[x];
				update(x,diff);
				val[x] = p;
				break;
				
			case 'q':
				scanf("%lld %lld",&x,&p);
				nn = p-x+1;
				if(x==1)
				{
					tsum = read(p);
				}
				else
				{
					tsum = read(p) - read(x-1);
				}
				if(tsum == 0)
				{
					printf("0\n");
					continue;
				}
				k = tsum/nn;
				r = tsum%nn;
				num = ((lli)a[tsum] * (lli)a[nn])%MOD;
				den = ((lli)a[r]*(lli)a[nn-r])%MOD;
				den = (den*modexpo((k+1),r,MOD))%MOD;
				den = (den*modexpo(k,nn-r,MOD))%MOD;
				l = (num *  modmulinverse(den,MOD))%MOD;
				printf("%lld\n",l);
				break;
		}
	}
	return 0;
	
}

