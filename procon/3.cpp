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

struct 
{
	int tim,it;
} po[10000];

int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		int it[10000],tim[10000];
		scanf("%d",&n);
		{
			for(i = 0;i < n;i++)
			{
				scanf("%d %d %d %d %d %d",&po[i].tim,&u,&v,&w,&x,&y,&z);
				po[i].it = u+v+w+x+y+z;
			}
			int wait[10000] = {0};
			sort(po,po+n);
			int cpo = 0;
			q.push(0);
			while(!q.empty())
			{
				int next = q.front();
				wait[cur]+=po[next].tim - po[curr].tim;
				int ltime = q.back();
				po[curr].tim = q.back();
				
			}
		}
		
	}	
	return 0;
}
