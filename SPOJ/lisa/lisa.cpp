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
#define LINF 9223372036854775807LL
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
		int n,i,j,k,m;
		lli a[100][100],b[100][100];
		char s[200];
		cin>>s;
		int l =  strlen(s);
		n =  (l+1)/2;
		for(i = 0;i < n;i++)
		{
			a[i][i] = s[2*i]-'0';
			b[i][i] = s[2*i]-'0';
		}
		for(i = 2;i <= n;i++)
		{
			
			for(j = 0;j < n-(i-1);j++)
			{
				lli maxv = 0;
				lli minv = LINF;
				for(m = j;m < j+(i-1);m++)
				{
					if(s[2*m+1] == '*')
					{
						maxv = max(maxv,a[j][m]*a[m+1][j+(i-1)]);
						minv = min(minv,b[j][m]*b[m+1][j+(i-1)]);
					}
					else
					{
						maxv = max(maxv,a[j][m]+a[m+1][j+(i-1)]);
						minv = min(minv,b[j][m]+b[m+1][j+(i-1)]);
					}
				}
				a[j][j+(i-1)] = maxv;
				b[j][j+(i-1)] = minv;
			}
		}
		cout<<a[0][n-1]<<" "<<b[0][n-1]<<endl;
	}
	return 0;
}
