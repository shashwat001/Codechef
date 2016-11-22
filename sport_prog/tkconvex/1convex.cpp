#include <bits/stdc++.h>

using namespace std;
typedef long long lli;

int main()
{
	lli n,k,i,s,b1,b2,j,z,zz;
	scanf("%lld %lld",&n,&k);
	pair<lli,lli> *a,*temp,*b;
	a = (pair<lli,lli> *)malloc((n+5)*sizeof(pair<lli,lli>));
	b = (pair<lli,lli> *)malloc((n+5)*sizeof(pair<lli,lli>));
	temp = a;
	for(i = 1;i <= n;i++)
	{
		scanf("%lld",&s);
		a[i] = make_pair(s,i);	
	}
	sort(a+1,a+n+1);
	s = 0;
	for(i = 1;i < k;i++)
	{
		s += a[i].first;
	}
	
	i = k;
	b1 = 0;
	while(i <= n)
	{
		if(s-a[i].first > 0)
		{
			b1 = i-k+1;
			break;
		}
		s = s+a[i].first-a[i+1-k].first;
		i++;
	}
	if(i > n-k+b1-1)
		printf("No\n");
	else
	{
		j = i;
		for(z = 1;z < b1;z++)
		{
			b[z] = a[z];
		}
		for(zz = i+1;zz <= n;zz++)
		{
			b[z] = a[zz];
			z++;
		}
		z--;
		n = z;
		s = 0;
		for(i = 1;i < k;i++)
		{
			s += b[i].first;
		}
	
		i = k;
		while(i <= n)
		{
			if(s-b[i].first > 0)
			{
				b2 = i-k+1;
				break;
			}
			s = s+b[i].first-b[i+1-k].first;
			i++;
		}
		if(i > n)
			printf("No\n");
		else
		{
			printf("Yes\n");
			for(i = 0;i < k;i++)
			{
				printf("%lld ",temp[b1+i].second);
			}
			for(i = 0;i < k;i++)
			{
				printf("%lld ",b[b2+i].second);
			}
		}
	}
	return 0;
}
