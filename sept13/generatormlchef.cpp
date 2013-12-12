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

int main ()
{
	int i;
	srand(time(NULL));
	int n = rand()%10+1;
	printf("%d\n",n);
	for(i = 1;i <= n;i++)
	{
		int sup = rand()%i;
		int wt = rand()%100+1;
		printf("%d %d\n",wt,sup);
	}
	int q = rand()%10+1;
	printf("%d\n",2*q);
	for(i = 0;i < q;i++)
	{
		int node = rand()%(n+1);
		int X = rand()%30;
		printf("1 %d %d\n",node,X);
		printf("2 %d\n",node);
	}
	return 0;
}
