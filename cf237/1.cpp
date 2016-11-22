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
	int i,j,n,l;
	cin>>n;
	char s[400][400];
	for(i = 0;i < n;i++)
	{
		cin>>s[i];
	}
	char c = s[0][0],d;

		d = s[0][1];
		if(d==c)
		{
			cout<<"NO";
			return 0;
		}
	for(i = 0;i < n;i++)
	{
		if(s[i][i]!=c)
		{
			cout<<"NO";
			return 0;
		}
		if(s[i][n-1-i]!=c)
		{
			cout<<"NO";
			return 0;
		}
	}

		for(i = 0;i < n;i++)
		{
			for(j = 0;j < n;j++)
			{
				if((i!=j) && i!=n-1-j )
				{
					if(s[i][j]!=d)
					{
						cout<<"NO";
						return 0;
					}
				}
			}
		}

	cout<<"YES";
	return 0;
}
