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

typedef long long int lli;
typedef pair<int,int> pi;

int main ()
{
	int m,i,x,y,tot=0,a[100000];
	scanf("%d",&m);
	for(i = 0;i < m;i++)
	{
		scanf("%d",&a[i]);
		tot+=a[i];
	}
	scanf("%d %d",&x,&y);
	int sum = 0;
	for(i = 0;i < m;i++)
	{
		sum+=a[i];
		if(sum>=x && sum<=y && (tot-sum)>=x && (tot-sum)<=y)
		{
			printf("%d",i+2);
			return 0;
		}
	}
	printf("0");
	return 0;
}
