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
#define MOD7 1000000007

typedef long long int lli;
typedef pair<int,int> pi;

lli modmulinverse(lli a,lli m)
{
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
lli f[2000100],n,m,res;
int main ()
{
	int t,i;
	
	cin>>t;
	f[0] = 1;
	for(i = 1;i <= 2000004;i++)
	{
		f[i] = (f[i-1]*i)%MOD7;
	}
	while(t--)
	{
		cin>>n>>m;
		n--,m--;
		if(n==0||m==0)
		{
			cout<<1<<endl;
			continue;
		}
		res = (f[n+m]*modmulinverse(f[n],MOD7))%MOD7;
		res = res*modmulinverse(f[m],MOD7);
		cout<<res%MOD7<<endl;
	}
	return 0;
}
