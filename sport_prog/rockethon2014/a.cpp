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
	char s[10004];
	cin>>s;
	int l = strlen(s),i,even=0;
	for(i = 0;i < l;)
	{
		int cnt = 0;
		char c = s[i];
		while(s[i]==c)
		{
			cnt++;
			i++;
		}
		if(cnt%2==0)
			even++;
	}
	cout<<even;
	return 0;
}
