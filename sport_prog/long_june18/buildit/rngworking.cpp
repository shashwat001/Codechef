#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <stack>
#include <cassert>
#include <string.h>
#include <ctime>

#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define sqr(x) (x)*(x)
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define X first
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;

const int mod = 163577857;
//const int mod = 7340033;
struct num {
	int x;
	num():x(0) {}
	num(int x):x(x) {}
	inline num operator+(const num& o) const {
		num res(x+o.x);
		if (res.x >= mod) res.x -= mod;
		return res;
	}
	inline num operator-(const num& o) const {
		num res(x-o.x);
		if (res.x < 0) res.x += mod;
		return res;
	}
	inline num operator*(const num& o) const {
		return num(x*(ll)o.x%mod);
	}
	num pow(ll n) const {
		num res(1);
		num t = *this;
		while (n) {
			if (n&1) res = res * t;
			t=t*t;
			n>>=1;
		}
		return res;
	}
};


//const num root = 5;
//const num root_1 = 4404020;
//const int root_pw = 1<<20;

int inverse(int x, int mod) {
	return ((num(x)).pow(mod-2)).x;
	/*if (x == 1) return 1;
	return (ll)(mod-mod/x) * inverse(mod%x, mod)%mod;*/
}

const num root = 3;

const int MAXBITS = 19;
const int MAXST = 1<<MAXBITS;
int rev[MAXST + 100];
int getrev(int x, int bcnt) {
	int res = 0;
	forn(iter, bcnt) {
		res <<= 1;
		res |= x&1;
		x >>= 1;
	}
	return res;
}


void fft (vector<num>& a, bool invert) {
	int n = (int) a.size();
	int curst = 0;
	while ((1<<curst) < n) curst++;
	for (int i=1, j=0; i<n; ++i) {
		/*int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;*/
		j = rev[i]>>(MAXBITS-curst);
		if (i < j)
			swap (a[i], a[j]);
	}

	for (int len=2; len<=n; len<<=1) {
		num wlen = root.pow((mod-1)/len);
		if (invert) wlen = num(inverse(wlen.x, mod));
		for (int i=0; i<n; i+=len) {
			num w = 1;
			for (int j=0; j<len/2; ++j) {
				num u = a[i+j],  v = a[i+j+len/2]  * w;
				w = w * wlen;
				a[i+j] = u+v;
				a[i+j+len/2] = u-v;

			}
		}
	}
	if (invert) {
		num nrev = num(inverse (n, mod));
		for (int i=0; i<n; ++i)
			a[i] = a[i] * nrev;
	}
}





vector<num> mult(const vector<num>& a, const vector<num>& b) {

	vector<num> va = a;
	vector<num> vb = b;
	while(sz(va) > 1 && va.back().x == 0) va.pop_back();
	while(sz(vb) > 1 && vb.back().x == 0) vb.pop_back();

	int n = max(sz(va), sz(vb));
	int pw = 1;
	while (pw < n) pw <<= 1;
	n = pw;

	va.resize(2*n);
	vb.resize(2*n);
	fft(va, false);
	fft(vb, false);
	forn(i, sz(va)) va[i] = va[i] * vb[i];
	fft(va, true);
	return va;
}


vector<num> mult_square(const vector<num>& a) {
	vector<num> va = a;
	while(sz(va) > 1 && va.back().x == 0) va.pop_back();

	int n = sz(va);
	int pw = 1;
	while (pw < n) pw <<= 1;
	n = pw;

	va.resize(2*n);
	fft(va, false);
	forn(i, sz(va)) va[i] = va[i] * va[i];
	fft(va, true);
	return va;
}

void out(const vector<num>& a) {
	forn(i, sz(a)) printf("%d ", a[i].x);
	printf("\n");
}

vector<num> getinv(vector<num> a) {
	int initialSize = sz(a);
	int pw = 1;
	while (pw <= sz(a)) pw <<= 1;
	a.resize(pw);
	int len = 2;
	vector<num> R(1,num(inverse(a[0].x, mod)));
	while (len <= sz(a)) {
		vector<num> ca(a.begin(), a.begin()+len);


		//vector<num> tmp = mult(R, R);
		vector<num> tmp = mult_square(R);

		tmp = mult(tmp, ca);
		tmp.resize(len);
		forn(i, sz(tmp)) {
			tmp[i] = num(0)-tmp[i];
			if (i < sz(R)) tmp[i] = tmp[i] + R[i]*num(2);
		}
		R = tmp;
		len *= 2;
		//R.resize(len);
	}
	//vector<num> rr = mult(a, R);
	//out(rr);
	R.resize(initialSize);
	return R;
}

vector<num> subtract(const vector<num>& a, const vector<num>& b) {
	int n = max(sz(a), sz(b));
	vector<num> res(n);
	forn(i, n) {
		if (i < sz(a)) res[i] = a[i];
		if (i < sz(b)) res[i] = res[i] - b[i];
	}
	return res;
}

vector<num> IB;


