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
typedef pair<float,float> pf;

float findintersectinglines(pf pts[],int n)
{
	int i,j,k;
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			for(k = 0;k < n;k++)
			{
				
			}
		}
	}
}

int main ()
{
	int i,n;
	pair<float,float> pts[106];
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%f %f",&pts[i].first,&pts[i].second);
	}
	float sadness1 = findintersectinglines(pts,n);
	return 0;
}
