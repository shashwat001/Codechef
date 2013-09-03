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

int a[100000][40];

lli find(int A,int I, int M)
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
int main()
{
	int i,n,I,PI,PF,l,r,m,t,x,j;
	vector<int> prime;
	for(i = 2;i <= 100;i++)
	{
		for(j = 2;j < i;j++)
		{
			if(i%j == 0)
				break;
		}
		if(i==j)
			prime.pb(i);
	}

	
	vector<vector<int> > a(101,vector<int>(prime.size()));
	for(i = 1;i <= 100;i++)
	{
		for(j = 0;j < prime.size();j++)
		{
			int k = i;
			int cnt = 0;
			while(k%prime[j]==0)
			{
				cnt++;
				k = k/prime[j];
			}
			a[i][j] = cnt;
		}
	}
	
	

	
	scanf("%d",&n);
	vector<vector<int> > po(n+1,vector<int>(prime.size()));
	for(i = 1;i <= n;i++)
	{
		scanf("%d",&x);
		for(j = 0;j < prime.size();j++)
		{
			po[i][j] = a[x][j]+po[i-1][j];
		}
	}
	
//	for(i = 1;i <= n;i++)
//	{
//		printf("%d: ",i);
//		for(j = 0;j < prime.size();j++)
//		{
//			printf("%d ",po[i][j]);
//		}
//		printf("\n");
//	}
	scanf("%d",&t);
	lli f=1;
	for(i = 0;i < t;i++)
	{
		f = 1;
		scanf("%d %d %d",&l,&r,&m);
		for (unsigned int j = 0; j < prime.size(); j += 1)
		{
			int ex = po[r][j] - po[l-1][j];
			//printf("%d ",ex);
			f = (f*find(prime[j],ex,m))%m;
		}
		printf("%lld\n",f);
		
	}
	return 0;
}
