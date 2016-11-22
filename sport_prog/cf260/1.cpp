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

int main()
{
	int n;
	scanf("%d",&n);
	pairint p[n];
	for(int i = 0;i < n;i++)
	{
		scanf("%d %d",&p[i].first,&p[i].second);
	}
	sort(p,p+n);
	for(int i = 1;i < n;i++)
	{
		if(p[i].second <= p[i-1].second)
		{
			printf("Happy Alex");
			return 0;
		}
	}
	printf("Poor Alex");
	return 0;
}
