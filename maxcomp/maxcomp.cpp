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

typedef struct _event event;
struct _event
{
	int s,e,c;
};

event make_order(int s,int e,int c)
{
	event ev;
	ev.s = s;
	ev.e = e;
	ev.c = c;
	return ev;
}

bool comp(event first,event second)
{
	if(first.e < second.e)
		return true;
	if(first.e == second.e)
	{
		if(first.c < second.c)
			return true;
	}
	return false;
}

event orders[2000];
lli sum[2000];

int bs(int left, int right, int val)
{
	if(right < 0)
		return 0;
	if(left == right)
	{
			return sum[left-1];
	}
	int res;
	int mid = (left+right)>>1;
	if(orders[mid].e < val)
		res = bs(mid+1,right,val);
	else
		res = bs(left,mid,val);
	return res;
}

int main()
{
	int t,n,res,e,s,c;
	t = readInt();
	while(t--)
	{
		memset(orders,0,sizeof(orders));
		n = readInt();
		for(i = 0;i < n;i++)
		{
			s = readInt();
			e = readInt();
			c = readInt();
			orders[i].s = s;
			orders[i].e = e;
			orders[i].c = c;
		}
		sort(orders,orders+n,comp);
		sum[0] = orders[0].c;
		for(i = 1;i < n;i++)
		{
			res = bs(0,i,orders[i].s+1);
			if((res + orders[i].c)>sum[i-1])
				sum[i] = res+orders[i].c;
			else
				sum[i] = sum[i-1];
		}
		printf("%lld\n",sum[n-1]);
	}
	return 0;
}
