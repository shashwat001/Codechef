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

bool isvip1(int n)
{
	if(n<=36)
		return true;
	return false;
}

bool isvip2(int n)
{
	int d1 = n%10;
	int d2 = n/10;
	if(d1==1 || d1== 3 || d1==4 || d1==6)
	{	}
	else
		return false;
	if(d2>=1 && d2 <= 9)
		return true;
	return false;
}

int convertv1tov2(int n)
{
	n--;
	int d1 = n%4;
	int d2 = n/4;
	int retval = (d2+1)*10;
	int a[] = {1,3,4,6,3,0,4};
	retval += a[d1];
	return retval;
}
int a[1000000];
int main ()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		bool v1 = true, v2 = true, both = true;
		int n,i;
		cin>>n;
		for(i = 0;i < n;i++)
		{
			cin>>a[i];
			if(isvip1(a[i]) && isvip2(a[i]))
			{}
			else
			{
				if(!isvip1(a[i]))
				{
					v1 = false;	
				}
				if(!isvip2(a[i]))
				{
					v2 = false;
				}
				both = false;
			}
		}
		if(both==true)
		{
			cout<<"UNCLASSIFIABLE\n";
		}
		else if(v1==false && v2 == false)
		{
			cout<<"THIEF\n";
		}
		else
		{
			if(v1==false)
			{
				for(i = 0;i < n;i++)
				{
					cout<<a[i]<<" ";
				}
				cout<<endl;
			}
			else
			{
				for(i = 0;i < n;i++)
				{
					cout<<convertv1tov2(a[i])<<" ";
				}
				cout<<endl;
			}
		}
	}
	return 0;
}
