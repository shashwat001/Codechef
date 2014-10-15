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
	int t,n,i,j,k,l,a[100005];
	set<int> s;
	set<int>::iterator it;
	cin>>n;
	for(i = 0;i < n;i++)
	{
		cin>>a[i];
	}
	if(n==1||n==2)
	{
		cout<<"no";
		return 0;
	}
	s.insert(a[0]);
	s.insert(a[1]);
	int curx = a[1];
	for(i = 2;i < n; i++)
	{
		if(a[i] < curx)
		{
			it = s.lower_bound(curx);
			if(it!=s.begin())
			{
				it--;
			}
			if(*it == curx || *it < a[i])
			{ 
				s.insert(curx);
				curx = a[i];
			}
			else
			{
				printf("yes");
				return 0;
			}
		}
		else
		{
			it = s.upper_bound(curx);
			if(it == s.end() || *it > a[i])
			{
				s.insert(curx);
				curx = a[i];
			}
			else
			{
				printf("yes");
				return 0;
			}
		}
	}
	printf("no");
	return 0;
}
