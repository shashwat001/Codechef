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
	int n = 1;
	int i,j;
	char s[500005];
	printf("%d\n",n);
//	for(i = 0;i < n;i++)
//	{
		for(j = 0;j < 500;j++)
		{
			s[j] = rand()%26+97;
		}
		s[j] = '\0';
		printf("%s\n",s);
//	}
	return 0;
}
