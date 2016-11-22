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
	int n,a[100001],m;
	long long b = 0,c = 0;
	cin>>n;
	for(i = 0;i < n;i++)
	{
		cin>>j;
		a[j-1] = i;
	}
	cin>>m;
	for(i = 0;i < m;i++)
	{
		cin>>j;
		b+=a[j-1]+1;
		c+=n-a[j-1];
	}
	cout<<b<<" "<<c;
	return 0;
}
