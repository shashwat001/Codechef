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
#include <cmath>

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
	lli t,n,r;
	int a[11],ans,po,m;
	double rt;
	cin>>n;
	for(i = 0;i <n;i++)
	{
		cin>>t;
		if(t==1)
		{
			printf("NO\n");
			continue;
		}
		j = 1;
		while(t>0)
		{
			r = t%10;
			a[j++] = r;
			t = t/10;
		}
		a[0] = j;
		j = j-1;
		ans = 0;
		po = 0;
		r = 0;
		while(j > 0)
		{
			if(j&1)
			{
				r = r*10 + a[j];
				m = 9;
				while((ans*10+m)*m>r)
					m--;
				r = r - (ans*10+m)*m;
				po = po*10+m;
				ans = 2*po;
				j--;
			}
			else
			{
				r = r*10+a[j];
				j--;
			}
		}
		if(r == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
