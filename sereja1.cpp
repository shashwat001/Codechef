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
class compare
{
	public:
	bool operator()(pairint a,pairint b)
	{
		return !(a.first < b.first);
	}
};

int a[100002];
int Max[40000008];
priority_queue<pairint,vector<pairint>,compare> pq;



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


lli modexpo(int x,lli y,int m)
{
	lli r = 1;
	lli lx = x;
	while(y > 0)
	{
		if(y&1)
		{
			r = (r*lx)%m;
		}
		lx = (lx*lx)%m;
		y >>= 1;
	}
	return r%m;
}

lli pro = 1;

void findthismin(int b,int e,int mminidx)
{
	if(b>=e) return;
	int k;
	int elem = e-b+1;
	int mmaxidx = getmax(0,n-1,b,e,0);
	
	int minidx = mminidx-b;
	int maxidx = mmaxidx-b;
	int sidemin;
	
	lli y;
	
	if(minidx < maxidx)
	{

		int dif = a[mmaxidx] - a[mminidx];
		sidemin = min(minidx , elem - maxidx-1);
		k = maxidx - minidx + 1;
		y = (lli)(sidemin+1)*(lli)(elem-k+1-sidemin);
		pro = (pro*modexpo(dif,y,MOD))%MOD;
		findthismin(b,mmaxidx-1,mminidx);
	}
	else
	{

		int dif = a[mmaxidx] - a[mminidx];
		sidemin = min(maxidx , elem - minidx-1);
		k = minidx - maxidx + 1;
		y = (lli)(sidemin+1)*(lli)(elem-k+1-sidemin);
		pro = (pro*modexpo(dif,y,MOD))%MOD;
		findthismin(mmaxidx+1,e,mminidx);
	}

}



void findpro(int b,int e)
{
	if(b>=e) return;
	
	//int mminidx = getmin(0,n-1,b,e,0);	
	int mminidx = pq.top().second;
	pq.pop();
	findthismin(b,e,mminidx);

	
	findpro(b,mminidx-1);
	findpro(mminidx+1,e);
	
}



int main()
{
	
	n = readInt();
	for(i = 0;i < n;i++)
	{
		a[i] = readInt();
		pq.push(mp(a[i],i));
	}
	//formminsegtree(0,n-1,0);
	formmaxsegtree(0,n-1,0);
	findpro(0,n-1);
	printf("%lld\n",pro);
	return 0;
}
