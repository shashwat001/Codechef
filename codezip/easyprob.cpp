#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <complex>
#include <string.h>
#include <assert.h>
 
 
using namespace std;
 
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define it(i,v) __typeof(v.begin()) i;
#define set(a,val) memset(a,val,sizeof(a))
#define rep(i,a,b) for(__typeof(a) i = (a); i < (b) ; i++)
#define rev(i,a,b) for(__typeof(a) i = (a); i >= (b) ; i--)
#define max(a,b) (a) > (b) ? (a) : (b)
#define min(a,b) (a) < (b) ? (a) : (b)
#ifdef LOCAL
#define trace(a)	cerr << #a << " -> " << a << "\t";
#define debug1(a)	{trace(a);cerr << endl;}
#define debug2(a,b)	{trace(a);trace(b);cerr << endl;}
#define debug3(a,b,c)	{trace(a);trace(b);trace(c);cerr << endl;}
#define debug4(a,b,c,d)	{trace(a);trace(b);trace(c);trace(d);cerr << endl;}
#else
#define debug1(args...);
#define debug2(args...);
#define debug3(args...);
#define debug4(args...);
#endif
 
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long LL;




int key(int k,int p) {
	p = 1 << (p-1);
	int r = 0;
	while(k) {
		if(k & 1) r += p;
		p >>= 1;
		k >>= 1;
	}
	return r;
}


void FFT(vector < int > &A,int s) {
	int n = A.size();
	int p = 0;
	while(n > 1) p++,n >>= 1;
	n = 1 << p;
	vector < int > aa(A);
	rep(i,0,n) A[key(i,p)] = aa[i];
	int w,wn,t,u;
	int m,r;
	rep(i,1,p+1) {
		m = 1 << i;
		r = m >> 1;
		wn = (int)( cos(s*2*M_PI/(double)m), sin(s*2*M_PI/(double)m) );
		w = 1.0;
		rep(j,0,r){
			for(int k = j; k < n ; k += m) {
				t = w * A[k + r];
				u = A[k];
				A[k] = u + t;
				A[k + r] = u - t;
			}
			w = w * wn;
		}
	}
	if(s==-1){
   	for(int i = 0;i<n;++i)
         A[i] /= n;
 	}
}
 
vector< int > Multiply(vector< int > &P, vector< int > &Q){
	int n = P.size()+Q.size();
	int p = 1;
	while(p < n) p <<= 1;
	n = p;
	P.resize(n,0);
	Q.resize(n,0);
	FFT(P,1);
	FFT(Q,1);
	vector< int > R;
	for(int i=0;i<n;i++) R.push_back(P[i]*Q[i]);
	FFT(R,-1);
	return R;
}


char sa[400000],sb[300004];
int main()
{
	int i;
	vector<int> a,b;
	scanf("%s %s",sa,sb);
	int la = strlen(a);
	int lb = strlen(b);
	for(i = 0;i < la;i++)
	{
		a.pb(sa[i]-'0');
	}
	for(i = 0;i < lb;i++)
	{
		b.pb(sb[i]-'0');
	}
	
	vector<int> ret = Multiply(a,b);
	for(i = 0;i < ret.size();i++)
	{
		printf("%d",ret[i]);
	}
	return 0;
}
 
