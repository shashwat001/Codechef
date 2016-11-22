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

typedef struct
{
	int a,b,idx;
} order;

order mo(int a,int b,int idx)
{
	order o;
	o.a = a;
	o.b = b;
	o.idx = idx;
	return o;
}

bool comp(order left,order right)
{
	if(left.b<right.b)
		return true;
	if(left.b==right.b)
	{
		if(left.a>right.b)
			return true;
	}
	return false;
}

class compa
{
	public:
	bool operator()(order left,order right)
	{
		if(left.a>right.a)
			return true;
		if(left.a==right.a)
		{
			if(left.b>right.b)
				return true;
		}
		return false;
	}
};



int main ()
{
	order a[200000];
	int n,p,k,i,x,y;
	scanf("%d %d %d",&n,&p,&k);
	for(i = 0;i < n;i++)
	{
		scanf("%d %d",&x,&y);
		a[i] = mo(x,y,i);
	}
	sort(a,a+n,comp);
	priority_queue<order ,vector<order>,compa> rk;
	for(i = 0;i<k;i++)
	{
		rk.push(a[n-1-i]);
	}
	int curi = n-k-1;
	for(i = n-k-1;i>=p-k;i--)
	{
		order temp = rk.top();
		if(a[i].a>temp.a)
		{
			rk.pop();
			rk.push(a[i]);
			curi = i;
		}
	}
	for(i = curi-(p-k);i<curi;i++)
	{
		printf("%d ",a[i].idx+1);
	}
	
	while(!rk.empty())
	{
		order temp = rk.top();
		rk.pop();
		printf("%d ",temp.idx+1);
	}
	
	return 0;
}
