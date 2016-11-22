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

int main ()
{
	int i,a[3],c[4] = {0};
	scanf("%d %d %d",&a[0],&a[1],&a[2]);
	pi b[3];
	for(i = 0;i < 3;i++)
	{
		b[i] = mp(a[i],i+1);
	}
	sort(b,b+3);
	int diff = b[1].first - b[0].first;
	if((diff+b[2].first)%2!=0)
	{
		printf("Impossible");
		return 0;
	}
	int big = (b[2].first+diff)/2;
	int small = (b[2].first - diff)/2;
	if(small<=b[0].first && big <= b[1].first)
	{
		if(b[2].second == 1)
		{
			if(b[1].second==2)
			{
				c[1] = big;
				c[3] = small;
				c[2] = b[1].first - big;
			}
			else
			{
				c[1] = small;
				c[3] = big;
				c[2] = b[1].first - big;
			}
		}
		else if(b[2].second == 2)
		{
			if(b[1].second==1)
			{
				c[1] = big;
				c[2] = small;
				c[3] = b[1].first - big;
			}
			else
			{
				c[1] = small;
				c[2] = big;
				c[3] = b[1].first - big;
			}
		}
		else
		{
			if(b[1].second==2)
			{
				c[2] = big;
				c[3] = small;
				c[1] = b[1].first - big;
			}
			else
			{
				c[2] = small;
				c[3] = big;
				c[1] = b[1].first - big;
			}
		}
		printf("%d %d %d",c[1],c[2],c[3]);
	}
	else
	{
		printf("Impossible");
	}
	return 0;
}
