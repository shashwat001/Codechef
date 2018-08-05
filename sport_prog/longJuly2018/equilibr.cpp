#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>

using namespace std;
typedef long long int lli;

int MOD = 1000000007;

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
    int n,k;
    scanf("%d", &n);
    scanf("%d", &k);

    
    int val,x;
    x = power(2, n-1);
    val = (x - n + MOD)%MOD;
    val = ((lli)val*power(x, MOD-2))%MOD;

    printf("%d", val);
    return 0;
}
