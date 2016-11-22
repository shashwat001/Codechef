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
	int t;
	cin>>t;
	while(t--)
	{
		int k,n,s[100],cs=0;
		cin>>n>>k;
		for(int i = 0;i < k;i++)
		{
			cin>>s[k];
		}
		int d[100][100] = {0};
		d[1][1] = 1;
		for(int i = 2;i <= 2*n;i++)
		{
			for (unsigned int j = 0; j <= i; j += 1)
			{
				if(i == s[cs])
				{
					d[i][j] = d[i-1][j-1];
				}
				else
				{
					d[i][j] = d[i-1][j-1] + d[i-1][j+1];
				}
			}
			if(i==s[cs])
				cs++;
		}
		cout<<d[2*n][0]<<endl;
	}
	return 0;
}
