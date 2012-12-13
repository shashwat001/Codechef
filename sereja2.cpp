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
int Max[800008];

class compare
{
	public:
	bool operator()(pairint a,pairint b)
	{
		return !(a.first < b.first);
	}
};
void initialize(int node, int b, int e)
{
  if (b == e)
  {
      Max[node] = b;
  }
  else
   {
      initialize(2 * node, b, (b + e) / 2);
      initialize(2 * node + 1, (b + e) / 2 + 1, e);
          
      if (a[Max[2 * node]] >= a[Max[2 * node + 1]])
          Max[node] = Max[2 * node];
      else
          Max[node] = Max[2 * node + 1]; 
  }
} 



  
  int querymax( int b, int e, int i, int j,int node)
  {
      int p1, p2;

   
      if (i > e || j < b)
          return -1;
   
      if (b >= i && e <= j)
          return Max[node];
   
      p1 = querymax( b, (b + e) / 2,i, j,2 * node );
      p2 = querymax( (b + e) / 2 + 1, e, i, j,2 * node + 1);
   

      if (p1 == -1)
          return  p2;
      if (p2 == -1)
          return  p1;
      if (a[p1] >= a[p2])
          return  p1;
      return  p2;

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
	return r;
}

lli pro = 1;

void findthismin(int b,int e,int mminidx)
{
	if(b>=e) return;
	int k;
	int elem = e-b+1;
	int mmaxidx = querymax(0,n-1,b,e,1);
	
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



priority_queue<pairint,vector<pairint>,compare> pq;
void findpro(int b,int e)
{
	if(b>=e) return;
	
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
	initialize(1,0,n-1);
	findpro(0,n-1);
	printf("%lld\n",pro);
	return 0;
}
