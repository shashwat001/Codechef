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
	int t;
	cin>>t;
	while(t--)
	{
		char s1[100090],s2[100090];
		int i;
		cin>>s1;
		cin>>s2;
		int l1 = strlen(s1);
		int l2 = strlen(s2);
		
		int cnt1[30] = {0},cnt2[30] = {0};
		i = 0;
		while(i < l1)
		{
			char c = s1[i];
			int cnt = 0;
			while(i < l1 && s1[i]==c)
			{
				i++;
				cnt++;
			}
			cnt1[c-'a'] = max(cnt,cnt1[c-'a']);
		}
		i = 0;
		while(i < l2)
		{
			char c = s2[i];
			int cnt = 0;
			while(i < l2 && s2[i]==c)
			{
				i++;
				cnt++;
			}
			cnt2[c-'a'] = max(cnt,cnt2[c-'a']);
		}
		int maxval = -1;
		for(i = 0;i < 26;i++)
		{
			maxval = max(cnt1[i]+cnt2[i],maxval);
		}
		cout<<maxval<<endl;
	}
	return 0;
}
