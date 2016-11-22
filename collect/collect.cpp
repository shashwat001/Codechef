#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define MOD 3046201

lli m[400005],n,aa[100005];
bool valid[100005];

lli init(lli b,lli e,lli node)
{
	if(b==e)
	{
		return m[node] = aa[b];
	}
	lli mid = (b+e)/2;
	return m[node] = init(b,mid,2*node) + init(mid+1,e,2*node+1);
}

lli query(lli b,lli e,lli i,lli j,lli node)
{
	if(j<b || i>e)
	{
		return 0;
	}
	if(i<=b && j>=e)
	{	
		return m[node];
	}
	lli mid = (b+e)/2;
	return query(b,mid,i,j,2*node) + query(mid+1,e,i,j,2*node+1);
}

lli update(lli b,lli e,lli idx,lli node,lli val)
{
	if(idx<b || idx>e)
	{
		return m[node];
	}
	if(idx<=b && idx>=e)
	{
		m[node] = val;
		return val;
	}
	lli mid = (b+e)/2;
	return m[node] = update(b,mid,idx,2*node,val) + update(mid+1,e,idx,2*node+1,val);
}
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



lli l;
lli a[3000007];

int main()
{
	lli p,x,i,q,tsum,k,nn,r;
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
		scanf("%lld",&aa[i]);
	}
	init(0,n-1,1);
	memset(valid,false,sizeof(valid));
	scanf("%lld",&q);
	for(i = 0;i < q;i++)
	{
		scanf("%s",s);
		switch(s[0])
		{
			case 'c':
				scanf("%lld %lld",&x,&p);
				update(0,n-1,x-1,1,p);
				break;
				
			case 'q':
				scanf("%lld %lld",&x,&p);
				nn = p-x+1;
				tsum = query(0,n-1,x-1,p-1,1);
				if(tsum == 0)
				{
					printf("0\n");
					continue;
				}
				k = tsum/nn;
				r = tsum%nn;
				num = ((lli)a[tsum] * (lli)a[nn])%MOD;
				den = ((lli)a[r]*(lli)a[nn-r])%MOD;
				den = (den*modexpo(a[(k+1)],r,MOD))%MOD;
				den = (den*modexpo(a[k],nn-r,MOD))%MOD;
				l = (num *  modmulinverse(den,MOD))%MOD;
				printf("%lld\n",l);
				break;
		}
	}
	return 0;
	
}

