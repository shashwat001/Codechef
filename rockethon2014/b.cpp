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
	char s[1004];
	cin>>s;
	int l = strlen(s);
	int cnt[27][2] = {{0}};
	char i;
	int j;
	int maxv = -1;
	for(i = 'A';i <= 'Z';i++)
	{
		
		
		for (j = 0; j < l; j += 1)
		{
			if(s[j]==i)
			{
				break;
			}
		}
		int idx = j;
		int cntodd = 0;
		int cnteven = 1;
		for(j = j+1;j<l;j++)
		{
			if(i==s[j])
			{
				if((j-idx)%2==1)
				{
					cntodd = cnteven+1;;
				}
				else
				{
					cnteven = cntodd+1;
				}
			}
		}
		cnteven = max(cnteven,cntodd);
		maxv = max(cnteven,maxv);
	}
	cout<<maxv;
	return 0;
}
