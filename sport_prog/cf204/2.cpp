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
	vector<int> v[100001];
	vector<int> legal;
	int n;
	cin>>n;
	int i,j,x;
	for(i = 0;i < n;i++)
	{
		cin>>x;
		v[x].pb(i);
	}
	for(i = 1;i <= 100000;i++)
	{
		if(v[i].size()==0)
			continue;
		if(v[i].size()==1)
		{
			legal.pb(i);
			continue;
		}
		if(v[i].size()==2)
		{
			legal.pb(i);
			continue;
		}
		int diff = v[i][1]-v[i][0];
		for(j = 2;j<v[i].size();j++)
		{
			if((v[i][j]-v[i][j-1]) !=diff)
			{
				break;
			}
		}
		if(j==v[i].size())
		{
			legal.pb(i);
		}
	}
	cout<<legal.size()<<endl;
	for(i = 0;i < legal.size();i++)
	{
		if(v[legal[i]].size()==1)
		{
			cout<<legal[i]<<" "<<0<<endl;
			
		}
		else
		{
			cout<<legal[i]<<" "<<v[legal[i]][1]-v[legal[i]][0]<<endl;
		}
	}
	
	
	return 0;
}
