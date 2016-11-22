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
int a[1000][1000]={{0}},c[1000][1000] = {{0}};
int main ()
{
	int n,m,rc,i,t;
	cin>>t;
	while(t--)
	{
		
	cin>>n>>m>>rc;
	for(i = 0;i <= 600;i++)
	{
		for (unsigned int j = 0; j <= 600; j += 1)
		{
			a[i][j] = c[i][j] = 0;
	}}
	for(i = 1;i <= n;i++)
	{
		for (unsigned int j = 1; j <= m; j += 1)
		{
			cin>>c[i][j];
		}
	}
	for(i = 1;i <=n;i++)
	{
		for (unsigned int j = 1; j <= m; j += 1)
		{
			int sum1 = -c[i][j] + a[i-1][j-1];
			int sum2 = -c[i][j] + a[i-1][j+1];
			int maxsum = max(sum1,sum2);
			if(maxsum <= 0)
			{
				if(i!=n)
					a[i][j] = -INF;
				else
					a[i][j] = maxsum;
			}
			else
				a[i][j] = maxsum;
			if(a[i][j]>100)
				a[i][j] = 100;
		}
	}
	int maxm = -INF;
	for(i = 1;i <= n;i++)
	{
		maxm = max(a[n][i],maxm);
	}
	if(maxm < -INF/2)
		cout<<-1;
	else if(maxm < 0)
		cout<<0;
	else
		cout<<maxm;
	cout<<endl;
	}
	return 0;
}
