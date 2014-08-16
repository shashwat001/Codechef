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

int dfs(int idx,int minm,int sum ,int count,pi b[],bool visited[])
{
	if(visited[idx])
	{
		int total = (sum-minm) + (count-1)*minm;
		return total;
	}
	visited[idx] = true;
	minm = min(minm,b[idx].first);
	sum += b[idx].first;
	count++;
	return dfs(b[idx].second,minm,sum,count,b,visited);
}

int main ()
{
	int t = 0;
	while(++t)
	{
		int n,i;
		pi a[1004],b[1004];
		bool visited[1004] = {false};
		cin>>n;
		if(n==0)
			return 0;
		for(i = 0;i < n;i++)
		{
			cin>>b[i].first;
			a[i] = mp(b[i].first,i);
		}
		sort(a,a+n);
		for(i = 0;i < n;i++)
		{
			b[a[i].second].second = i;
		}
		int total = 0;
		for(i = 0;i < n;i++)
		{
			if(!visited[i])
			{
				total += dfs(i/*idx*/    ,INF/*minm*/    ,0/*sum*/    ,0/*count*/    ,b,visited);
			}
		}
		cout<<"Case "<<t<<": "<<total<<endl<<endl;
	}
	return 0;
}
