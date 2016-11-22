#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;

int i,j;

/**********************************************************************************************/
char a[31][31];
int len,n,p,cstars,m;
vector<pair<int,int> > edges,edgesdiag;

void readinput()
{
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%s",a[i]);
	}
}

int main()
{
	readinput();
	cstars = 0;
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			if(a[i][j] == '*')
			{
				cstars++;
				edges.push_back(make_pair(i,j));
			}
		}
	}
	p = sqrt(2*cstars);
	m = 0;
	while(m<n)
	{
		for(i = 0,j = m;i <= m;i++,j--)
		{
			if(a[i][j] == '*')
			{
				edgesdiag.push_back(make_pair(i,j));
			}
		}
		m++;
	}
	while(m < 2*n-1)
	{
		for(j = n-1,i = m-n; i <= n-1;i++,j--)
		{
			if(a[i][j] == '*')
			{
				edgesdiag.push_back(make_pair(i,j));
			}
		}
		m++;
	}
	return 0;
}
