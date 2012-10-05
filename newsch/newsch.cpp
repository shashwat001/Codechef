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
	long long int n,m,res = 1,a[32];
	int MOD = 1000000007,t;
	a[0] = 3;
	for(i = 1;i < 32;i++)
	{
		a[i] = (a[i-1]*a[i-1])%MOD;
	}
	t = readInt();
	while(t--)
	{
		i = 0;
		res = 1;
		n = readInt();
		m = n;
		while(n>0)
		{
			if(n&1)
			{
				res = (res*a[i])%MOD;
			}
			n>>=1;
			i++;
		}
		if(m&1)
		{
			if(res-3 <0)
				printf("%lld\n",(res-3+MOD));
			else
				printf("%lld\n",(res-3)%MOD);
		}
		else
			printf("%lld\n",(res+3)%MOD);
	}
	return 0;
}
