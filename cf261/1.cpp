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
	int x[4],y[4];
	int d;
	scanf("%d %d %d %d",&x[0],&y[0],&x[1],&y[1]);
	if(x[0]==x[1])
	{
		d = abs(y[1]-y[0]);
		int f = -1;
		if(x[0]+d <=1000)
		{
			f = 1;
		}
		x[2] = x[0]+f*d;
		x[3] = x[2];
		y[2] = y[0];
		y[3] = y[1];
	}
	else if(y[0] == y[1])
	{
		d = abs(x[1]-x[0]);
		int f = -1;
		if(y[0]+d <=1000)
		{
			f = 1;
		}
		y[2] = y[0]+f*d;
		y[3] = y[2];
		x[2] = x[0];
		x[3] = x[1];
	}
	else if(abs(x[1]-x[0]) != abs(y[1]-y[0]))
	{
		printf("-1");
		return 0;
	}
	else
	{
		x[2] = x[0];
		x[3] = x[1];
		y[2] = y[1];
		y[3] = y[0];
	}
	for(int i = 2;i <= 3;i++)
	{
		printf("%d %d ",x[i],y[i]);
	}
	return 0;
}
