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
	int maxi = 0,maxj = 0,i,j,t;
	lli ncr[60][60],p[80],q[80],n;
//	for(i = 1;i < 60;i++)
//	{
//		ncr[i][0] = 1;
//		for(j = 1;j < i;j++)
//		{
//			ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
//			if(ncr[i][j]>1000000000000000000)
//			{
//				maxi = i;
//				maxj = j;
//				break;
//			}
//		}
//		if(maxi!=0)
//			break;
//		ncr[i][i] = 1;
//	}
	p[1] = 2;
	for(i = 2;i < 33;i++)
	{
		p[i] = (p[i-1]/i)*(4*i-2);

	}
	for(i = 1;i < 33;i++)
	{
		q[2*i] = p[i];
		q[2*i+1] = q[2*i]/(i+1)*(2*i+1);
	}
	q[1] = 1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i = 1;i < 65;i++)
		{
			if(q[i]>=n)
			{
				printf("%d\n",i);
				break;;
			}
		}
	}
	return 0;
}
