#pragma GCC optimize ("O3")
#pragma GCC target ("avx")

#include <bits/stdc++.h>


#define home
#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = 1.01e9;
const dbl eps = 1e-9;

/* --- main part --- */

namespace fft
{
    const int maxBase = 17;
    const int maxN = 1 << maxBase;

    struct num
    {
        dbl x, y;
        num(){}
        num(dbl xx, dbl yy): x(xx), y(yy) {}
        num(dbl alp): x(cos(alp)), y(sin(alp)) {}
    };

    inline num operator + (num a, num b) { return num(a.x + b.x, a.y + b.y); }
    inline num operator - (num a, num b) { return num(a.x - b.x, a.y - b.y); }
    inline num operator * (num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
    inline num conj(num a) { return num(a.x, -a.y); }

    const dbl PI = acos(-1);

    num root[maxN];
    int rev[maxN];
    bool rootsPrepared = false;

    void prepRoots()
    {
        if (rootsPrepared) return;
        rootsPrepared = true;
        root[1] = num(1, 0);
        for (int k = 1; k < maxBase; ++k)
        {
            num x(2 * PI / pw(k + 1));
            for (int i = pw(k - 1); i < pw(k); ++i)
            {
                root[2 * i] = root[i];
                root[2 * i + 1] = root[i] * x;
            }
        }
    }

    int base, N;

    int lastRevN = -1;
    void prepRev()
    {
        if (lastRevN == N) return;
        lastRevN = N;
        forn(i, N) rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (base - 1));
    }

    void fft(num *a, num *f)
    {
        forn(i, N) f[i] = a[rev[i]];
        for (int k = 1; k < N; k <<= 1) for (int i = 0; i < N; i += 2 * k) forn(j, k)
        {
            num z = f[i + j + k] * root[j + k];
            f[i + j + k] = f[i + j] - z;
            f[i + j] = f[i + j] + z;
        }
    }

    num a[maxN], b[maxN], f[maxN], g[maxN];
    ll A[maxN], B[maxN], C[maxN];

    void _multMod(int mod)
    {
        forn(i, N)
        {
            int x = A[i] % mod;
            a[i] = num(x & (pw(15) - 1), x >> 15);
        }
        forn(i, N)
        {
            int x = B[i] % mod;
            b[i] = num(x & (pw(15) - 1), x >> 15);
        }
        fft(a, f);
        fft(b, g);

        forn(i, N)
        {
            int j = (N - i) & (N - 1);
            num a1 = (f[i] + conj(f[j])) * num(0.5, 0);
            num a2 = (f[i] - conj(f[j])) * num(0, -0.5);
            num b1 = (g[i] + conj(g[j])) * num(0.5 / N, 0);
            num b2 = (g[i] - conj(g[j])) * num(0, -0.5 / N);
            a[j] = a1 * b1 + a2 * b2 * num(0, 1);
            b[j] = a1 * b2 + a2 * b1;
        }

        fft(a, f);
        fft(b, g);

        forn(i, N)
        {
            ll aa = f[i].x + 0.5;
            ll bb = g[i].x + 0.5;
            ll cc = f[i].y + 0.5;
            C[i] = (aa + bb % mod * pw(15) + cc % mod * pw(30)) % mod;
        }
    }

    void prepAB(int n1, int n2)
    {
        base = 1;
        N = 2;
        while (N < n1 + n2) base++, N <<= 1;
        assert(base <= maxBase);

        for (int i = n1; i < N; ++i) A[i] = 0;
        for (int i = n2; i < N; ++i) B[i] = 0;

        prepRoots();
        prepRev();
    }

    void multMod(int n1, int n2, int mod)
    {
        prepAB(n1, n2);
        _multMod(mod);
    }
}

const int mod = 104857601;

struct poly
{
    vi v;
    poly() {}
    poly(vi vv)
    {
        v = vv;
    }
    int size()
    {
        return (int)v.size();
    }
    poly cut(int maxLen)
    {
        if (maxLen < sz(v)) v.resize(maxLen);
        return *this;
    }
    poly norm()
    {
        while (sz(v) > 1 && v.back() == 0) v.pop_back();
        return *this;
    }
    inline int& operator [] (int i)
    {
        return v[i];
    }
    void out(string name="")
    {
        stringstream ss;
        if (sz(name)) ss << name << "=";
        int fst = 1;
        forn(i, sz(v)) if (v[i])
        {
            int x = v[i];
            int sgn = 1;
            if (x > mod / 2) x = mod-x, sgn = -1;
            if (sgn == -1) ss << "-";
            else if (!fst) ss << "+";
            fst = 0;
            if (!i || x != 1)
            {
                ss << x;
                if (i > 0) ss << "*x";
                if (i > 1) ss << "^" << i;
            }
            else
            {
                ss << "x";
                if (i > 1) ss << "^" << i;
            }
        }
        if (fst) ss <<"0";
        string s;
        ss >> s;
        eprintf("%s\n", s.data());
    }
};

