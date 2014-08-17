#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

#define INF 100000000
#define LLINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef unsigned int uint;
typedef unsigned long long int ulli;
typedef pair<int,int> pairint;

int main()
{
	lli n,k,d;
	cin>>n>>k>>d;
	int i,j;
	if(k == 1)
	{
		if(n==1)
			cout<<"1";
		else
			cout<<"-1";
		return 0;
	}
	lli p = 0;
	lli pk = k;
	while(n>pk)
	{
		p++;
		pk = pk*k;
	}
	if(p>d)
	{
		cout<<-1;
		return 0;
	}
	lli cap = pk/k;
	lli a[pk];
	lli ki = 1;
	for(j = 0;j < k;j++)
	{
		lli f = j*cap;
		for(l = 0;l < cap;l++)
		{
			a[f] = j;
			f++;
		}
		
	}
	vector<lli> v[k];
	for(i = 0;i < pk;i++)
	{
		v[a[pk]].pb(pk);
	}
	int cnt = 0;
	do
	{
		for(i = 0;i < k;i++)
		{
			for(j = 0;j < v[i].size();j++)
			{
				a[v[i][j]] = i;
			}
		}
		for(i = 0;i < n;i++)
		{
			cout<<a[i]+1<<" ";
		}
		vector<lli> temp[k];
		for(i = 0;i < k;i++)
		{
			for(j = i;j < pk;j+=k)
			{
				lli r = j/k;
				lli c = j%k;
				temp[i].pb(v[r][c]);
			}
		}
		for(i = 0;i < k;i++)
		{
			v[i] = temp[i];
		}
		cout<<"\n";
		cnt++;
	}
	while(cnt < p);
	for(i = cnt;i < d;i++)
	{
		for(i = 0;i < n;i++)
		{
			cout<<"1 ";
		}
	}
	
	
	
	
	return 0;
}
