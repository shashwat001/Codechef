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
typedef vector<int> VI;
typedef pair<int,int> PII;

typedef struct _oformat
{
	lli x1,y1,x2,y2,k;
} oformat;

oformat mo(lli x1,lli y1,lli x2,lli y2,lli k)
{
	oformat ret;
	ret.x1=x1;
	ret.x2 = x2;
	ret.y1 = y1;
	ret.y2 = y2;
	ret.k = k;
	return ret;
}


lli mod(lli a, lli b) {
  return ((a%b)+b)%b;
}
lli extended_euclid(lli a, lli b, lli &x, lli &y) {  
  lli xx = y = 0;
  lli yy = x = 1;
  while (b) {
    lli q = a/b;
    lli t = b; b = a%b; a = t;
    t = xx; xx = x-q*xx; x = t;
    t = yy; yy = y-q*yy; y = t;
  }
  return a;
}

PII chinese_remainder_theorem(lli x, lli a, lli y, lli b) {
  lli s, t;
  lli d = extended_euclid(x, y, s, t);
  if (a%d != b%d) return make_pair(0,-1);
  return make_pair(mod(s*b*x+t*a*y,x*y)/d, x*y/d);
}

// Chinese remainder theorem: find z such that
// z % x[i] = a[i] for all i.  Note that the solution is
// unique modulo M = lcm_i (x[i]).  Return (z,M).  On 
// failure, M = -1.  Note that we do not require the a[i]'s
// to be relatively prime.
PII chinese_remainder_theorem(const VI &x, const VI &a) {
  PII ret = make_pair(a[0], x[0]);
  for (lli i = 1; i < x.size(); i++) {
    ret = chinese_remainder_theorem(ret.second, ret.first, x[i], a[i]);
    if (ret.second == -1) break;
  }
  return ret;
}


