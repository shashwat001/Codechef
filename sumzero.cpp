/*The length of longest subarray whose sum of elements is zero when array contains only 1, -1 and zero only. */

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

int longestSubstring (string a) {
	int i,l,sumc = 0,maxm = -1;
	set<pair<int,int> > setp;
	set<pair<int,int> >::iterator it;
    string s(a);
	l = s.size();
	cout<<l<<endl;
	for(i = 0;i < l;i++)
	{
		switch(s[i])
		{
			case 'a':
				sumc += -1;
				break;
			case 'b' :
				sumc+=1;
				break;
			case 'c' :
				sumc+=0;
				break;
		}
		it = setp.lower_bound(make_pair(sumc,-2));
		if(it!=setp.end())
		{
			if(it->first == sumc)
			{
				int range = i-it->second;
				maxm = max(range,maxm);
			}
		}
		setp.insert(make_pair(sumc,i));
	}
	return maxm;
}
int main ()
{
	string a;
	cin>>a;
	cout<<longestSubstring(a);
	return 0;
}
