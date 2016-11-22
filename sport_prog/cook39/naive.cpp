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


lli a[35][100006];
int main ()
{
    lli t,n,i;
	scanf("%lld",&t);
	while(t--)
	{
        memset(a,0,sizeof(a));
		scanf("%lld",&n);
		for(i = 0;i < n;i++)
		{
			cin>>b[i];
		}
		for(i = 0;i < n;i++)
		{
			for(j = 0;j <=i;j++)
			{
				int xorval = 0;
				for(k = i;k <= j;k++)
				{
					xorval = xorval^b[k];
				}
			}
		}
		printf("%lld\n",output);
		
	}
	return 0;
}
