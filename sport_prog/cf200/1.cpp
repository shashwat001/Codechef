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
	int n;
	int count = 1,i;
	char s[4],lastl;
	scanf("%d",&n);
	for(i = 0;i < n;i++)
	{
		scanf("%s",s);
		if(i!=0)
		{
		if(s[0]==lastl)
		{
			count++;

		}
		}
		lastl = s[1];
	}
	printf("%d",count);
	return 0;
}