lli p[200][200],a[200][200],n,m,i,j;
oformat out[10004],out2[10004];
lli co = 0,co2 = 0;
pi apr[200][200];
int solve2(int i)
{
	int curco = co;
	lli i = 1;
	VI av,xv;
		lli jbegin,jend;
		jbegin = jend = 1;
		if(i<n)
		{
			while(jend<=m)
			{
			
				if(jbegin == jend  &&  a[i][jend] == 0 && a[i+1][jend] == 0)
				{
					jbegin++;
					jend++;
					continue;
				}
				xv.pb(p[i][jend]);
				xv.pb(p[i+1][jend]);
			
				av.pb(p[i][jend]-a[i][jend]);
				av.pb(p[i+1][jend]-a[i+1][jend]);
			
				pi pr = chinese_remainder_theorem(xv,av);
				if(pr.second==-1 && jbegin == jend)
				{
					if(a[i][jbegin]!=0)
						out[co++] = mo(i,jbegin,i,jend,p[i][jbegin]-a[i][jbegin]);
					if(a[i+1][jbegin]!=0)
						out[co++] = mo(i+1,jbegin,i+1,jend,p[i+1][jbegin]-a[i+1][jbegin]);
					jbegin++;
					jend++;
					xv.clear();
					av.clear();
					continue;
				}
				if((pr.second == -1))
				{
					out[co++] = mo(i,jbegin,i+1,jend-1,apr[i][jend-1].first);
					jbegin = jend;
					xv.clear();
					av.clear();
					continue;
				}
				apr[i][jend] = pr;
				jend++;
			}

			if(jbegin<=m)
			{
				out[co++] = mo(i,jbegin,i+1,jend-1,apr[i][jend-1].first);
				xv.clear();
				av.clear();
			}
		}
		else
		{
			while(jend<=m)
			{
				if(jbegin == jend  &&  a[i][jend] == 0)
				{
					jbegin++;
					jend++;
					continue;
				}
				xv.pb(p[i][jend]);
			
				av.pb(p[i][jend]-a[i][jend]);
			
				pi pr = chinese_remainder_theorem(xv,av);
				if((pr.second == -1))
				{
					out[co++] = mo(i,jbegin,i,jend-1,apr[i][jend-1].first);
					jbegin = jend;
					xv.clear();
					av.clear();
					continue;
				}
				apr[i][jend] = pr;
				jend++;
			}
			if(jbegin<=m)
			{
				out[co++] = mo(i,jbegin,i,jend-1,apr[i][jend-1].first);
				xv.clear();
				av.clear();
			}
		}
		int newco = co;
		co = curco;
		return newco-curco;
}
void dosolve2(int i)
{
	int curco = co;
	lli i = 1;
	VI av,xv;
		lli jbegin,jend;
		jbegin = jend = 1;
		if(i<n)
		{
			while(jend<=m)
			{
			
				if(jbegin == jend  &&  a[i][jend] == 0 && a[i+1][jend] == 0)
				{
					jbegin++;
					jend++;
					continue;
				}
				xv.pb(p[i][jend]);
				xv.pb(p[i+1][jend]);
			
				av.pb(p[i][jend]-a[i][jend]);
				av.pb(p[i+1][jend]-a[i+1][jend]);
			
				pi pr = chinese_remainder_theorem(xv,av);
				if(pr.second==-1 && jbegin == jend)
				{
					if(a[i][jbegin]!=0)
						out[co++] = mo(i,jbegin,i,jend,p[i][jbegin]-a[i][jbegin]);
					if(a[i+1][jbegin]!=0)
						out[co++] = mo(i+1,jbegin,i+1,jend,p[i+1][jbegin]-a[i+1][jbegin]);
					jbegin++;
					jend++;
					xv.clear();
					av.clear();
					continue;
				}
				if((pr.second == -1))
				{
					out[co++] = mo(i,jbegin,i+1,jend-1,apr[i][jend-1].first);
					jbegin = jend;
					xv.clear();
					av.clear();
					continue;
				}
				apr[i][jend] = pr;
				jend++;
			}

			if(jbegin<=m)
			{
				out[co++] = mo(i,jbegin,i+1,jend-1,apr[i][jend-1].first);
				xv.clear();
				av.clear();
			}
		}
		else
		{
			while(jend<=m)
			{
				if(jbegin == jend  &&  a[i][jend] == 0)
				{
					jbegin++;
					jend++;
					continue;
				}
				xv.pb(p[i][jend]);
			
				av.pb(p[i][jend]-a[i][jend]);
			
				pi pr = chinese_remainder_theorem(xv,av);
				if((pr.second == -1))
				{
					out[co++] = mo(i,jbegin,i,jend-1,apr[i][jend-1].first);
					jbegin = jend;
					xv.clear();
					av.clear();
					continue;
				}
				apr[i][jend] = pr;
				jend++;
			}
			if(jbegin<=m)
			{
				out[co++] = mo(i,jbegin,i,jend-1,apr[i][jend-1].first);
				xv.clear();
				av.clear();
			}
		}

}
int solve1(int i)
{
	int curco = co;
	lli i = 1;
	VI av,xv;
		lli jbegin,jend;
		jbegin = jend = 1;
		
		while(jend<=m)
		{
			if(jbegin == jend  &&  a[i][jend] == 0)
			{
				jbegin++;
				jend++;
				continue;
			}
			xv.pb(p[i][jend]);
		
			av.pb(p[i][jend]-a[i][jend]);
		
			pi pr = chinese_remainder_theorem(xv,av);
			if((pr.second == -1) || (jend-jbegin)>10)
			{
				out[0].pb(mo(i,jbegin,i,jend-1,apr[i][jend-1].first));
				jbegin = jend;
				xv.clear();
				av.clear();
				continue;
			}
			apr[i][jend] = pr;
			jend++;
		}
		if(jbegin<=m)
		{
			out[0].pb(mo(i,jbegin,i,jend-1,apr[i][jend-1].first));
			xv.clear();
			av.clear();
		}
				int newco = co;
		co = curco;
		return newco-curco;
}
void dosolve1(int i)
{
	int curco = co;
	lli i = 1;
	VI av,xv;
		lli jbegin,jend;
		jbegin = jend = 1;
		
		while(jend<=m)
		{
			if(jbegin == jend  &&  a[i][jend] == 0)
			{
				jbegin++;
				jend++;
				continue;
			}
			xv.pb(p[i][jend]);
		
			av.pb(p[i][jend]-a[i][jend]);
		
			pi pr = chinese_remainder_theorem(xv,av);
			if((pr.second == -1) || (jend-jbegin)>10)
			{
				out[0].pb(mo(i,jbegin,i,jend-1,apr[i][jend-1].first));
				jbegin = jend;
				xv.clear();
				av.clear();
				continue;
			}
			apr[i][jend] = pr;
			jend++;
		}
		if(jbegin<=m)
		{
			out[0].pb(mo(i,jbegin,i,jend-1,apr[i][jend-1].first));
			xv.clear();
			av.clear();
		}

}

void solve()
{
	int i = 1;
	while(i<=n)
	{
		int c1 = solve1(i);
		int c2 = 	solve1(i+1);
		int c3 = solve2(i);
		if(c1+c2 < c3)
		{
			dosolve1(i);
			dosolve1(i+1);
		}
		else
		{
			dosolve2(i);
		}
	}
}
int main ()
{
	cin>>n>>m;
	for(i = 1;i <= n;i++)
	{
		for (j = 1; j <= m; j += 1)
		{
			cin>>p[i][j];
		}
	}
	for(i = 1;i <= n;i++)
	{
		for (j = 1; j <= m; j += 1)
		{
			cin>>a[i][j];
		}
	}
	for(i = 0;i < 200;i++)
		for(j = 0;j < 200;j++)
			apr[i][j] = mp(0,0);
	solve();
	for(i = 0;i < 200;i++)
	{
		for(j = 0;j < 200;j++)
			apr[i][j] = mp(0,0);
	}
	assert(co>=0 && co<=n*m);

		printf("%lld\n",co);
		for(i = 0;i < co;i++)
		{
			printf("%lld %lld %lld %lld %lld\n",out[i].x1,out[i].y1,out[i].x2,out[i].y2,out[i].k);
		}

	return 0;
}

