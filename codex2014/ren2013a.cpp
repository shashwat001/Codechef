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

int getmax(int a)
{
	int maxm = 0;
	int b = a;
	while(a>0)
	{
		maxm = max(maxm,a%10);
		a = a/10;
	}
	maxm++;
	int k = 1;
	int sum = 0;
	while(b>0)
	{
		sum += k*(b%10);
		k = maxm*k;
		b = b/10;
		
	}
	return sum;
}

int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		int ca = getmax(a);
		int cb = getmax(b);
		cout<<ca+cb<<endl;
	}
	return 0;
}
