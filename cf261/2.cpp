#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

#define INF 100000000
#define LLINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef unsigned int uint;
typedef unsigned long long int ulli;
typedef pair<int,int> pairint;

int main()
{
	lli n;
	cin>>n;
	int i;
	int a[300000];
	for(i = 0;i < n;i++)
	{
		cin>>a[i];
	}
	lli c = 0,d = 0;
	sort(a,a+n);
	int m = a[n-1]-a[0];
	i = 0;
	while(i<n && a[i] == a[0])
	{
		i++;
		c++;
	}
	i = n-1;
	while(i>=0 && a[i] == a[n-1])
	{
		i--;
		d++;
	}
	lli ans;
	if(a[0] == a[n-1])
	{
		ans = (n*(n-1))/2;
		cout<<0<<" "<<ans;
		return 0;
	}
	else
	{
		ans = c*d;
		cout<<m<<" "<<ans;
	}
	return 0;
}
