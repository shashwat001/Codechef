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

int d[105][100000];
int main()
{
	int t,i,j,c;
	cin>>t;
	while(t--)
	{
		int n,i,tm[1000],p[10000],w;
		cin>>n>>w;
		for(i = 1;i <= n;i++)
		{
			cin>>c>>p[i]>>tm[i];
			p[i] = p[i]*c;
		}
		memset(d,0,sizeof(d));
		for(i = 1;i <= n;i++)
		{
			for(j = 0;j <= w;j++)
			{   
					if(d[i-1][j]!=0)
					{
								d[i][j+tm[i]] = max(d[i][j+tm[i]],d[i-1][j]+p[i]);
					}		
					d[i][j] = max(d[i][j],d[i-1][j]);		
			}
			d[i][tm[i]] = max(d[i][tm[i]],p[i]);
		}
		int maxv = 0;
	
			for(j = 0;j <= w;j++)
			{   
				maxv = max(maxv,d[n][j]);
				
			}
		cout<<maxv<<endl;
		
	}
	return 0;
}
