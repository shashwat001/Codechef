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

string createstring(vector<string> vs)
{
	int i;
	string res = "<3";
	int n = vs.size();
	for(i = 0;i < n;i++)
	{
		res += vs[i];
		res += "<3";
	}
	return res;
}
int main ()
{
	int n,i,j,k;
	
	
	cin>>n;
	vector<string> vs(n);
	string s;
	for(i = 0;i < n;i++)
	{
		cin>>vs[i];
	}
	cin>>s;


	string res = createstring(vs);
	int resc = 0;
	int sc = 0;
	while(sc < s.size())
	{
		if(res[resc]==s[sc])
		{
			resc++;
			sc++;
		}
		else
		{
			sc++;
		}
	}
	if(sc==s.size() && resc==res.size())
	{
		printf("yes");
	}
	else
		printf("no");
	return 0;
}
