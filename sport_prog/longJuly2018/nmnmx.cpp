#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>

typedef long long int lli;
int MOD = 1000000007;

using namespace std;

int ncr[5001][5001];

void populatenCr()
{
    for(int i = 1;i <= 5000;i++)
    {
        ncr[i][0] = 1;
        for(int j = 1;j < i;j++)
        {
            ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1])%(MOD-1) ;
        }
        ncr[i][i] = 1;
    }
}

int power(int x, int y)
{
    int val = 1;
    while(y > 0)
    {
        if(y&1)
        {
            val = ((lli)val*x)%MOD;
        }
        y>>=1;
        x = ((lli)x*x)%MOD;
    }
    return val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    populatenCr();
    int  t;

    scanf("%d", &t);
    while(t--)
    {
        int n,k;

        scanf("%d %d", &n,&k);

        vector<int> a(n);
        for(int i = 0;i < n;i++)
        {
            scanf("%d", &a[i]);
        }

        sort(a.begin(), a.end());
        int sumv = 1;
        for(int i = 1;i < n-1;i++)
        {
            int left = i;
            int right = n-1-i;
            int total = ncr[n-1][k-1];
            if(left >= k-1)
            {
                total = (total - ncr[left][k-1] + MOD-1)%(MOD-1);
            }
            if(right >= k-1)
            {
                total = (total - ncr[right][k-1] + MOD-1)%(MOD-1);
            }
            sumv = ((lli)sumv * power(a[i], total))%MOD;
        }
        printf("%d\n", sumv);
    }
    return 0;
}
