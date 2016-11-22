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

list<int> a[100004];
list<int>::iterator it;
vector<int> v[100004];

void printval(int idx, int n, int sum)
{
	if(idx == n)
	{
		printf("%d\n",sum/2);
		return ;
	}
	sum += v[idx].size();
	printval(idx+1,n,sum);
	for(int i = 0;i < (int)v[idx].size();i++)
	{
		if(idx > v[idx][i])
		printf("%d %d\n",idx+1,v[idx][i]+1);
	}
}
	pi d[100004];
int main ()
{
	int n,maxd,i;

	cin>>n>>maxd;
	for(i = 0;i < n;i++)
	{
		int x;
		cin>>x;
		d[i] = mp(x,i);
	}
	sort(d,d+n);
	i = 1;
	a[0].pb(d[0].second);
	while(i < n)
	{
		int k = d[i].first;
		if(k < 1)
		{
			cout<<-1;
			return 0;
		}
		while(i < n && k==d[i].first)
		{
			if(a[k-1].size()==0)
			{
				cout<<-1;
				return 0;
			}
			
			int node = a[k-1].front();
			v[node].pb(d[i].second);
			v[d[i].second].pb(node);
			a[k].pb(d[i].second);
			if(v[node].size()==maxd)
			{
				a[k-1].pop_front();
			}

			i++;
		}
	}
	printval(0,n,0);
	return 0;
}
