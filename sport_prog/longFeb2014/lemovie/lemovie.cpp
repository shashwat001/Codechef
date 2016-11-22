//shashwat001

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back
#define mod 1000000007

typedef long long int lli;
typedef pair<int,int> pi;

lli modmulinverse(lli a)
{
	lli m=mod;
    lli x = 0,y = 1,u = 1,v = 0; 
    lli e = m,f = a;
    lli c,d,q,r;
    while(f != 1)
    {
        q = e/f;
        r = e%f;
        c = x-q*u;
        d = y-q*v;
        x = u;
        y = v;
        u = c;
        v = d;
        e = f;
        f = r;
    } 
    u = (u+m)%m;
    return u;
}


int main ()
{
	int t,i;
	cin>>t;
	lli fact[300];
	fact[0] = 1;
	for(i = 1;i < 300;i++)
	{
		fact[i] = (i*fact[i-1])%mod;
	}
	while(t--)
	{
		lli w[300][300] = {{0}};
		lli n,k,i,temp;
		lli a[300];
		lli ca = 0;
		//memset(w,0,sizeof(w));
		cin>>n>>k;
		lli arr[300] = {0};
		for(i = 1;i <= n;i++)
		{
			cin>>temp;
			if(arr[temp] == 0)
			{
				a[++ca] = temp;
			}
			arr[temp]++;			
		}
		a[0] = 0;
		n = ca;
		k = min(k,n);
		sort(a+1,a+n+1,greater<lli>());
		
		lli cnt[300] = {0};
//		for(i = 0;i <= n;i++)
//		{
//			for (unsigned int j = 0; j <= k; j += 1)
//			{
//					w[i][j] = 0;
//			}
//		}
		w[0][0] = 1;
		for(i = 1;i <= n;i++)
		{
			for (unsigned int j = 1; j <= k; j += 1)
			{
				lli r = arr[a[i]];
				lli s = cnt[i-1];
				lli all = (fact[s+r]*modmulinverse(fact[s]))%mod;
				lli firstplace = (r*(fact[s+r-1]))%mod;
				firstplace = (firstplace*modmulinverse(fact[s]))%mod;
				lli secondplace = (all-firstplace+mod)%mod;
				
				w[i][j] = (secondplace*w[i-1][j])%mod;
				w[i][j] = (w[i][j] + firstplace*w[i-1][j-1])%mod;
			}
			cnt[i] = cnt[i-1]+arr[a[i]];
		}
		lli sum = 0;
	
		for(i = 1;i <= k;i++)
		{
			sum = (sum+w[n][i])%mod;
		}
		
		cout<<sum<<endl;
		
	}
	return 0;
}
