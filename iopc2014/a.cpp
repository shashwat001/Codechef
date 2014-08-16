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
	int s[100002],a[100004],i,t;
	s[0] = 0;
	a[0] = 0;
	for(i = 1;i <= 100000;i++)
	{
		if(i%2==1)
		{
			a[i] = 0;
		}
		else
		{
			a[i] = a[i/2]+1;
			
		}
		s[i] = s[i-1]+a[i];
	}

	cin>>t;
	while(t--)
	{
		int n;
		lli b;
		cin>>n>>b;
		int q = 0;
		for(i = 1;i <= n;i++)
		{
			q = (q*n)%2;
		}
	}
	return 0;
}
