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
typedef struct
{
   int exer;
   char name[20];
} book;
book books[1000010];
int main()
{

	int n,top=0,q,minm,minidx;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%d",&q);
		if(q>=0)
		{
		    books[top].exer = q;
		    scanf("%s",books[top].name);
		    if(q == 0)
		    	continue;
		    top++;
		}
		else
		{
		    minm = 10000000;
		    for(j = 0;j < top;j++)
		    {
		      	if(minm>=books[j].exer)
		      	{
					minm = books[j].exer;
					minidx = j;
		      	}
		    }
		    printf("%d %s\n",top-minidx-1,books[minidx].name);
		    top = minidx;
		}
	}
	return 0;
}
