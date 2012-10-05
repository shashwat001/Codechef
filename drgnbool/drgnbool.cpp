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
	int t,m,n,l[100],sum,maxl,c;
	t = readInt();
	while(t--)
	{
		maxl = 0;
		sum = 0;
		memset(l,0,sizeof(l));
		n = readInt();
		m = readInt();
		while(n--)
		{
			c = readInt();
			j = readInt();
			if((j) > maxl)
				maxl = j;
			l[j-1]+=c;
		}
		while(m--)
		{
			c = readInt();
			j = readInt();
			l[j-1]-=c;
		}
		while(maxl--)
		{
			if(l[maxl] < 0)
				sum = sum - l[maxl];
		}
		printf("%d\n",sum);
	}
	return 0;
}
