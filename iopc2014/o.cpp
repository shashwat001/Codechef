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
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int main ()
{
	int p,q,t;
	cin>>t;
	while(t--)
	{
		cin>>p>>q;
		int g = gcd(p,q);
		p = p/g;
		q = q/g;
		if(p==1)
		{
			while(q%2==0)
			{
				q = q/2;				
			}
			if((q&(q+1))==0)
			{

				cout<<"YES\n";
				continue;
			}
			else
			{
				cout<<"NO\n";
				continue;
			}
		}
		else if((p&(p-1))==0)
		{
			int ba = 0;
			while(p%2==0)
			{
				p = p/2;
				ba++;
				
			}
			if((q&(q+1))==0)
			{
				q++;
				int b = 0;
				while(q%2==0)
				{
					q = q/2;
					b++;
				}
				if(b>=ba)
					cout<<"YES\n";
				else 
					cout<<"NO\n";
				continue;
			}
			else
			{
				cout<<"NO\n";
				continue;
			}
		}
		else
		{
			cout<<"NO\n";
		}
	}
	return 0;
}
