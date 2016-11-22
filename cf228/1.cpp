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
	int n,a[200],i;
	cin>>n;
	int count[200] = {0};
	for(i = 0;i < n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int maxm = -1;
	int h[1000] = {0};
	int tbox = 0,minidx;
	for(i = 0;i < n;i++)
	{
		int minm = 10000;
		for (unsigned int j = 0; j < i; j += 1)
		{
			if(a[j]!=INF)
			{
				if(h[j] < a[i])
				{
					if(h[j]+1 < minm)
					{
						minm = h[j]+1;
						minidx = j;
					}
				}
			}
			
		}
		if(minm > a[i])
		{
			tbox++;
			h[i] = 0;
		}
		else
		{
			h[i] = minm;
			a[minidx] = INF;
		}
	}
	cout<<tbox;
	
	return 0;
}
