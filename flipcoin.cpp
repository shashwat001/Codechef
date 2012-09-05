/* Jai Gupta */
#include <iostream>
#include <cstdio>
 
#include <vector>
#include <stack>
#include <queue>
 
#include <string>
#include <cstring>
#include <map>
 
#include <cstdlib>
#include <algorithm>
#include <list>
 
#include <deque>
#include <bitset>
#include <cmath>
 
#include <functional>
#include <set>
 
using namespace std;
 
 
#define INT_MAX 2147483647
#define INT_MIN -2147483648
 
#define uint unsigned int
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
 
#define CMAX(a,b) if((a)<(b)) a=b
#define CMIN(a,b) if((a)>(b)) a=b
#define FOR(i,a,b) for(i=a; i<b; i++)
 
#define REVI(i,a,b) for(int i= a ; i >= b ; --i)
#define LET(x,a) __typeof(a) x(a)
 
#define IFOR(i,a,b) for(LET(i,a);i!=(b);++i)
#define EACH(it,v) IFOR(it,v.begin(),v.end())
#define SWAP(a,b,t) t=a,a=b,b=t
 
#define REP(i,n) for(int i=0; i<n; i++)
#define ll long long
#define gint(t)scanf("%d", &t);
 
#define gint2(a,b)scanf("%d%d", &a, &b);
#define gint3(a,b,c)scanf("%d%d%d", &a, &b, &c);
 
#define pint(t)printf("%d\n", t);
#define pint2(a,b)printf("%d %d\n", a, b);
 
#define pint3(a,b,c)printf("%d %d %d\n", a, b, c);
#define pii pair<int, int>
 
#define debug(args...) {dbg,args; cerr<<endl;}
#define dline cerr<<endl
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
 
 
struct debugger
 
{
    template<typename T> debugger& operator , (const T& v)
 
	{
	    cerr<<v<<" ";
	    return *this;
 
	}
} dbg;
 
 
 
/* memset(start*, byteVal, numBytes);
 *  memcpy(dst*, src*, numBytes);
 */
 
 
 
const int BASE = 1<<17;
 
int r[BASE+BASE];
int f[BASE+BASE];
 
 
int lo,hi;
void update(int ind,int beg,int end)
 
{
	if(beg>hi || end<lo) return;
 
	if(lo<=beg && end<=hi)
	{
 
		r[ind] = end-beg+1 - r[ind];
		f[ind] = 1-f[ind];
 
		
		int len = end-beg+1;
		for(ind>>=1,len<<=1; ind; ind>>=1,len<<=1)
 
		{
			r[ind] = r[ind+ind] + r[ind+ind+1];
 
			if(f[ind])
				r[ind] = len - r[ind];
 
		}
		return;
	}
	
 
	int twice=ind<<1;
	int mid = (beg+end)>>1;
 
	
	update(twice,beg,mid);
	update(twice+1,mid+1,end);
 
}
 
void updatex(int _lo,int _hi)
 
{
	lo=_lo;
	hi=_hi;
	update(1,0,BASE-1);
 
}
 
int query(int ind,int beg,int end,int flip)
 
{
	if(beg>hi || end<lo) return 0;
 
	if(lo<=beg && end<=hi) return flip ? end-beg+1 - r[ind] : r[ind];
 
	
	int twice=ind<<1;
	int mid = (beg+end)>>1;
 
	flip = flip^f[ind];
 
	return query(twice,beg,mid,flip) + query(twice+1,mid+1,end,flip);
 
}
 
int query(int _lo,int _hi)
 
{
	lo=_lo;
	hi=_hi;
	return query(1,0,BASE-1,0);
 
}
 
void init()
 
{
    memset(r,0, sizeof(int)*(BASE+BASE));
 
    memset(f,0, sizeof(int)*(BASE+BASE));
 
}
 

 
int main()
{
 
    int n, q, t, s, e;
    n= readInt();
    q = readInt();
 
    REP(qi, q) {
	t = readInt();
 
	s = readInt();
	e = readInt();
	if(t==0)
 
	{
	    updatex(s, e);
	}
 
	else {
	    pint(query(s, e));
 
	}
    }
    return 0;
 
} 
