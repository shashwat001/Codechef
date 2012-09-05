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
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef unsigned int uint;
typedef unsigned long long int ulli;
typedef pair<int,int> pairint;

int i,j,pcount = 0;
pair<int,int> p[400001];

void insert(int n)
{
	int cnt = pcount,precnt;
	if(p[cnt].second == 0)
	{
		p[cnt].second = n;
		while(cnt > 0)
		{
			precnt = (cnt-1)/2;
			if(p[precnt].second < p[cnt].second)
			{
				temp = p[precnt].second;
				p[precnt].second = p[cnt].second;
				p[cnt].second = temp;
			}
			cnt = precnt;
		}
	}
	else
	{
		pcount++;
		cnt++;
		p[cnt].first = n;
		while(cnt > 0)
		{
			precnt = (cnt-1)/2;
			if(p[precnt].first > p[cnt].first)
			{
				temp = p[precnt].second;
				p[precnt].second = p[cnt].second;
				p[cnt].second = temp;
			}
			cnt = precnt;
		}
	}
}

int main()
{
	int n,Min,Max,a[400001],w,ways = 0;
	scanf("%d",&n);
	scanf("%d",&w);
	scanf("%d",&a[0]);
	Min = Max = a[0];
	p[0] = mp(Min,Max);
	printf("%d",p[1].first);

	return 0;
}
