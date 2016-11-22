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
  if (a%d != b%d) 
  {
  	return make_pair(a%d-b%d,-1);
  }
  return make_pair(mod(s*b*x+t*a*y,x*y)/d, x*y/d);
}

PII chinese_remainder_theorem(const VI &x, const VI &a) {
  PII ret = make_pair(a[0], x[0]);
  for (lli i = 1; i < x.size(); i++) {
    ret = chinese_remainder_theorem(ret.second, ret.first, x[i], a[i]);
    if (ret.second == -1) break;
  }
  return ret;
}


lli p[200][200],a[200][200],n,m,i,j;
oformat out[10004];
lli co = 0;
pi apr[200][200];
int crow = 3,irow;
int change = 0;
int maxchange = 100;

void solve1()
{
	lli i = 1;
	VI av,xv;
	while(i <= n)
	{
		lli jbegin,jend;
		jbegin = jend = 1;
		if(i+crow-1 > n)
			crow = n-i+1;
		while(jend<=m)
		{
		
			if(jbegin == jend)
			{
				for (irow = 0; irow < crow; irow += 1)
				{
					if(a[i+irow][jend] != 0)
						break;
				}
				if(irow == crow)
				{
					jbegin++;
					jend++;
					continue;
				}
			}
			int prevco = co;
			VI tempxv,tempav;
			int wrong = 0;
			for (irow = 0; irow < crow; irow += 1)
			{
				
				xv.pb(p[i+irow][jend]);
				av.pb(p[i+irow][jend]-a[i+irow][jend]);
//				pi pr = chinese_remainder_theorem(tempxv,tempav);
//				{
//					if(pr.second == -1)
//					{
//						//out[co++] = mo(i+irow,jend,i+irow,jend,pr.first + p[i+irow][jend]-a[i+irow][jend]);
//						//change++;
//						//arr[irow] = 1;
//						//cnt++;
//						wrong++;
//					}
//				}
//				
//				xv.pop_back();
//				av.pop_back();
			}
			//if(wrong>0)
			pi pr  = chinese_remainder_theorem(xv,av);
			if(pr.second == -1)
			{
				VI tempxv,tempav;
				for (irow = 0; irow < crow; irow += 1)
				{
					tempxv.pb(p[i+irow][jend]);
					tempav.pb(p[i+irow][jend]-a[i+irow][jend]);
				}
				pi pr = chinese_remainder_theorem(tempxv,tempav);
				if(pr.second== -1)
				{
					vector<pi > xv;
					for (irow = 0; irow < crow; irow += 1)
					{
						xv.pb(mp(p[i+irow][jend],p[i+irow][jend]-a[i+irow][jend]));
					}
					sort(xv.begin(),xv.end());
					pi pr = chinese_remainder_theorem(xv);
					if(pr.second == -1)
					{
						out[co++] = mo(i+irow,jend,i+irow,jend,pr.first + p[i+irow][jend]-a[i+irow][jend]);
					}
				}
			}
			//if(change > maxchange)
			//	co = prevco;
		
			//pi pr = chinese_remainder_theorem(xv,av);
			if(pr.second==-1 && jbegin == jend)
			{
				for (irow = 0; irow < crow; irow += 1)
				{
					if(a[i+irow][jbegin]!=0)
						out[co++] = mo(i+irow,jbegin,i+irow,jend,p[i+irow][jbegin]-a[i+irow][jbegin]);
				}
					//out[co++] = mo(i+1,jbegin,i+1,jend,p[i+1][jbegin]-a[i+1][jbegin]);
				jbegin++;
				jend++;
				xv.clear();
				av.clear();
				continue;
			}
			if((pr.second == -1))
			{
				out[co++] = mo(i,jbegin,i+crow-1,jend-1,apr[i][jend-1].first);
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
			out[co++] = mo(i,jbegin,i+crow-1,jend-1,apr[i][jend-1].first);
			xv.clear();
			av.clear();
		}
		i+=crow;
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
	solve1();
	assert(co>=0 && co<=n*m);

	printf("%lld\n",co);
	for(i = 0;i < co;i++)
	{
		printf("%lld %lld %lld %lld %lld\n",out[i].x1,out[i].y1,out[i].x2,out[i].y2,out[i].k);
	}

	return 0;
}


