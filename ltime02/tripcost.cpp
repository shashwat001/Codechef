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
#define mp makepair
#define pb push_back

typedef long long int lli;
typedef struct
{
	int first,second,third;
} pi;

pi makepair(int a,int b,int c)
{
	pi p;
	p.first = a;
	p.second = b;
	p.third = c;
	return p;
}



class comp
{
	public:
	bool operator()(pi lhs, pi rhs)
	{
		if(lhs.third > rhs.third)
			return true;
		if(lhs.third == rhs.third)
		{
			if(lhs.first > rhs.first)
				return true;
		}
		return false;
	}
};

int c[500000],mind[500000];
int main ()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		int n,d,x,minc;
		scanf("%d %d",&n,&d);
		vector<lli> dist(n+1);
		vector<lli>::iterator ub;
		priority_queue<pi, vector<pi >, comp > pq;
		dist[0] = 0;
		for(i = 0;i < n;i++)
		{
			scanf("%d %d",&x,&c[i+1]);
			dist[i+1] = dist[i]+(lli)x;
		}
		pq.push(makepair(0,0,0));
		for(i = 1;i <= n;i++)
		{
			ub = upper_bound(dist.begin(),dist.end(),dist[i]-d-1);
			int pos = ub-dist.begin();
			pi pr;
			while(!pq.empty())
			{
				pr = pq.top();
				if(pr.second<pos)
				{
					pq.pop();
				}
				else
				{
					break;
				}
			}
			minc = max(c[i],pr.first);
			if(i == n)
				c[i] = pr.first;
			else
				c[i] = minc;
			mind[i] = pr.third+1;
			pq.push(makepair(c[i],i,mind[i]));
		}
		printf("%d %d\n",mind[n],c[n]);
	}
	
	return 0;
}
