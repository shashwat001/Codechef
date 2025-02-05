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
	int t,n,c,h[1005],k[1005],a[1005],T,minm,maxm,flag;
	t = readInt();
	while(t--)
	{
		n = readInt();
		c = 0;
		memset(a,0,sizeof(a));
		maxm = 0;
		for(i = 0;i < n;i++)
		{
			h[i] = readInt();
			h[i] = 2*h[i];
			if(maxm < h[i])
				maxm = h[i];
		}
		for(i = 0;i < n;i++)
		{
			k[i] = readInt();
		}
		sort(k,k+n);
		a[0] = 1;
		for(i = 1;i <= maxm;i++)
		{ 
			minm = 1000000;
			flag = 0;
			for(j = 0;j < n;j++)
			{
				if(i == k[j])
				{
					a[i] = 1;
					break;;
				}
				if(i > k[j])
				{
				     if(a[i-k[j]]!=0)
				     {
					if(minm > a[i-k[j]])
						minm = a[i-k[j]];
				     }
					flag = 1;
				}
				else
					break;
			}
			if(a[i]==1)
				continue;
			if(flag == 0 || minm==0)
				a[i] = 0;
			else
				a[i] = minm+1;
		}
		for(i = 0;i < n;i++)
		{
		/*	for(j = n-1;j >= 0;j--)
			{
				if((h[i]%k[j]) == 0)
				{
					c+=h[i]/k[j];
					break;
				}
			}*/
			c+=a[h[i]];
		}
		printf("%d\n",c);

	}
	return 0;
}
