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

int a[200][200],preference[200][200];
pi votes[200];

int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		int c,v;
		cin>>c>>v;
		for (unsigned int i = 0; i < c; i += 1)
		{
			votes[i].first = 0;
			votes[i].second = i;
		}
		for(int i = 0;i < v;i++)
		{
			for (unsigned int j = 0; j < c; j += 1)
			{
				cin>>a[i][j];
				a[i][j]--;
				preference[i][a[i][j]] = j;
			}
			votes[a[i][0]].first++;
		}
		if(c==1)
		{
			cout<<1<<" "<<1<<endl;
			continue;
		}
		sort(votes,votes+c);
		if(votes[c-1].first > v/2)
		{
			cout<<votes[c-1].second+1<<" "<<1<<endl;
		}
		else
		{
			int first = votes[c-1].second;
			int second = votes[c-2].second;
			int firstvote = 0,secondvote = 0;
			for(int i = 0;i < v;i++)
			{
				if(preference[i][first]<preference[i][second])
				{
					firstvote++;
				}
				else
					secondvote++;
			}
			if(firstvote>secondvote)
			{
				cout<<first+1<<" "<<2;
			}
			else
				cout<<second+1<<" "<<2;
			cout<<endl;
		}
	}
	return 0;
}
