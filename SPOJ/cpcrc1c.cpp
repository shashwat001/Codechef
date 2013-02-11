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
lli c[10];
int sumdig[10];

lli findsum(int a)
{
	int k = 1;
	int i = 0;
	lli sum = 0;
	int num = 0;
	int r;
	while(a>0)
	{
		r = a%10;
		a = a/10;
		if(r!=0)
			sum += sumdig[r-1]*k + (num+1)*r + r*c[i];
		num = num+r*k;
		k = k*10;
		i++;
//		printf("%lld\n",sum);
	}
	return sum;
}

int main()
{
	int a,b;
	int k;
	c[0] = 0;
	c[1] = 45;
	k = 10;
	sumdig[0] = 0;
	sumdig[1] = 1;
	for(i = 2;i < 10;i++)
	{
		sumdig[i] = sumdig[i-1]+i;
		c[i] = c[1]*k + c[i-1]*10;
		k = k*10;
	}
	scanf("%d",&a);
	scanf("%d",&b);
	while(a!=-1)
	{
		lli diff = findsum(b)-findsum(a-1);
		printf("%lld\n",diff);
		scanf("%d",&a);
	        scanf("%d",&b);
	
	}
	return 0;
}
