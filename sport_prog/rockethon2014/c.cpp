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
	pi p[200003];
	int n,k;
	cin>>n>>k;
	for(i = 1;i <= n;i++)
	{
		cin>>p[i].first>>p[i].second;
	}
	sort(p+1,p+n+1,greater<pi >());
	int points = p[k].first;
	return 0;
}
