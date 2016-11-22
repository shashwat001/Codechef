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
	int t,i,n,m,x,l,r,win[400000];
	set<int> s;
	set<int>::iterator it;
	scanf("%d %d",&n,&m);
	for(i = 0;i < n;i++)
	{
		s.insert(i+1);
	}
	for(i = 0;i < m;i++)
	{
		scanf("%d %d %d",&l,&r,&x);
		s.erase(x);
		it = s.lower_bound(l);
		while(it!= s.end() && *it <= r)
		{
				win[*it] = x;
				s.erase(*it);
				it = s.lower_bound(l);
		}
		s.insert(x);
	}
	win[x] = 0;
	for(i = 0;i < n;i++)
	{
		printf("%d ",win[i+1]);
	}
	return 0;
}