map<int, vector<num> > mem;
vector<num> mult_optimized(const vector<num>& a, const vector<num>& b) {
	int n = max(sz(a), sz(b));
	int pw = 1;
	while (pw < n) pw <<= 1;
	n = pw;
	vector<num> va = a;
	vector<num> vb = b;
	va.resize(2*n);
	vb.resize(2*n);
	fft(va, false);
	if (mem.count(n) == 0) {
		fft(vb, false);
		mem[n] = vb;
	} else vb = mem[n];

	forn(i, sz(va)) va[i] = va[i] * vb[i];
	fft(va, true);
	return va;
}

map<int, vector<num> > mem2;
vector<num> mult_optimized2(const vector<num>& a, const vector<num>& b) {
	int n = max(sz(a), sz(b));
	int pw = 1;
	while (pw < n) pw <<= 1;
	n = pw;
	vector<num> va = a;
	vector<num> vb = b;
	va.resize(2*n);
	vb.resize(2*n);
	fft(va, false);
	if (mem2.count(n) == 0) {
		fft(vb, false);
		mem2[n] = vb;
	} else vb = mem2[n];

	forn(i, sz(va)) va[i] = va[i] * vb[i];
	fft(va, true);
	return va;
}

vector<num> getremainder(const vector<num>& a, const vector<num>& b) {
	vector<num> reva = a;
	while (sz(reva) > 1 && reva.back().x == 0) reva.pop_back();

	if (sz(reva) < sz(b)) return reva;
	reverse(ALL(reva));

	vector<num> revb = b;
	reverse(ALL(revb));
	/*
	vector<num> invb = getinv(revb);*/
	vector<num> invb = IB;


	vector<num> revq = mult_optimized(reva, invb);


	vector<num> q = revq;
	q.resize(sz(reva)-1 - (sz(revb)-1)+1);
	reverse(ALL(q));


	vector<num> r = subtract(a, mult_optimized2(q, b));

	r.resize(sz(b)-1);
	return r;
}

vector<num> mulrem(const vector<num>& a, const vector<num>& b, const vector<num>& rem) {
	vector<num> res = mult(a, b);
	res = getremainder(res, rem);
	return res;
}

vector<num> mulremsquare(const vector<num>& a, const vector<num>& rem) {
	vector<num> res = mult_square(a);
	res = getremainder(res, rem);
	return res;
}

num solvestupid(const vector<int>& C, const vector<int>& A, ll n) {
	vector<num> f(max(sz(C)+1LL,n+1));
    vector<num> S(f.size());
	forn(i, sz(A)) f[i] = num(A[i]);
	for (int i = sz(A); i <= n; ++i) {
		forn(j, sz(C)) f[i] = f[i] + f[i-j-1] * C[j];
	}
    S[0] = f[0];
    for(int i = 1;i < f.size();i++)
    {
        S[i] = S[i-1] + f[i];
    }
	return S[n];
}

num solvesmart(const vector<int>& C, const vector<int>& A, ll n) {
	int k = sz(C);
	if (n < k) {
		return num(A[n]);
	}

	vector<num> rem(k+1);
	rem[k] = 1;
	for (int i = 0; i < k; ++i) rem[k-1-i] = num(0)-C[i];

	vector<num> revb = rem;
	reverse(ALL(revb));
	vector<num> invb = getinv(revb);
	IB = invb;

	vector<num> res(k);
	res[0] = 1;
	vector<num> t(max(k,2));
	t[1] = 1;
	int cc1 = 0;
	int cc2 = 0;
	while (n) {
		if (n&1) {
			res = mult(res, t);
			res = getremainder(res, rem);
		}
		n >>= 1;
		if (n == 0) break;
		t = mult_square(t);
		t = getremainder(t, rem);

	}
	num answer = 0;
	forn(i, k) answer = answer + res[i] * num(A[i]);
	return answer;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	forn(i, MAXST)
		rev[i] = getrev(i, MAXBITS);
	//stress();
	//return 0;

	int k;
	ll n;
	cin >> k >> n;
	--n;
	vector<int> A(k);
	forn(i, k) scanf("%d", &A[i]);
	vector<int> C(k);
	forn(i, k) scanf("%d", &C[i]);

    vector<int> S(k+1), SC(k+1);

    S[0] = A[0];
    for(int i = 1;i < k;i++)
    {
        S[i] = (S[i-1] + A[i])%mod;
        SC[i] = C[i]-C[i-1];
        if(SC[i] < 0)
            SC[i] += mod;
    }
    SC[0] = (1+C[0])%mod;
    SC[k] = mod-C[k-1];

    int last = 0;
    for(int i = 0;i < k;i++)
    {
        last += ((ll)C[i]*A[k-1-i])%mod;
        last = last%mod;
    }
    S[k] = last + S[k-1];

	num answer = solvesmart(SC, S, n);
    num answer1 = solvestupid(C, A, n);
	printf("%d\n%d\n", answer.x, answer1.x);
	return 0;
}
