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

int r,c;
bool inbound(int x,int y)
{
	return (x>=0 && x<r && y>=0 && y<c);
}
int main ()
{
	char s[505][505];
	int up[505][505],down[505][505],left[505][505],right[505][505];

	int p[600] = {0},i,j,n,cnt,t;
	for(i = 2;i <= 500;i++)
	{
		for(j = 2;j<i;j++)
		{
			if((i%j)==0)
				break;
		}
		if(i==j)
			p[i] = 1;
	}
	for(i = 1;i < 600;i++)
	{
		p[i] = p[i]+p[i-1];
	}
	scanf("%d",&t);
	while(t--)
	{
		
		scanf("%d %d",&r,&c);
		for(i = 0;i < r;i++)
		{
			scanf("%s",s[i]);
		}
		for(i = 0;i < r;i++)
		{
			for(j = 0;j < c;j++)
			{
				if(inbound(i-1,j))
				{
					if(s[i-1][j]=='^')
						up[i][j] = up[i-1][j]+1;
					else
						up[i][j] = 0;
				}
				else
					up[i][j] = 0;
					
				if(inbound(i,j-1))
				{
					if(s[i][j-1]=='^')
						left[i][j] = left[i][j-1]+1;
					else
						left[i][j] = 0;
				}
				else
					left[i][j] = 0;
			}
		}
		for(i = r-1;i >= 0;i--)
		{
			for(j = c-1;j >= 0;j--)
			{
				if(inbound(i+1,j))
				{
					if(s[i+1][j]=='^')
						down[i][j] = down[i+1][j]+1;
					else
						down[i][j] = 0;
				}
				else
					down[i][j] = 0;
					
				if(inbound(i,j+1))
				{
					if(s[i][j+1]=='^')
						right[i][j] = right[i][j+1]+1;
					else
						right[i][j] = 0;
				}
				else
					right[i][j] = 0;
			}
		}
		cnt = 0;
		for(i = 0;i < r;i++)
		{
			for (j = 0; j < c; j += 1)
			{
				if(s[i][j]!='#')
				{
					n = min(min(min(down[i][j],up[i][j]),left[i][j]),right[i][j]);
					cnt+=p[n];
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
