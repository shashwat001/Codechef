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
	int i,n,m,j,k,a[100004]={0},x;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%d",&x);
		if(x==100)
		{
			if(a[50]>=1 && a[25]>=1)
			{
				a[50]--;
				a[25]--;
			}
			else if(a[25]>=3)
			{
				a[25]-=3;
			}
			else
			{
				printf("NO");
				return 0;
			}
			a[100]++;
		}
		else if(x==50)
		{
			if(a[25]>=1)
			{
				a[25]--;
			}
			else
			{
				printf("NO");
				return 0;
			}
			a[50]++;
		}
		else if(x==25)
		{
			a[25]++;
		}
	}
	printf("YES");
	return 0;
}
