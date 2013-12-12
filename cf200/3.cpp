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
	lli a,b,sum=0,r;
	cin>>a>>b;
	while(b!=0)
	{
		if(a<b)
		{
			swap(a,b);
			continue;
		}
		else
		{
			sum+=a/b;
			r = a%b;
			a = b;
			b = r;
		}
	}
	cout<<sum;
	return 0;
}
