#include <stdio.h>
#define MOD 1000000007

int main()
{
	long long a,b,c,aa,bb,cc,s;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		s = 1;
		scanf("%lld %lld %lld",&a,&b,&c);
	
	if(a<=b && a<=c)
	{
		aa = a;
		if(b<=c)
		{
			bb = b;
			cc = c;
		}
		else
		{
			bb = c;
			cc = b;
		}
	}
	else if(b<=a && b<=c)
	{
		aa = b;
		if(a<=c)
		{
			bb = a;
			cc = c;
		}
		else
		{
			bb = c;
			cc = a;
		}
	}
	else
	{
		aa = c;
		if(a<=b)
		{
			bb = a;
			cc = b;
		}
		else
		{
			bb = b;
			cc = a;
		}
	}
	aa = aa%MOD;
	bb = (bb-1)%MOD;
	if(cc==1)
		cc = 2;
	cc = (cc-2)%MOD;
	s = (aa*bb)%MOD;
	s = (s*cc)%MOD;
	printf("%lld\n",s);
}
		
}
