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

int main()
{
	lli t,T,resc,i,j,n,a[30],cum[30],rem;
	cin>>T;
	char L[30];
	char res[30];
	
	for(t = 1;t <= T;t++)
	{
		cin>>L;
		cin>>n;
		int l = strlen(L);
		a[0] = 1;
		cum[0] = 0;
		for(i = 1;i <= l;i++)
		{
			a[i] = a[i-1]*l;
			cum[i] = a[i]+cum[i-1];
		}
		rem = n;
		while(rem > 0)
		{
			j = 1;
			while(rem > cum[j]) j++;

			lli curlengthstr = a[j];
			rem = rem-cum[j-1];
			int currentChar = rem/a[j-1];
			res[resc++] = L[currentChar];
		}
		
		res[resc] = '\0';
		
	}
	return 0;
}
