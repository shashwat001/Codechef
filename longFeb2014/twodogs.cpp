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

vector<int> v[1000001];
int main ()
{
	int n,k,i,a;
	cin>>n>>k;
	int minm;
	for(i = 1;i <= n;i++)
	{
		cin>>a;
		
		if(v[a].size()>0)
		{
			minm = v[a][0];
			minm = min(minm,i);
			minm = min(minm,n+1-i);
				
			v[a][0] = minm;
		}
		else
		{
			minm = min(n+1-i,i);
			v[a].pb(minm);
		}
	}
	 minm = INF;
	
	vector<int>::iterator it1l,it2l,it1r,it2r;
	for (unsigned int i = 1; i < 1000001; i += 1)
	{
		if(i>=k)
			break;
		if(i!=(k-i)  && v[i].size()>0 && v[k-i].size()>0)
		{
		
			minm = min(minm,max(v[i][0],v[k-i][0]));
//			it1l = v[i].begin();
//			it2l = v[k-i].begin();
//			it1r = v[i].end();
//			it1r--;
//			it2r = v[k-i].end();
//			it2r--;
//			if(!(*it1l==*it2l))
//			{
//				minm = min(minm,max(*it1l,*it2l));
//			}
//			if(!(*it1l==*it2r))
//			{
//				minm = min(minm,max(*it1l,n-*it2r+1));
//			}
//			if(!(*it1r==*it2r))
//			{
//				minm = min(minm,max(n+1-*it1r,n-*it2r+1));
//			}
//			if(!(*it1r==*it2l))
//			{
//				minm = min(minm,max(n+1-*it1r,*it2l));
//			}
		}
		
	}
	
	if(minm==INF)
		cout<<-1;
	else
		cout<<minm;
	return 0;
}
