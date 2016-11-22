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

int a[100];
int getmin(int j,int l)
{
	int minm = INF;
	for (unsigned int i = j; i < l+1; i += 1)
	{
		minm = min(minm,a[i]);
	}
	return minm;
}

int main ()
{
	int i,n,q,k;
	cin>>n;
	for(i = 0;i < n;i++)
	{
		cin>>a[i];
	}
	cin>>q;
	for(i = 0;i < q;i++)
	{
		cin>>k;
		int cnt = 0;
		for (unsigned int j = 0; j < n; j += 1)
		{
			for (unsigned int l = j; l < n; l += 1)
			{
				int minm = getmin(j,l);
				if(minm==k)
					cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
