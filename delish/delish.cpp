#include <bits/stdc++.h>
using namespace std;

long long int bmaxleft[10005],bminleft[10005],bmaxright[10005],bminright[10005];
void findmaxsum(int a[],int n,long long int b[])
{
	int i;
	long long int maxs = 0;
	b[0] = a[0];
	maxs = a[0];
	for(i = 1;i < n;i++)
	{
		
		b[i] = b[i-1];
		if(maxs>0)
		{
			maxs+=a[i];
		}
		else
		{
			maxs = a[i];
		}
		if(b[i] < maxs)
			b[i] = maxs;		
	}
}


void findminsum(int a[],int n,long long int b[])
{
	int i;
	long long int	mins =0;
	b[0] = a[0];
	mins = a[0];
	for(i = 1;i < n;i++)
	{
		
		b[i] = b[i-1];
		if(mins<0)
		{
			mins+=a[i];
		}
		else
		{
			mins = a[i];
		}
		if(b[i] > mins)
			b[i] = mins;		
	}
	
}
void reversearr(int a[],int n)
{
	int i = 0;	
	while(i <= (n-i-1))
	{
		int t = a[i];
		a[i] = a[n-1-i];
		a[n-1-i] = t;
		i++;
	}
	return;
}

void reversearr(long long int a[],int n)
{
	int i = 0;	
	while(i <= (n-i-1))
	{
		long long int t = a[i];
		a[i] = a[n-1-i];
		a[n-1-i] = t;
		i++;
	}
	return;
}


int main()
{

	int i,n,a[10005];
	long long int maxs;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
		}
		findmaxsum(a,n,bmaxleft);
		findminsum(a,n,bminleft);
		reversearr(a,n);
		findminsum(a,n,bminright);
		findmaxsum(a,n,bmaxright);
		reversearr(bminright,n);
		reversearr(bmaxright,n);
		reversearr(a,n);
		maxs = 0;
		for(i = 1;i < n;i++)		
		{
			long long int diff1 = abs(bmaxright[i] - bminleft[i-1]);
			long long int diff2 = abs(bmaxleft[i-1] - bminright[i]);
			maxs = max(maxs,max(diff1,diff2));
		}
		printf("%lld\n",maxs);
	}
	return 0;
}
