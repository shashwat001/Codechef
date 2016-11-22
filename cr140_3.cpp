#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <list>

using namespace std;

#define INF 2147483647
#define LLINF 9223372036854775807
#define make_pair mp
#define push_back pb

typedef long long int lli;
typedef unsigned int uint;
typedef unsigned long long int ulli;
typedef pair<int,int> pairint;

int i,j;

int main()
{
	long long int n,m,res = 1,a[32];
	cin>>n>>m;
	a[0] = 3;
	for(i = 1;i < 32;i++)
	{
		a[i] = (a[i-1]*a[i-1])%m;
	}
	i = 0;
	while(n>0)
	{
		if(n&1)
			res = (res*a[i])%m;
		n = n>>1;
		i++;
		
	}
	if(res==0)
		cout<<m-1;
	else
	cout<<(res-1)%m;
	return 0;
}
