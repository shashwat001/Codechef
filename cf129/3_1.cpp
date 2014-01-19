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
	int i,n,flag = 0,a,counta = 0;
	set<int> s;
	int b[100005] = {0};
	set<int>::iterator it,it2;
	cin>>n;
	for (unsigned int i = 0; i < n; i += 1)
	{
		cin>>a;
		if(b[a]>0)
			b[a]++;
		else
		{
			s.insert(a);
			b[a]++;
		}
	}
	while(flag==0)
	{
		if(s.size()<=0)
			break;
		it = s.begin();
		
		int half = (*it)*2;
		it2 = s.lower_bound(half);
		if(it2!=s.end())
		{
			b[*it2]--;
			b[*it]--;
			if(b[*it2]==0)
				s.erase(it2);
			if(b[*it]==0)
				s.erase(it);
			counta++;
		}
		else 
			break;
	}
	cout<<s.size()+counta;
	return 0;
}
