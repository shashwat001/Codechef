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
bool comp(list<pi > first, list<pi > second)
{
	return (first.first > second.first);
}

bool compeq(list<pi > first, list<pi > second)
{
	return first.second < second.second;
}
int main ()
{
	int n,i,j,k;
	float f;
	cin>>n;
	for(i = 0;i < n;i++)
	{
		cin>>f;
		int k = (int)(f*1000);
		k = k%1000;
		if(k < 500 && k!=0)
		{
			less.pb(mp(k,i));
		}
		else if(k == 500 || k==0)
		{
			equal.pb(mp(k,i));
		}
		else
		{
			more.pb(mp(k,i));
		}
	}
	less.sort();
	more.sort(comp);
	equal.sort(compeq);
	for(it = less.begin();it != less.end();)
	{
		for(it1 = more.begin();it1!=more.end();it1++)
		{
			if(it->second < it1->second )
			{
				sum+=it->first + 1000-it1->first;
				it = less.erase(it);
				it1 = more.erase(it1);
				break;
			}
		}
		if(it1==more.end())
		{
			it++;
		}
	}
	if(!more.empty())
		it1 = more.begin();
	else it1 = more.end();
	if(!less.empty())
		it = less.begin();
	else it = less.end();
		
	while(it1 != more.end() && it != less.end())
	{
		if(it->first < 1000-it1->first)
		{		
			list<pi >::iterator eqit;
			eqit = equal.begin();
			while(eqit != equal.end())
			{
				if(it.second < eqit.second)
				{
					sum+=it->first + (1000-eqit->first)%1000;
					it = less.erase(it);
					eqit = more.erase(eqit);
					break;
				}
			}
	}
	
	return 0;
}
