#include <bits/stdc++.h>

using namespace std;

typedef struct
{
	float x,y,first,second;
} pt;

bool comp(pt a,pt b)
{
	if(a.second < b.second)
		return true;
	if(a.second == b.second)
	{
		if(a.first < b.second)
			return false;
		else
			return true;
	}
	return false;
}
int main()
{
	int t,n,i;
	int f1,f2;
	pt a[4005];
	int pos[4005];
	int prev[4005];
	float b,ints;
	scanf("%d",&t);
	list<pt> ls;
	while(t--)
	{
		scanf("%d",&n);
		for(i = 0;i <n;i++)
		{
			scanf("%d %d",&f1,&f2);
			a[i].x = (float)f1;
			a[i].y = (float)f2;
			a[i].first = (float)f1 - 4*sqrt((float)f2);
			a[i].second = (float)f1 + 4*sqrt((float)f2);
		}
		sort(a,a+n,comp);

		for(i = 0;i < n-1;i++)
		{
			pos[i] = i+1;
			prev[i+1] = i;
		}
		float length = 0;
		b = a[n-1].second - a[n-1].x;
		length += (b*sqrt(b*b+64)/2 + 32* log((b+sqrt(b*b+64))) - 32*log(8))/8;
		for(i = n-2;i>=0;i--)
		{
			if(a[i].first < a[pos[i]].first)
			{
				if(a[i].second <= a[pos[i]].first)
				{
					//length += a[i].second - a[i].first;
					b = a[i].second - a[i].x;
					length += (b*sqrt(b*b+64)/2 + 32* log((b+sqrt(b*b+64))) - 32*log(8))/8;
					
					
					b = a[pos[i]].x - a[pos[i]].first;
					length += (b*sqrt(b*b+64)/2 + 32* log((b+sqrt(b*b+64))) - 32*log(8))/8;
					
				}
				else
				{
					//length += a[i].first - a[i+1].first;
					ints = ((a[pos[i]].y - a[i].y)/(a[pos[i]].x - a[i].x) + (a[pos[i]].x + a[i].x))/2;
					b = ints - a[i].x;
					length += (b*sqrt(b*b+64)/2 + 32* log((b+sqrt(b*b+64))) - 32*log(8))/8;
					
					b = a[pos[i]].x - ints;
					length += (b*sqrt(b*b+64)/2 + 32* log((b+sqrt(b*b+64))) - 32*log(8))/8;
					
				}
			}
			else
			{
				pos[i-1] = pos[i];
				prev[pos[i]] = i-1;
			}
			
		}

		float minm = 1000000000.0;
		int idx;
		for(i = 0;i < n;i++)
		{
			if(minm >= a[i].first)
			{
				minm = a[i].first;
				idx = i;
			}
		}
		if(i==n)
		{
			b = a[idx].x - a[idx].first;
			length += (b*sqrt(b*b+64)/2 + 32* log((b+sqrt(b*b+64))) - 32*log(8))/8;
		}
		printf("%0.2f\n",length);
	}
	return 0;
}
