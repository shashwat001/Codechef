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
	int t,n,m,q,p,r,k;
	t = readInt();
	int att[100005]={0};
	while(t--)
	{
		n = readInt();
		m = readInt();
		q = readInt();
		p = readInt();
		r = readInt();
		k = readInt();
		
		int wcar = n;
		int wq = q;
		int rided = 0;
		int tim = 0;
		int wr = r;
		int wp = p;
		int time = 0;
		
		while(tim <= k)
		{
			if(wcar < wq)
			{
				wq = wq - wcar;
				att[tim+p] = wcar;
				wcar = 0;
				
			}
			else if(wcar > wq)
			{
				wcar = wcar - wq;
				wq = 0;
				att[tim+p] = wcar;
			}
			else
			{
				wcar = wcar - wq;
				wq = 0;
				att[tim+p] = wcar;
			}
			
			
			
			if(wr<wp)
			{ 
				if((tim+wr)<=k)
				{
				tim += wr;
				wp = wp-wr;
				wr = r;
				wq+=1;
				}
				else
					break;
			}
			else if(wp<wr)
			{
				if((tim+wp)<=k)
				{
				tim += wp;
				wr = wr - wp;
				wp = p;
				wcar+=att[tim];
				}
				else
					break;
				
			}
			else
			{
				if((tim+wr)<=k)
				{
					tim+=wr;
					wp = p;
					wr = r;
					wq+=1;
					wcar+=att[tim];
				}
				else
					break;
			}
		}
		cout<<wcar<<" "<<wq<<endl;
	}
	return 0;
}
