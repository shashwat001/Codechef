// copied solution from contest for testing purpose.
# include <bits/stdc++.h>
using namespace std;
# define FOR(i, a, b) for (int i = a; i <= b; ++i)
# define FDR(i, a, b) for (int i = a; i >= b; --i)
# define mp make_pair
# define pb push_back
# define lch p<<1, l, mid
# define rch p<<1|1, mid + 1, r
# define mem(a, b) memset(a, b, sizeof(a))
# define fi first
# define se second
# define MOD 1000000007
# define INF 1000000000
typedef long long i64;
typedef vector<int> VI;
typedef pair<int, int> PII;
const int N = 1000005;

VI fac;
int n, C;
int ans[N], now;

void init() {
    fac.clear();
    int sqr = (int)sqrt(C + 0.5);
    FOR(i, 1, sqr) {
        if (C % i) continue;
        fac.pb(i);
        if (i != C / i) fac.pb(C / i);
    }
    sort(fac.begin(), fac.end());
}
bool check(int x) {
    now = 0;
    int p = C;
    while (now < n) {
        if (p == 1) return true;
        // find the largest factor of p.
        while (p % fac[x]) --x;
        // p is divisible by fac[x]
        p /= fac[x];
        ans[now + 1] = fac[x] + n - now - 1;
        ++now;
        if (x != (int)fac.size() - 1 && fac[x + 1] == fac[x] + 1) ++x;
    }
    return p == 1;
}
int main ()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &C);
        init();
        int r = (int)fac.size(), res;
        FDR(i, r - 1, 0) if (check(i)) res = i;
        check(res);
        FOR(i, now + 1, n) ans[i] = 1 + n - i;
        FDR(i, n, 1) printf(i == n ? "%d" : " %d", ans[i]);
        puts("");
    }
    return 0;
}
