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
#include <cmath>

using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef pair<int,int> pi;

int main ()
{
	int t;
	while(t--)
	{
		lli n,k,m;
		cin>>n>>k>>m;
		lli d = m/n;
		a = n;
		for(l = 0;l <= 64;l++)
		{
			if(a>m)
			{
				break;
			} 
			a = a*k;
		}
	}
	return 0;
}
