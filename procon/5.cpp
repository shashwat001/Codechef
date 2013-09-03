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
	int t,i,j,l,r;
	scanf("%d",&t);
	int p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
	int k = 16;
	while(t--)
	{
		scanf("%d",&l);
		scanf("%d",&r);
		int cnt = 0;
		for(i = l;i <= r;i++)
		{
			j = i;
			int sum = 0;
			while(j>0)
			{
			sum+=(j%10);
			j = j/10;
			}
			for(j = 0; j < k;j++)
			{
				if(sum==p[j])
				{
					break;
				}
				
			}
			if(j!=k)
				cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
