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

int hash[1000004];

int main ()
{
	int t,k,L,i;
	char s[1000004];
	scanf("%d",&t);
	while(t--)
	{
		int ln = 0;
		scanf("%s %d %d",s,&k,&L);
		int l = strlen(s);
		fill(hash,hash+l,0);
		i = 0;
		while(i < l)
		{
			char c = s[i];
			int cnt = 0;
			while(s[i]==c)
			{
				i++;
				cnt++;
			}

			ln+=min(cnt,k);
			cnt -=k;
			if(cnt>0)
			{
				int q = (cnt)/k;
				int r = cnt%k;
				hash[r]++;
				hash[k]+=q;
			}
		}
		if(ln>=L)
		{
			cout<<L<<endl;
			continue;
		}
		ln = L-ln;
		for(i = k;i>0;i--)
		{
			int ml = hash[i]*i;
			if(ml>=ln)
			{
				int c = (ln)/i;
				if(ln%i != 0)
					c++;
				L+=c;
				cout<<L<<endl;
				break;
			}
			else
			{
				ln -= ml;
				L+=hash[i];
			}
		}
	}
	return 0;
}
