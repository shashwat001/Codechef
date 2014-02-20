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
	int n,i,a[100006],b;
	lli sum = 0;
	cin>>n;
	for(i = 0;i < n;i++)
	{
		cin>>a[i];
	}
	for(i = 0;i < n;i++)
	{
		cin>>b;
		if(a[i]*2 < b)
		{
			sum-=1;
			continue;
		}
		if(b==1)
		{
			sum-=1;
			continue;
		}
		if(b%2==0)
			sum+=(((lli)b*b)/4);
		else
			sum+=((lli)b/2*(b+1)/2);
	}
	cout<<sum;
	return 0;
}
