//shashwat001

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef pair<int,int> pi;

#define BUF 4096
char ibuf[BUF];
 
int ipt = BUF;
 
int readInt() {
 
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
 
    if (ipt == BUF) {
	fread(ibuf, 1, BUF, stdin);
 
	ipt = 0;
	while (ipt < BUF && ibuf[ipt] < '0') ipt++;
 
    }
    int n = 0;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
 
    if (ipt == BUF) {
	fread(ibuf, 1, BUF, stdin);
 
	ipt = 0;
	while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
 
    }
    return n;
}
#define maxv 100000
int h[2*maxv];

int main ()
{
	int t;
	t = readInt();
	while(t--)
	{
		memset(h,0,sizeof(h));
		int n,a,b,c,d,k,f;
		n = readInt();
		a = readInt();
		b = readInt();
		c = readInt();
		d = readInt();
		k = readInt();
		f = readInt();
		
		queue<int > q;
		q.push(n);
		h[maxv+n] = 1;
		int flag = 0;
		int depth;
		while(!q.empty())
		{
			int p = q.front();
			q.pop();
			if( p%k == f%k)
			{
				flag = 1;
				depth = h[maxv+p]-1;
				break;
			}
			if(p+a < maxv  && h[maxv+p+a]==0)
			{
				h[maxv+p+a] = h[maxv+p]+1;
				q.push(p+a);
			}
			if(p-b>=0 && h[maxv+p-b]==0)
			{
				h[maxv+p-b] = h[maxv+p]+1;
				q.push(p-b);
			}
			if(p*c < maxv && h[maxv+p*c]==0)
			{
				h[maxv+p*c] = h[maxv+p]+1;
				q.push(p*c);
			}
			int pp;
			if(p < 0)
			{
				pp = (p%d)+d;
			}
			else
			{
				pp = p%d;
			}
			if(h[maxv+pp]==0)
			{
				h[maxv+pp] = h[maxv+p]+1;
				q.push(pp);
			}
			
		}
		
		if(flag == 0)
			printf("-1\n");
		else
			printf("%d\n",depth);
	}
	return 0;
}
