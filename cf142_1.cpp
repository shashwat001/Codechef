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

struct gp
{
	int x,y,diff;
};

typedef struct gp g;

bool compa(g first,g second)
{
	if(first.x < second.x)
		return true;
	if(first.x > second.x)
		return false;
	if(first.y >= second.y)
		return true;
	return false;
}

bool compb(g first,g second)
{
	if(first.x < second.x)
		return true;
	if(first.x > second.x)
		return false;
	if(first.y <= second.y)
		return true;
	return false;
}

int main()
{
	int s,n,k,l,lena,lenb;
	g val;
	vector<g> a,b;
	scanf("%d %d",&s,&n);
	for(i = 0;i < n;i++)
	{
		scanf("%d %d",&k,&l);
		if(k <= l)
		{
			val.x = k;
			val.y = l;
			val.diff = l-k;
			a.pb(val);
		}
		else
		{
			val.x = k;
			val.y = l;
			val.diff = k+l;
			b.pb(val);
		}
	}
	sort(a.begin(),a.end(),compa);
	sort(b.begin(),b.end(),compb);
	
	lena = a.size();
	for(i = 0;i < lena;i++)
	{
		if(s < a[i].x)
		{
			printf("NO");
			exit(0);
		}
		else
		{
			s += a[i].diff;
		}
	}
	lenb = b.size();
	for(i = 0;i < lenb;i++)
	{
		if(s < b[i].x)
		{
			printf("NO");
			exit(0);
		}
		else
		{
			s -= b[i].diff;
		}
	}
	printf("YES");
	return 0;
}
