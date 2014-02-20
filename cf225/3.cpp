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
	int i,n,k;
	vector<int> left,right;
	vector<int>::iterator it;
	lli countc = 0;
	cin>>n;
	for(i = 0;i < n;i++)
	{
		cin>>k;
		if(k==0)
			left.pb(i);
		else
			right.pb(i);
	}
	for(i = 0;i < left.size();i++)
	{
		it = lower_bound(right.begin(),right.end(),left[i]);
		countc += (lli)(it-right.begin());
	}
	cout<<countc;
	return 0;
}
