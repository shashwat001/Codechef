#include <iostream>
#include <vector>
#include <algorithm>

typedef long long int lli;
lli MOD = 5;

using namespace std;

lli prodv = 1;


void findcombin(vector<lli> &a, int k, int cidx, int cnt, vector<int> &idxs)
{
    if(cnt == k)
    {
        for(int i = 1;i <= k-2;i++)
        {
            prodv = (prodv*a[idxs[i]])%MOD;
        }
        return;
    }

    if(cidx >= a.size())
        return;

    for(int i = cidx;i < a.size();i++)
    {
        idxs[cnt] = i;
        findcombin(a, k, i+1, cnt+1, idxs);
    }
}

int main()
{
    int a,b, t;

    scanf("%d", &t);
    while(t--)
    {
        int n,k;

        scanf("%d %d", &n,&k);

        vector<lli> a(n);
        for(int i = 0;i < n;i++)
        {
            scanf("%lld", &a[i]);
        }

        sort(a.begin(), a.end());
        prodv = 1;
        vector<int> idxs(k);
        findcombin(a, k, 0, 0, idxs);

        printf("%lld\n", prodv);
    }
    return 0;
}
