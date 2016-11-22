//shashwat001

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef pair<int,int> pi;
int a[1000007];
bool comp(pi a,pi b)
{
	return a.second < b.second;
}
int main ()
{
	int v,x,i,j;
	pi p[10];
	scanf("%d",&v);
	for(i = 0;i < 9;i++)
	{
		scanf("%d",&x);
		p[i] = mp(x,i+1);
	}
	sort(p,p+9);
	if(v<p[0].first)
	{
		printf("-1");
		return 0;
	}
	int maxd = v/p[0].first;
	int rem = v%p[0].first;
	for(i = maxd;i>0;i--)
	{
		int amt = p[0].first+rem;
		int curnum = p[0].second;
		int curidx = 0;
		for(j = 1;j <= 8;j++)
		{			
			if(p[j].second>curnum)
			{
				int diff = amt-p[j].first;
				if(diff >= 0)
				{
					curnum = p[j].second;
					curidx = j;
				}			
			}
		}
		a[i] = curnum;
		rem = amt-p[curidx].first;
	}
	for(i = maxd;i>0;i--)
	printf("%d",a[i]);
	return 0;
}
