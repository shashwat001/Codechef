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
	lli a[100005],n,i,d,v[100004],c1;
	cin>>n;
	for(i = 0;i < n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	if(n==1)
	{
		cout<<"-1";
		return 0;
	}
	if(n==2)
	{
		d = a[1]-a[0];
		if((a[1]-a[0])%2==0)
		{
			if(d>0)
				cout<<"3\n"<<a[0]-d<<" "<<a[0]+d/2<<" "<<a[1]+d;
			else
				cout<<"1\n"<<a[0];
		}
		else
		{
			cout<<"2\n"<<a[0]-d<<" "<<a[1]+d;
		}
		return 0;
	}
	for(i = 1;i < n;i++)
	{
		v[i-1] = a[i]-a[i-1];
	}
	c1 = 0;
	for(i = 0;i < n-1;i++)
	{
		if(v[i]==v[0]) c1++;
	}
	if(c1==n-1)
	{
		if(v[0]==0)
		{
			cout<<"1\n"<<a[0];
		}
		else
		{
			cout<<"2\n";
			cout<<a[0]-v[0]<<" "<<a[n-1]+v[0];
		}
		return 0;
	}
	if(c1==n-2)
	{
		if(n!=3  || (n==3 && v[1]>v[0]))
		{
			for(i = 0;i < n-1;i++)
			{
				if(v[i]!=v[0]) break;
			}
			if(v[i]==2*v[0])
			{
				cout<<"1\n";
				cout<<a[i]+v[0];
				return 0;
			}
			else
				cout<<"0";
			return 0;
		}
	}
	if(c1==1)
	{
		for(i = 1;i < n-1;i++)
		{
			if(v[i]!=v[1])
			{
				cout<<"0";return 0;
			}
		}
		
		if(v[0]==2*v[1])
		{
			cout<<"1\n";
			cout<<a[1]-v[1];
			return 0;
		}
		else
			cout<<"0";
		return 0;
	}
	else
		cout<<"0";
	return 0;
}
