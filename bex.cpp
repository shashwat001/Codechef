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

int tree[10000005] = {0},n;
typedef struct _node
{
	int exer;
	char name[20];
	int top;
	int minidx;
} node;

node a[1000005];
int p[1000009];
int ps = 0;

class compare
{
	public:
	bool operator()(int& y,int& z)
	{	
		if(a[p[y]].exer < a[p[z]].exer)
	       		return true;
		else if(a[p[y]].exer == a[p[z]].exer)
		{
			if(p[y] > p[z])
				return true;
		}
		return false;
	}
} comp;


int read(int idx)
{
	int sum = 0;
	while (idx > 0)
	{
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val)
{
	while (idx <= n)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

//priority_queue<int, vector<int>, compare> p;


void heapify(int i)
{
	int l,r,maxm,t;
	while(1)
	{
		l = 2*i+1;
		r = 2*i+2;
		if(l>=ps)
			return;
		if(r==ps)
			maxm = l;
		else if(comp(l,r))
		{
			maxm = l;
		}
		else
			maxm = r;
		if(!comp(maxm,i))
			return;
		t = p[i];
		p[i] = p[maxm];
		p[maxm] = t;
		i = maxm;
	}
}

void deletemin()
{
	p[0] = p[ps-1];
	ps--;
	heapify(0);
}

void insert(int val)
{
	int pp,ii;
	p[ps] = val;
	ii = ps;
	ps++;
	while(1)
	{
		if(ii==0)
			return;
			
		pp = (ii-1)/2;
		if(comp(pp,ii))
			return;
		p[ii] = p[pp];
		p[pp] = val;
		ii = pp;
	}
}
int main()
{	

	int q,topidx,peak,d,k,gh;
	node temp;
	char str[20];
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%d",&q);

		if(q >= 0)
		{	
			d = n-i;
			scanf("%s",str);
			if(q == 0)
				continue;
			a[i].exer = q;
			strcpy(a[i].name,str);		
			insert(i);
			update(d,1);

		}
		else
		{
			topidx = p[0];
			deletemin();
			k = read(n-topidx);

			update(n-topidx,-k);
			printf("%d %s\n",k-1,a[topidx].name);

			while(ps>0&&(p[0]>topidx))
			{
				deletemin();
			}


		}
	}
	return 0;
}
