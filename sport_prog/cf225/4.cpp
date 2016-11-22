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


set<pi > ndonex,donex;
set<pi >::iterator it;

bool get(int i,int j)
{
	if(!inbound(i,j))
		return false;
	if(ndonex.find(i,j)!=ndonex.end())
	{
		return false;
	}
	if(donex.find(i,j)!=donex.end())
		return true;
	it = ndonex.lower_bound(mp(i,j));
	it--;
	bool right = false,down = false;
	down = get(it->first+1,it->second);
	right = get(it->first,it->second+1);
	bool res1 = right | down;
	if(res1 == true)
	{
		donex.insert(i,j);
		doney.insert(j,i);
	}
	else
	{
		ndonex.insert(i,j);
		ndoney.insert(j,i);
	}
	return res;
}


int main ()
{
	cin>>n>>m;
	for(i = 1;i <= m;i++)
	{
		cin>>a>>b;
		ndonex.insert(mp(a,b));
		ndoney.insert(mp(b,a));
	}
	donex.insert(mp(1,1));
	doney.insert(mp(1,1));
	if(get(n,n)==true)
	{
		cout<<2*(n-1)<<endl;
	}
	else
		cout<<-1<<endl;
	return 0;
}
