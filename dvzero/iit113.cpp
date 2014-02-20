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
	char s[100006];
	int i,k;
	while(t--)
	{
		int n;
		cin>>n;
		cin>>s;
		for(i = 0;i < n;i++)
		{
			cin>>k;
			char temp = s[i];
			s[i] = s[k-1];
			s[k-1] = temp;
		}
		cout<<s<<endl;
	}
	return 0;
}
