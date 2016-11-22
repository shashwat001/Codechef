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
	vector<lli> f;
	vector<lli>::iterator it;
	int i,t;
	lli n;
	f.pb(0);
	f.pb(1);
	for(i = 2;f[i-1]<=10000000000;i++)
	{
		f.push_back(f[i-1]+f[i-2]);
	}
	cin>>t;
	while(t--)
	{
		cin>>n;
		it = lower_bound(f.begin(),f.end(),n);
		if(*it==n)
		{
			cout<<"IsFibo\n";
		}
		else
		{
			cout<<"IsNotFibo\n";
		}
	}
	return 0;
}
