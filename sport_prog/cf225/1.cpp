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
	int n;
	cin>>n;
	int c = 0;
		for (unsigned int i = 0; i < n; i += 1)
	{
		for (unsigned int j = 0; j < n; j += 1)
		{
			if((i+j)%2==0)
			{
				c++;
			}
		}
	}
	cout<<c<<endl;
	for (unsigned int i = 0; i < n; i += 1)
	{
		for (unsigned int j = 0; j < n; j += 1)
		{
			if((i+j)%2==0)
			{
				cout<<"C";
			}
			else
			cout<<".";
		}
		cout<<endl;
	}
	return 0;
}
