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
	int i,n,x,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		vector<int> A(n),B(n);
		for(i = 0;i < n;i++)
		{
			scanf("%d",&x);
			if(x==1)
				x = INF;
			else if(x==2)
				x = 4;
			A[i] = x;
		}
		for(i = 0;i < n;i++)
		{
			scanf("%d",&x);
			if(x==1)
				x = INF;
			else if(x==2)
				x = 4;
			B[i] = x;
		}
		sort(A.begin(),A.end());
		lli cnt = 0;
		vector<int>::iterator it;
		for(i = 0;i < n;i++)
		{
			it = lower_bound(A.begin(),A.end(),B[i]);
			cnt+= (lli)(it - A.begin());
		}
		printf("%f\n",((float)cnt)/n);
	}
	return 0;
}
