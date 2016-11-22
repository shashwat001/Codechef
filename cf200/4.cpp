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
	stack<char> s;
	int i,n;
	char a[1000000];
	scanf("%s",a);
	n = strlen(a);
	for(i = 0;i < n;i++)
	{
		if(s.empty())
		{
			s.push(a[i]);
			continue;
		}
		else
		{
			char c = s.top();
			if(a[i] == c)
				s.pop();
			else
				s.push(a[i]);
		}
	}
	if(s.empty())
		printf("YES");
	else
		printf("NO");
	return 0;
}
