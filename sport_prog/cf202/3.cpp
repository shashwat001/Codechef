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

typedef long long lli;
typedef pair<int,int> pi;

int main ()
{
	int x,i,n;
	lli sumc = 0;
	cin>>n;
	int maxval = -1;
	for(i = 0;i < n;i++)
	{
		cin>>x;
		maxval = max(maxval,x);
		sumc+=(lli)x;
	}
	int rem = sumc % (n-1);
	int res;
	if(rem==0)
		res = sumc/(n-1);
	else
		res = (sumc+n-1-rem)/(n-1);
	if(maxval > res)
		cout<<maxval;
	else
		cout<<res;
	return 0;
}
