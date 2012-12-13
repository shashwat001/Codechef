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
#define MOD 1000000007

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

int i,j,n;

int a[100002];
int Min[400008],Max[4000008];

void formminsegtree(int b,int e,int idx)
{
	if(b==e)
	{
		Min[idx] = b;
		return;
	}
	
	int mid = (b+e)/2;
	int lidx = 2*idx+1;
	int ridx = 2*idx+2;
	formminsegtree(b, mid, lidx);
	formminsegtree(mid+1,e,ridx);
	if(a[Min[lidx]] <= a[Min[ridx]])
	{
		Min[idx] = Min[lidx];
	}
	else
	{	
		Min[idx] = Min[ridx];
	}		
}


void formmaxsegtree(int b,int e,int idx)
{
	if(b==e)
	{
		Max[idx] = b;
		return;
	}
	
	int mid = (b+e)/2;
	int lidx = 2*idx+1;
	int ridx = 2*idx+2;
	formmaxsegtree(b, mid, lidx);
	formmaxsegtree(mid+1,e,ridx);
	if(a[Max[lidx]] >= a[Max[ridx]])
	{
		Max[idx] = Max[lidx];
	}
	else
	{	
		Max[idx] = Max[ridx];
	}		
}

int getmin(int b,int e,int l,int r,int idx)
{
	int mid = (b+e)/2;
	if(l>e || r < b)
		return -1;
	if(b>=l && e<=r)
		return Min[idx];
	int val1 = getmin(b,mid,l,r,2*idx+1);
	int val2 = getmin(mid+1,e,l,r,2*idx+2);
	
	if(val1 == -1)
		return  val2;
	if(val2 == -1)
		return  val1;
	if(a[val1] <= a[val2])
		return  val1;
	return  val2;
}


int getmax(int b,int e,int l,int r,int idx)
{
	int mid = (b+e)/2;
	if(l>e || r < b)
		return -1;
	if(b>=l && e<=r)
		return Max[idx];
	int val1 = getmax(b,mid,l,r,2*idx+1);
	int val2 = getmax(mid+1,e,l,r,2*idx+2);
	
	if(val1 == -1)
		return  val2;
	if(val2 == -1)
		return  val1;
	if(a[val1] >= a[val2])
		return  val1;
	return  val2;
}




int main()
{
	int n,m,minm,i,l,r;
	scanf("%d",&m);
	for(i = 0;i < m;i++)
		scanf("%d",&a[i]);
	formmaxsegtree(0,m-1,0);
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&l,&r);
		minm = getmax(0,m-1,l,r,0);

		printf("%d\n",a[minm]);
	}
	return 0;
}
