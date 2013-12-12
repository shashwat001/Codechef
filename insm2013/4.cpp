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

#define INF 1000000007
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef pair<int,int> pi;
	
	int a[30][30];
	int c[10006][30];
int main ()
{

	int t,i,j,k,n,pi;
	char s[6];
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		for(i = 0;i < 26;i++)
		{
			scanf("%d",&pi);
			for(j = 0;j < pi;j++)
			{
				scanf("%s",s);
				a[i][s[0]-97] = 1;
				a[s[0]-97][i] = 1;
			}
		}
		scanf("%d",&n);
		
		for(i = 0;i<26;i++)
		{
			c[0][i] = 1;
		}
		for(i = 1;i < n;i++)
		{
			for(j = 0;j < 26;j++)
			{
				for(k = 0;k < 26;k++)
				{
					if(a[j][k]==0)
					{
						c[i][j]= (c[i][j]+c[i-1][k])%INF;
					}
				}
			}
		}
		int sum = 0;
		for(i = 0;i < 26;i++)
		{
			sum=(sum+c[n-1][i])%INF;
		}
		printf("%d\n",sum);
	}
	return 0;
}
