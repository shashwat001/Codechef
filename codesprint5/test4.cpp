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

int dimensions,a[100],gcdval,n,sum;

int gcd(int a,int b)
{
	return b>0?gcd(b,a%b):a;
}

void dfs(int dim)
{
	int i;
	if(dim==dimensions)
	{
		int gcdval = a[0];
		for(i = 1;i < dimensions;i++)
		{
			gcdval = gcd(gcdval,a[i]);
		}
		sum += gcdval;
		return;
	}
	for(i = 1;i <= n;i++)
	{
		a[dim] = i;
		dfs(dim+1);
	}
}

int main ()
{
	sum = 0;
	cin>>n>>dimensions;
	dfs(0);
	cout<<sum<<endl;
	
	return 0;
}
