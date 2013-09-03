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

if()

void getSuffixArray(char *str)
{
	l = strlen(str);
	for(i = 0;i < l;i++)
	{
		pos[i] = i;
	}
	sort(pos,pos+l,comp);
}

int main ()
{
	char str[1000];
	cin>>str;
	getSuffixArray(str);
	return 0;
}
