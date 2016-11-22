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
	scanf("%d %d",&n,&z);
	for(i = 1;i <= z;i++)
	{
		scanf("%d",&a[i]);
	}
	a[0] = 0;
	a[z+1] = n+1;
	for(i = 1;i <= z+1;i++)
	{
		p.push(mp(a[i]-a[i-1]-1,mp(i-1,i)));
	}
	int cnt = 0;
	while(!p.empty())
	{
		pair<int,pi > u = p.top();
		if(!mark[u.second.first])
		{
			mark[u.second.first] = 1;
			tot+=u.first;
			cnt++;
		}
		else if(!mark[u.second.second])
		{
			mark[u.second.second] = 1;
			tot+=u.first;
			cnt++;			
		}
		else
		{
			p.pop();
		}
		
	}
	return 0;
}
