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
	int i,n,m,k,j;
	cin>>n>>m>>k;
	cout<<(m*(m-1))/2<<endl;
	if(k==0)
	{
		for(i = m-1;i > 0;i--)
		{
			for(j = 0;j < i;j++)
			{
				cout<<j+1<<" "<<j+2<<endl;
			}
		}
	}
	else
	{
		for(i = 1;i < m;i++)
		{
			for(j = m-1;j >= i;j--)
			{
				cout<<j+1<<" "<<j<<endl;
			}
		}
	}
	return 0;
}
