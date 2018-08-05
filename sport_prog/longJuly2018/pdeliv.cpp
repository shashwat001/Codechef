#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>

using namespace std;
typedef long long int lli;

int MOD = 1000000007;

int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> s(n),p(n);

    for(int i = 0;i < n;i++)
    {
        cin>>s[i]>>p[i];
    }

    for(int i = 0;i < m;i++)
    {
        int x,k;
        cin>>x>>k;

        vector<int> kn(n,0);
        for(int j = 0;j < k;j++)
        {
            int y;
            cin>>y;
            kn[y-1] = 1;
        }
        lli minm = 1L<<62;
        for(int j = 0;j < n;j++)
        {
            if(kn[j] == 0)
                minm = min(minm, (lli)p[j] + (lli)(s[j]-x)*(s[j]-x));
        }

        cout<<minm<<endl;
    }
    return 0;
}
