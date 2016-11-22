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
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef pair<int,int> pi;

lli expo(lli A,lli I, lli M)
{
	lli p = 1,k = A;
	while(I>0)
	{
		if(I&1)
		{
			p = (p*k)%M;
		}
		I >>= 1;
		k = (k*k)%M;
	}
	return p;
}

int main ()
{
	lli t,n,i,j,k,upper,m,d;
	lli mod = 1000000007;
	scanf("%lld",&t);
	while(t--)
	{
		vector<lli> a(50,0);
		scanf("%lld %lld %lld %lld",&upper,&d,&m,&n);
		lli quo = upper/n;
		lli rem = upper%n;
		for(i = 0;i < n;i++)
		{
			lli val = expo(i,d,n);
			a[val]+=quo;
			if(i<=rem)
			{
				a[val]++;
			}
		}

		lli count = 0;
		for(i = 0;i < n;i++)
		{
			for (j = i; j < n; j += 1)
			{
				for (k = j; k < n; k += 1)
				{
					lli p;
					if(((i+j+k)%n) == m)
					{
							if(j==k&&k==i)
							{
								count = (count + (((a[i]*a[j])%mod)*a[k])%mod)%mod;
							}
							else if(j==k && k!=i)
							{
								count = (count + (((((a[i]*a[j])%mod)*a[k])%mod)*3)%mod)%mod;
							}
							else if(i==j && j!=i)
                                                        {
								count = (count + (((((a[i]*a[j])%mod)*a[k])%mod)*3)%mod)%mod;
                                                        }
							else
							{
								count = (count + (((((a[i]*a[j])%mod)*a[k])%mod)*6)%mod)%mod;
							}
					}
				}
			}
		}
		printf("%lld\n",count);
		
	}
	return 0;
}
