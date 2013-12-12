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
#define s1(t) scanf("%d",&t)
#define s2(a,b) scanf("%d %d",&a,&b)
#define sa(a,n) for(i = 0;i < (n);i++) scanf("%d",&a[i])
#define pf(t) printf("%d\n",t)


typedef long long int lli;
typedef pair<int,int> pi;

int main ()
{
	int t,a[100006],n,i,j,k,l;
	s2(n,k);
	sa(a,n);
	sort(a,a+n);
	int diff = INF;
	for(i = 0;i <= n-k;i++)
	{
		diff = min(diff,a[i+k-1]-a[i]);
	}
	pf(diff);
	return 0;
}
