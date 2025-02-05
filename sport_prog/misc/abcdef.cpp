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
int sum[120001] = {0};

bool isdiv(int a,int b)
{
	if(b==0)
		return false;
	if(b < 0)
	{
		b = -b;
	}
	if(a%b==0)
		return true;
	return false;

}

int main()
{
	int n,a[101],pro[10001],proc = 0,c = 0,k,f,l,m,p;
	list<int> prol;
	int lhs;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
	}

	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			pro[proc++] = a[i]*a[j];
			sum[a[i]+a[j]+60000]++;
		}
	}
	for(i = 0;i < proc;i++)
	{		
		for(j = 0;j < n;j++)
		{
			for(k = 0;k < n;k++)
			{
				f = pro[i] + a[j];
				if(isdiv(f,a[k]))
				{
					lhs = f/a[k];
					c+=sum[lhs+60000];
				}
			}
		}
	}
	printf("%d\n",c);
	return 0;
}
