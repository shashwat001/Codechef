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

int gcd(int a,int b)
{
	return b>0?gcd(b,a%b):a;
}

bool get(int a,int b)
{
	if(b==1)
		return 1;
	if(a<b)
		return get(b,a);
	if(a/b > 1)
	{
		return 1;
	}
	else
	{
		return 1-get(b,a%b); 
	}
}
int main ()
{
	int t,n,i,a,b;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		bool ans = false;
		for(i = 0;i < n;i++)
		{
			cin>>a>>b;
			int g = gcd(a,b);
			ans = ans^get(a/g,b/g);
		}
		if(ans==true)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}
