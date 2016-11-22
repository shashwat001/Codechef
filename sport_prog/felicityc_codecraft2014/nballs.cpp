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
	int n,a,b,i;
	pi dp[100001];
	cin>>n;
	for(i = 0;i <= 100000;i++)
	{
		dp[i].first = 0;
		dp[i].second = 0;
	}
	for(i = 0;i < n;i++)
	{
		cin>>a>>b;
		dp[a].first++;
		dp[b].second++;
	}
	int half = (n+1)/2;
	int minm = INF;
	for(i = 0;i <= 100000;i++)
	{
		if(dp[i].first<half)
		{
			if(half-dp[i].first <= dp[i].second)
			{
				minm = min(minm,half-dp[i].first);
			}
		}
		else
		{
			minm = 0;
		}
	}
	if(minm == INF)
		cout<<"Impossible";
	else cout<<minm;
	return 0;
}
