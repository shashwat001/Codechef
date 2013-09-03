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
	int n,i;
	char s[2060];
	scanf("%d",&n);
	scanf("%s",s);
	int l = strlen(s);
	int c = 0;
	for(i = n;i < l;i+=n)
	{
		if(s[i-1]==s[i-2] && s[i-2]==s[i-3])
		{
			c++;
		}
	}
	printf("%d",c);
	return 0;
}
