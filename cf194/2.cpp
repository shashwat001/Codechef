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
	pi a[8];
	int i,x,y;
	for(i = 0;i < 8;i++)
	{
		scanf("%d %d",&x,&y);
		a[i] = make_pair(x,y);
	}
	sort(a,a+8);
	if(!(a[0].first == a[1].first && a[1].first == a[2].first))
	{
		printf("ugly");
		return 0;
	}
	if(!(a[5].first == a[6].first && a[6].first == a[7].first))
	{
		printf("ugly");
		return 0;
	}
	if(!(a[3].first == a[4].first))
	{
		printf("ugly");
		return 0;
	}
	if(!(a[0].second == a[3].second && a[3].second == a[5].second))
	{
		printf("ugly");
		return 0;
	}
	if(!(a[2].second == a[4].second && a[4].second == a[7].second))
	{
		printf("ugly");
		return 0;
	}
	if(!(a[1].second == a[6].second))
	{
		printf("ugly");
		return 0;
	}
	
	if(!(a[0].second < a[1].second && a[1].second < a[2].second))
	{
		printf("ugly");
		return 0;
	}
	if(!(a[5].second < a[6].second && a[6].second < a[7].second))
	{
		printf("ugly");
		return 0;
	}
		if(!(a[0].first < a[3].first && a[3].first < a[5].first))
	{
		printf("ugly");
		return 0;
	}
	if(!(a[2].first < a[4].first && a[4].first < a[7].first))
	{
		printf("ugly");
		return 0;
	}
		if(!(a[1].first < a[6].first))
	{
		printf("ugly");
		return 0;
	}
		if(!(a[3].second < a[4].second))
	{
		printf("ugly");
		return 0;
	}
	printf("respectable");
	
	
	return 0;
}
