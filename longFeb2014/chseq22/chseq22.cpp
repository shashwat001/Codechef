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
#define mod 1000000007

typedef long long int lli;
typedef pair<int,int> pi;

int a[100004];
int val[1000003] = {0};
void update(int b,int e,int i,int j,int node)
{
	if(b>j || e<i)
	{
		return ;
	}
	if(b==e)
	{
		val[node]+=1;
		return;
		
	}
	if(i<=b && j>=e)
	{
		val[node]+=1;
		return ;
	}
	int mid = (b+e)/2;
	val[2*node] += val[node];
	val[2*node+1] += val[node];
	val[node] = 0;
	update(b,mid,i,j,2*node);
	update(mid+1,e,i,j,2*node+1);
	return ;
}

void finish(int b,int e,int node)
{
	if(b==e)
	{
		a[b] = val[node];
		return ;
	}
	int mid = (b+e)/2;
	val[2*node] += val[node];
	val[2*node+1] += val[node];
	val[node] = 0;
	finish(b,mid,2*node);
	finish(mid+1,e,2*node+1);
	return ;
}

int main ()
{
	int n,m,i,x,y;
	
	cin>>n>>m;
	for(i = 1;i <= m;i++)
	{
		cin>>x>>y;
		update(0,n-1,x-1,y-1,1);
	}
	finish(0,n-1,1);
	sort(a,a+n);
	int l = unique(a,a+n)-&a[0];
	//cout<<l<<endl;
	int out = 1;
	for(i = 0;i < l;i++)
	{
		out = (2*out)%mod;
	}
	cout<<out;
	return 0;
}
