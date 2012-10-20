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
	int t,n;
	long long p[2001][1001],r,s,res;
	p[0][1] = 0;
	p[0][0] = 0;
	for(i = 1;i <= 2000; i++)
	{
		for(j = 1;j <= (i+1)/2;j++)
		{
			if(j>i/2)
			{
				r = p[i-1][i-j];
			}
			else
				r = p[i-1][j];
			if((j-1)>i/2)
			{
				s = p[i-1][i-j+1];
			}
			else
				s = p[i-1][j-1];
			p[i][j] = 1000000000.0 - ((r + s)>>1);
			//p[i][i+1-j] = p[i][j];
		}
	}
	t = readInt();
	while(t--)
	{
		res = 0.0;
		n = readInt();
		for(i = 1;i <= (n+1)/2;i++)
		{
			j = readInt();
			//if((n&1) && (i==(n+1)/2))
				//res = 2*p[n][i]*j;
			//else
				res += p[n][i]*j;
		}
		for(i = i;i <= n;i++)
		{
			j = readInt();
			res += p[n][n+1-i]*j;
		}
		printf("%lld\n",res/1000000000);
	}
	
	/*for(i = 1;i <= 10;i++)
	{
		for(j = 1;j <= (i+1)/2;j++)
		{
			printf("%f  ",p[i][j]);
		}
		printf("\n");
	}*/
	return 0;
}
