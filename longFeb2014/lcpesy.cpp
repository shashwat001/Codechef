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
	int t,i;
	scanf("%d",&t);
	char s1[10004],s2[10004];
	while(t--)
	{
		int c1[300] = {0},c2[300] = {0};
		cin>>s1>>s2;
		int l1 = strlen(s1);
		int l2 = strlen(s2);
		for(i = 0;i < l1;i++)
		{
			c1[(unsigned int)s1[i]]++;
		}
		for(i = 0;i < l2;i++)
		{
			c2[(unsigned int)s2[i]]++;
		}
		int sum = 0;
		for(i = 0;i < 256;i++)
		{
			sum+=min(c1[i],c2[i]);
		}
		cout<<sum<<endl;
	}
	return 0;
}
