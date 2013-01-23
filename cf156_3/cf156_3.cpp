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
#include <map>

using namespace std;

#define INF 2147483647
#define LLINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef unsigned int uint;
typedef unsigned long long int ulli;
typedef pair<int,int> pairint;

#define BUF 65536
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

int i,j,l,lmax = 0,n,a[4001],diff;
multimap<int,int> m[4001];
multimap<int,int>::iterator it;
int main()
{
	n = readInt();
	for(i = 0;i < n;i++)
		a[i] = readInt();

	if(n == 1)
		lmax = 1;
	else
	{
		for(i = 1;i < n;i++)
		{
			for(j = 0;j < i;j++)
			{
				diff = a[i]-a[j];
				it = m[j].find(-diff);
				if(it == m[j].end())
				{
					if(lmax < 2)
						lmax = 2;
					it = m[i].find(diff);
					if(it == m[i].end())						
						m[i].insert(pair<int,int>(diff,2));
				}
				else
				{
					l = it->second + 1;
					if(lmax<l)
						lmax = l;
					it = m[i].find(diff);
					if(it == m[i].end())
						m[i].insert(pair<int,int>(diff,l));
					else
					{
						if(it->second < l)
							it->second = l;
					}
				}
			}
		}
	}
	printf("%d",lmax);
	return 0;
}
