#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

#define INF 2147483647
#define LLINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef unsigned int uint;
typedef unsigned long long int ulli;
typedef pair<int,int> pairint;

#define BUF 4096
char ibuf[BUF];
int ipt = BUF;

int readInt()
{
	while (ipt < BUF && ibuf[ipt] < '0')
		ipt++;

	if (ipt == BUF)
	{
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] < '0')
			ipt++;
	}

	int n = 0;
	while (ipt < BUF && ibuf[ipt] >= '0')
		n = (n*10)+(ibuf[ipt++]-'0');

	if (ipt == BUF)
	{
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] >= '0')
			n = (n*10)+(ibuf[ipt++]-'0');
	}
	return n;
}

/********************************************************************************************/

int i,j;

int main()
{
	int t,a[101][101] = {0},n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		
		for(i = 1;i <= n;i++)
		{
			for(j = 1;j <= n;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(i = 1;i <= n;i++)
		{
			if(i==1)
			for(j = 1;j <= n;j++)
			{
				a[i][j] += a[i][j-1];
			}
			else
			for(j = 1;j <= n;j++)
			{
				if(j==1)
				a[i][j] += a[i-1][j];
				else
				a[i][j] += max(a[i-1][j],a[i][j-1]);
			}
		}
		if(a[n][n] < 0)
			printf("Bad Judges\n");
		else
			printf("%lf\n",(double)a[n][n]/(double)(2*n-3));
	}
	return 0;
}
