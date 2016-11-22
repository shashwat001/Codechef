#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <sstream>
#include <numeric>
#include <functional>
#include <set>
#include <cmath>
#include <stack>
#include <fstream>
#ifdef HOME_PC
#include <ctime>
#endif
using namespace std;
 
#pragma comment(linker,"/stack:16000000")
#pragma warning (disable : 4996)
 
#define ALL(v) v.begin(),v.end()
#define SZ(v) (int)v.size()
#define mset(A,x) memset((A),(x),sizeof(A))
#define FOR(i,start,N) for(int i=(start);i<(N);++i)
#define FORSZ(i,start,v) FOR(i,start,SZ(v))
#define REPSZ(i,v) FORSZ(i,0,v)
#define FORE(i,start,N) FOR(i,start,N+1)
#define make_unique(v) v.resize(unique(ALL(v))-v.begin())
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define adebug(A,N) FOR(i,0,N) cout<<#A<<"["<<i<<"] = "<<A[i]<<endl;
#define adebug2d(a,n,m) FOR(i,0,n) { FOR(j,0,m) { cout<<a[i][j]<<" ";} cout<<endl;}
#define vdebug(v) REPSZ(i,v) cout<<#v<<"["<<i<<"] = "<<v[i]<<endl;
#define selfx(x,f,a) x = f(x,a)
#define sqr(x) ((x)*(x))
 
 
typedef pair<int,int> pii;
typedef long long i64;
typedef vector<int> VI; typedef vector< vector<int> > VVI;
typedef vector<string> VS;
 
const int inf = 1<<25;
const double eps = 1e-9;
 
int di[] = {-2,-2,2,2};
int dj[] = {-2,2,-2,2};
 
const int MAXN = 701;
 
char board[MAXN][MAXN];
 
int n,m;
 
pii fnd()
{
	pii ret(-1,-1);
	int best_result = 10;
	FOR(i,0,n)
		FOR(j,0,m)
		if(board[i][j] != '#')
		{
			int cnt = 0;
			FOR(k,0,4)
			{
				int ni = i +di[k];
				int nj = j + dj[k];
				if(ni < 0 || nj < 0 || ni >= n || nj >= m || board[ni][nj] == '#')
					continue;
				++cnt;
			}
 
			if(cnt < best_result)
			{
				best_result = cnt;
				ret = pii(i,j);
			}
		}
	return ret;
}
 
void place(pii& pos)
{
	int i = pos.first, j = pos.second;
	board[i][j] = '#';
	FOR(k,0,4)
	{
		int ni = i +di[k];
		int nj = j + dj[k];
		if(ni < 0 || nj < 0 || ni >= n || nj >= m)
			continue;
		board[ni][nj] = '#';
	}
}
 
 
int f(int i,int j)
{
	if(j >= m)
	{
		j = 0;
		++i;
	}
	if(i>=n) return 0;
	int ret = f(i,j+1);
	string a(4,' ');
	FOR(k,0,4)
	{
		int ni = i +di[k];
		int nj = j + dj[k];
		if(ni < 0 || nj < 0 || ni >= n || nj >= m)
			continue;
		a[k] = board[ni][nj];
		board[ni][nj] = '#';
	}
	ret = max(ret,1+f(i,j+1));
	FOR(k,0,4)
	{
		int ni = i +di[k];
		int nj = j + dj[k];
		if(ni < 0 || nj < 0 || ni >= n || nj >= m)
			continue;
		board[ni][nj] = a[k];
	}
	return ret;
}
 
pii G2B[MAXN][MAXN];
int color[MAXN][MAXN];
int curcolor = 0;
 
int dfs(pii X)
{
	int i = X.first, j = X.second;
	if(color[i][j] == curcolor || board[i][j] == '#')
		return 0;
	color[i][j] = curcolor;
	FOR(k,0,4)
	{
		int ni = i +di[k];
		int nj = j + dj[k];
		if(ni < 0 || nj < 0 || ni >= n || nj >= m || board[ni][nj] == '#')
			continue;
		if(G2B[ni][nj].first == -1 || dfs(G2B[ni][nj]))
		{
			G2B[ni][nj] = pii(i,j);
			return 1;
		}
	}
	return 0;
}
 
int max_match()
{
	mset(G2B,-1);
	mset(color,-1);
	int ans = 0;
	FOR(i,0,n)
		FOR(j,0,m)
		if((i+j)&1)
		{
			++curcolor;
			ans+=dfs(pii(i,j));
		}
	return ans;
}
 bool inlimit(int i,int j)
{
	if(i >=0 && i < n && j >=0 && j < m)
			return true;
	return false;
}
int main(int argc, char* argv[])
{
#ifdef HOME_PC
	//freopen ("input.txt","r",stdin);
	freopen ("in.txt","r",stdin);
	//freopen ("output.txt","w",stdout);
#endif
	int tt;

		char str[701][701];
		scanf("%d %d",&n,&m);
		while(m || n)
	{
		memset(board,0,sizeof(board));
		for(int i = 0;i < n;i++)
		{
			scanf("%s",str[i]);
		}
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < m;j++)
			{
				if(str[i][j] == 'G')
				{
					board[i][j] = '#';
					if((str[i-1][j-1] != 'P' && str[i-2][j-2]!='P') && inlimit(i-1,j-1)&&inlimit(i-2,j-2))
						board[i-2][j-2] = '#';
					if(str[i+1][j-1] != 'P' && str[i+2][j-2]!='P' && inlimit(i+1,j-1)&&inlimit(i+2,j-2))
						board[i+2][j-2] = '#';
					if(str[i-1][j+1] != 'P' && str[i-2][j+2]!='P' && inlimit(i-1,j+1)&&inlimit(i-2,j+2))
						board[i-2][j+2] = '#';
					if(str[i+1][j+1] != 'P' && str[i+2][j+2]!='P' && inlimit(i+1,j+1)&&inlimit(i+2,j+2))
						board[i+2][j+2] = '#';
				}
				if(str[i][j] == 'P')
				{
					board[i][j] = '#';
				}
			}
		}
 
		int total = 0;
		FOR(i,0,n)
			FOR(j,0,m)
			total+=(board[i][j] != '#');
		int match = max_match();
		printf("%d\n",total - match);
		scanf("%d %d",&n,&m);
	}
#ifdef HOME_PC
	cerr<<endl<<"Execution time = "<<clock()<<" ms"<<endl;
#endif
	return 0;
}
 
