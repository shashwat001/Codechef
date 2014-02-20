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

#define INF 100000000
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef pair<int,int> pi;
typedef vector<int> VI;
typedef pair<int,int> PII;

class oformat
{
	public:
	lli x1,y1,x2,y2,k;
};

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
  if (a%d != b%d) return make_pair(a%d - b%d,-1);
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
vector<oformat> out[5];
lli co = 0,co2 = 0;
pi apr[200][200];
int optval[200][200],optidx[200][200];
int ans[200][200];
void get(int beg,int end,int row)
{
	if(optval[beg][end]==0)
		return;
	if(optidx[beg][end]==beg)
	{
		out[2].pb(mo(row,beg,row,end,ans[beg][end]));
		return ;	
	}
	get(beg,optidx[beg][end]-1,row);
	get(optidx[beg][end],end,row);
}


void solve1()
{
	lli i = 1;
	VI av,xv;
	while(i <= n)
	{
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
		i+=1;
	}
}

void solve2()
{
	lli i = 1;
	VI av,xv;
	while(i <= m)
	{
		lli jbegin,jend;
		jbegin = jend = 1;
		while(jend<=n)
		{
			if(jbegin == jend  &&  a[jend][i] == 0)
			{
				jbegin++;
				jend++;
				continue;
			}
			xv.pb(p[jend][i]);
			av.pb(p[jend][i]-a[jend][i]);
			pi pr = chinese_remainder_theorem(xv,av);
			if((pr.second == -1) || (jend-jbegin)>10)
			{
				out[1].pb(mo(jbegin,i,jend-1,i,apr[jend-1][i].first));
				jbegin = jend;
				xv.clear();
				av.clear();
				continue;
			}
			apr[jend][i] = pr;
			jend++;
			
		}
		if(jbegin<=n)
		{
			out[1].pb(mo(jbegin,i,jend-1,i,apr[jend-1][i].first));
			xv.clear();
			av.clear();
		}
		i++;
	}
}


//int main ()
//{
//	cin>>n>>m;
//	for(i = 1;i <= n;i++)
//	{
//		for (j = 1; j <= m; j += 1)
//		{
//			cin>>p[i][j];
//		}
//	}
//	for(i = 1;i <= n;i++)
//	{
//		for (j = 1; j <= m; j += 1)
//		{
//			cin>>a[i][j];
//		}
//	}
//	for(i = 0;i < 200;i++)
//		for(j = 0;j < 200;j++)
//			apr[i][j] = mp(0,0);
//	solve1();
//	for(i = 0;i < 200;i++)
//	{
//		for(j = 0;j < 200;j++)
//			apr[i][j] = mp(0,0);
//	}
//	solve2();
//	for(i = 0;i < 200;i++)
//	{
//		for(j = 0;j < 200;j++)
//			apr[i][j] = mp(0,0);
//	}
//	solve3();
//	vector<oformat> final;
//	int size = INF;
//	int algos  = 3;
//	for(i = 0;i < algos;i++)
//	{
//		if((int)out[i].size()<size)
//		{
//			size = out[i].size();
//			final = out[i];
//		}
//			
//	}
//	printf("%u\n",final.size());
//	for(i = 0;i < final.size();i++)
//	{
//		printf("%lld %lld %lld %lld %lld\n",final[i].x1,final[i].y1,final[i].x2,final[i].y2,final[i].k);
//	}

//	return 0;
//}

int main()
{
	VI xv,av;
	xv.pb(6);
	xv.pb(12);
	av.pb(5);
	av.pb(2);
	pi pr = chinese_remainder_theorem(xv,av);
	cout<<pr.first<<endl;
	return 0;
}
