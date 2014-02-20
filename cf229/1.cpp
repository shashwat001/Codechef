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
	int n,a,b,i;
	cin>>n;
	vector<int> h,v;
	for(i = 0;i < n;i++)
	{
		cin>>a>>b;
		h.pb(a);
		v.pb(b);
	}
	sort(h.begin(),h.end());
	sort(v.begin(),v.end());
	
	int hl = (int)(unique(h.begin(),h.end())-h.begin());
	int vl = (int)(unique(v.begin(),v.end())-v.begin());
	cout<<min(hl,vl);
	
	return 0;
}
