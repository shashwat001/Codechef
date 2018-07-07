#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <sys/time.h>
#include <unistd.h>
#include <chrono>

#define S1(n) scanf("%d", &n)
#define S2(a,b) scanf("%d %d", &a, &b)
#define MOD 163577857
#define SIZE 100

using namespace std;

class Solution
{
public:
    void solve()
    {
        int n,a,b,ca = 0, cb = 0;
        scanf("%d %d %d", &n, &a, &b);
        for(int i = 0;i < n;i++)
        {
            int k;
            S1(k);
            ca += a==k?1:0;
            cb += b==k?1:0;
        }
        printf("%lf\n", (double)ca/n*(double)cb/n);
    }
};

int main()
{
    int t;
    S1(t);
    while(t--)
    {
        Solution().solve();
    }
}
