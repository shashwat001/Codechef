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
	set<int> s;
	set<int>::iterator it;
	s.insert(0);
	for(i = 0;i < n;i++)
	{
		cin>>a>>b;
		set<int> t;
		for(it = s.begin();it!= s.end();it++)
		{
			t.insert(*it+a);
			t.insert(*it+b);
		}
		for(it = t.begin();it!= t.end();it++)
		{
			s.insert(*it);
		}
	}
	int maxv = 0;
	for(it = s.begin();it!= s.end();it++)
	{
		maxv = max(maxv,*it);
	}
	cout<<maxv<<endl;
	return 0;
}
