#include <bits/stdc++.h>

using namespace std;
#define sf(n) scanf("%d",&n)
#define pf(n) printf("%d\n",n)


int main()
{
	int a[1001] = {0},b[1001] = {0}	,i,j,n,c,p,q,d[1001] = {0};
	sf(n);
	pair<int,int> pp[1001];
	for(i = 0;i < n;i++)
	{
		sf(p);
		sf(q);
		d[p]++;
		pp[i].first = p;
		pp[i].second = q;
	
	}
	for(i = 0;i < n;i++)
	{
		if(pp[i].second != pp[i].first)
		{
			if(a[pp[i].second]==0)
			{
				c+=d[pp[i].second];
				a[pp[i].second] = 1;
			}
		}
		else
		{
			if(a[pp[i].first] == 0)
			{
				c+=d[pp[i].second]-1;
				a[pp[i].second] = 2;
			}
			else
			{
			}
			
		}
	}
	pf(c);
	return 0;
}