poly operator + (poly A, poly B)
{
    poly C;
    C.v = vi(max(sz(A), sz(B)));
    forn(i, sz(C))
    {
        if (i < sz(A)) C[i] = (C[i] + A[i]) % mod;
        if (i < sz(B)) C[i] = (C[i] + B[i]) % mod;
    }
    return C.norm();
}

poly operator - (poly A, poly B)
{
    poly C;
    C.v = vi(max(sz(A), sz(B)));
    forn(i, sz(C))
    {
        if (i < sz(A)) C[i] = (C[i] + A[i]) % mod;
        if (i < sz(B)) C[i] = (C[i] + mod - B[i]) % mod;
    }
    return C.norm();
}

poly operator * (poly A, poly B)
{
    poly C;
    C.v = vi(sz(A) + sz(B) - 1);

    forn(i, sz(A)) fft::A[i] = A[i];
    forn(i, sz(B)) fft::B[i] = B[i];
    fft::multMod(sz(A), sz(B), mod);
    forn(i, sz(C)) C[i] = fft::C[i];
    return C.norm();
}

poly inv(poly A, int n) // returns A^-1 mod x^n
{
    assert(sz(A) && A[0] != 0);
    A.cut(n);

    auto cutPoly = [](poly &from, int l, int r)
    {
        poly R;
        R.v.resize(r - l);
        for (int i = l; i < r; ++i)
        {
            if (i < sz(from)) R[i - l] = from[i];
        }
        return R;
    };

    function<int(int, int)> rev = [&rev](int x, int m)->int
    {
        if (x == 1) return 1;
        return (1 - rev(m % x, x) * (ll)m) / x + m;
    };

    poly R({rev(A[0], mod)});
    for (int k = 1; k < n; k <<= 1)
    {
        poly A0 = cutPoly(A, 0, k);
        poly A1 = cutPoly(A, k, 2 * k);
        poly H = A0 * R;
        H = cutPoly(H, k, 2 * k);
        poly R1 = (((A1 * R).cut(k) + H) * (poly({0}) - R)).cut(k);
        R.v.resize(2 * k);
        forn(i, k) R[i + k] = R1[i];
    }
    return R.cut(n).norm();
}

auto rev = [](poly f)
{
    reverse(all(f.v));
    return f;
};

pair<poly, poly> divide(poly A, poly B, poly &B1)
{
    if (sz(A) < sz(B)) return {poly({0}), A};


    poly q = rev((B1*rev(A)).cut(sz(A) - sz(B) + 1));
    poly r = A - B * q;

    return {q, r};
}


const int N = 1e5 + 10;

int a[N];
int c[N];

int main()
{

    ll n;
    int k;
    scanf("%d%lld", &k, &n);
    --n;
    forn(i, k) scanf("%d", &a[i]);
    forn(i, k) scanf("%d", &c[i]);

    if (n < k)
    {
        printf("%d\n", a[n]);
        return 0;
    }
    poly f;
    f.v.resize(k + 1);
    forn(i, k) f[i] = (mod - c[k - 1 - i]) % mod;
    f[k] = 1;

    poly f1 = inv(rev(f), k);

    for(int iii = 0;iii < 2000;iii++)
    {

        poly R({1});
        int fst = 0;
        for (int ii = 60; ii >= 0; --ii)
        {
            if (fst) R = divide(R * R, f, f1).S;
            if (n & pw(ii))
            {
                poly T(vi(k, 0));
                forn(i, k - 1) if (i < sz(R)) T[i + 1] = R[i];
                forn(i, k) if (k <= sz(R)) T[k - 1 - i] = (T[k - 1 - i] + R[k - 1] * (ll)c[i]) % mod;
                R = T;
                fst = 1;
            }
        }

        R.v.resize(k);
        int res = 0;
        forn(i, k) res = (res + a[i] * (ll)R[i]) % mod;
        printf("%d\n", res);
    }


    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
