#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

#define INF 100000000
#define LLINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef unsigned int uint;
typedef unsigned long long int ulli;
typedef pair<int,int> pairint;

int s[1000003],t[1000003];
int h[1000003] = {0};

int main()
{
	int n,m;
	cin>>n;
	int i,j;
	for(i = 1;i <=n;i++)
	{
		cin>>m;
		if(m >= i)
		{
			h[m]++;
		}
		
	}
	for(i = n;i >= 0;i--)
	{
		cin>>m;
		if(m >= i)
		{
			rh[m]++;
		}
	}
	s[0] = 0;
	for(i = 1;i <=n;i++)
	{
		s[i] = s[i-1]+h[i];
	}
	t[n+1] = 0;
	for(i = n;i > 0;i--)
	{
		t[i] = t[i+1]+h[i];
	}
	i = 0;j = n;
	lli sum = 0;
	while(i < j)
	{
		if(s[i] > t[j])
		{
			sum+=(lli)(j-i);
			j--;
		}
		else
		{
			i++;
		}
	}
	cout<<sum;
	return 0;
}
