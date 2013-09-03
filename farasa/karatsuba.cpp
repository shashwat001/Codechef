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

void karatsuba(int *a,int *b,int n,int res[])
{
	int mid = (n)/2;
	if(n<=2)
	{
		res[0] = a[0]*b[0];
		res[1] = a[1]*b[0] + a[0]*b[1];
		res[2] = a[1]*b[1];
		return;
	}
	int resl[20010],resr[20010],resm[20010];
	int diffp[10010],diffq[10010];
	karatsuba(a+mid,b+mid,n-mid,resl);
	karatsuba(a,b,mid-1,resr);
	for(i = mid;i < n;i++)
	{
		diffp[i-mid] = a[i] - a[i-mid];
		diffq[i-mid] = b[i] - b[i-mid];
	}
	karatsuba(diffp,diffq,n-mid,resm);
	for(i = 0;i < 2n;i++)
	{
		res[i] += resr[i];
		res[i+mid] += resr[i]+resl[i] - resm[i];
		res[i+n] += resl[i];
	}	
}

int main ()
{
	int n,res[200000],i,a[100005],b[100005];
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i = 0;i < n;i++)
	{
		scanf("%d",&b[i]);
	}
	karatsuba(a,b,n,res);
	return 0;
}
