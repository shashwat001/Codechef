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

#define MOD 1000000007
int i,j;

deque<pairint> dmin,dmax;

int main()
{
	int n,b,maxm,minm,minidx,maxidx;
	int a[100001];
	lli p=1;
	n = readInt();
	for(i = 0;i < n;i++)
	{
		a[i] = readInt();
	}
	for(i = 2;i <= n;i++)
	{
		//minm = INF;
		//maxm = 0;
		dmin.clear();
		dmax.clear();
		dmin.push_front(mp(a[0],0));
		dmax.push_front(mp(a[0],0));
		for(j = 1;j < i;j++)
		{
			while(!dmin.empty())
			{
				if((a[j] <= dmin.back().first)|| ((j - dmin.back().second) >= i))
				{
					dmin.pop_back();
				}
				else
				{
					break;
				}
			}
			while(!dmin.empty())
			{
				if(a[j] <= dmin.front().first ||  ((j - dmin.front().second) >= i))
				{
					dmin.pop_front();
				}
				else
				{
					break;
				}
			}
			dmin.push_front(make_pair(a[j],j));
			
			
			while(!dmax.empty())
			{
				if((a[j] >= dmax.back().first)|| ((j - dmax.back().second) >= i))
				{
					dmax.pop_back();
				}
				else
				{
					break;
				}
			}
			while(!dmax.empty())
			{
				if(a[j] >= dmax.front().first ||  ((j - dmax.front().second) >= i))
				{
					dmax.pop_front();
				}
				else
				{
					break;
				}
			}
			dmax.push_front(make_pair(a[j],j));		
		}
		p = (p*(dmax.back().first-dmin.back().first))%MOD;
		for(j = j;j < n;j++)
		{
			while(!dmin.empty())
			{
				if((a[j] <= dmin.back().first)|| ((j - dmin.back().second) >= i))
				{
					dmin.pop_back();
				}
				else
				{
					break;
				}
			}
			while(!dmin.empty())
			{
				if(a[j] <= dmin.front().first ||  ((j - dmin.front().second) >= i))
				{
					dmin.pop_front();
				}
				else
				{
					break;
				}
			}
			dmin.push_front(make_pair(a[j],j));
			
			
			while(!dmax.empty())
			{
				if((a[j] >= dmax.back().first)|| ((j - dmax.back().second) >= i))
				{
					dmax.pop_back();
				}
				else
				{
					break;
				}
			}
			while(!dmax.empty())
			{
				if(a[j] >= dmax.front().first ||  ((j - dmax.front().second) >= i))
				{
					dmax.pop_front();
				}
				else
				{
					break;
				}
			}
			dmax.push_front(make_pair(a[j],j));		
			
			p = (p*(dmax.back().first-dmin.back().first))%MOD;
		}
	}
	printf("%lld\n",p);
	return 0;
}
