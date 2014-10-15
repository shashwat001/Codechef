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
lli tree[400005] = {0};
int rangetree[400005] = {0};

int MaxVal;



lli read(int idx)
{
	lli sum = 0;
	while (idx > 0)
	{
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void add(int idx, int val)
{
	while (idx <= MaxVal)
	{
		tree[idx] += (lli)val;
		idx += (idx & -idx);
	}
}

void update(int idx)
{
	while (idx <= MaxVal)
	{
		tree[idx] -= 1;
		idx += (idx & -idx);
	}
}


int bsleft(int b,int e,lli val)
{
	if(b==e)
	{
		if(val==0)
			return b;
		else
			return b+1;
	}
	int mid = (b+e)/2;
	lli valmid = read(mid);
	if(valmid>=val)
	{
		return bsleft( b,mid,val);
	}
	else
	{
		return bsleft(mid+1,e,val);
	}
}

int bsright(int b,int e,lli val)
{
	if(b==e)
	{
			return b;
	}
	int mid = (b+e)/2;
	lli valmidnext = read(mid+1);
	if(valmidnext>val)
	{
		return bsright( b,mid,val);
	}
	else
	{
		return bsright(mid+1,e,val);
	}
}


pi findrange(int idx)
{
	lli val = read(idx);
	int left = bsleft(1,MaxVal,val);
	int right = bsright(1,MaxVal,val);
	return mp(left,right);
}

int getcountleft(int b,int e, vector<pi > &rangesecondsort)
{
	if(e<b)
		return 0;
	vector<pi >::iterator lb,ub;
	lb = lower_bound(rangesecondsort.begin(),rangesecondsort.end(),mp(e,b));
	ub = upper_bound(rangesecondsort.begin(),rangesecondsort.end(),mp(e,e));
	return ub-lb;
}

int getcountright(int b,int e, vector<pi > &rangefirstsort)
{
	if(e<b)
		return 0;
	vector<pi >::iterator lb,ub;
	lb = lower_bound(rangefirstsort.begin(),rangefirstsort.end(),mp(b,b));
	ub = upper_bound(rangefirstsort.begin(),rangefirstsort.end(),mp(b,e));
	return ub-lb;
}

int rangesols(vector<int> &v, int a, int b)
{
	if (v.size() == 0)
		return 0;
	if (v.front() > b)
		return 0;
	if (v.back() < a)
		return 0;
	int low = -1;
	if (v.front() >= a)
		low = 0;
	else
	{
		int beg = 0;
		int end = v.size() - 1;
		while ((end - beg) > 1)
		{
			int mid = (beg + end) / 2;
			if (v[mid] < a)
				beg = mid;
			else
				end = mid;
		}

		low = end;
	}
	
	int high = -1;
	if (v.back() <= b)
		high = v.size() - 1;
	else
	{
		int beg = 0;
		int end = v.size() - 1;

		while ((end - beg) > 1)
		{
			int mid = (beg + end) / 2;
			if (v[mid] <= b)
				beg = mid;
			else
				end = mid;
		}

		high = beg;
	}

	return (high - low + 1);
}

int main ()
{
	int i,n,m,y,x,k,j;
	scanf("%d %d",&n,&m);
	//assert(n>=1 && n<=100000);
	//assert(m>=1 && m<=100000);
	MaxVal = n;
	set<int> done = set<int>();
	vector<int> a(n);
	vector<vector<int> > first(n+1, vector<int>());
	vector<vector<int> > second(n+1, vector<int>());
	vector<pi > rangefirstsort(m),rangesecondsort(m);
	for(i = 0;i < n;i++)
	{
		scanf("%d",&a[i]);
		add(i+1,a[i]);
	}
	
	for(i = 0;i < m;i++)
	{
		scanf("%d %d",&x,&y);
		first[x].pb(y);
		second[y].pb(x);
		rangefirstsort[i] = mp(x,y);
		rangesecondsort[i] = mp(y,x);
	}
	for(i = 1;i <=n;i++)
	{
		sort(first[i].begin(),first[i].end());
		sort(second[i].begin(),second[i].end());
	}
	sort(rangefirstsort.begin(),rangefirstsort.end());
	sort(rangesecondsort.begin(),rangesecondsort.end());
	int ans = 0;
/*	for(i = 0;i < n;i++)
	{
		if(a[i]==0)
		{
			pi range = findrange(i+1);
			int countleft = getcountleft(range.first,i+1,rangesecondsort);
			//int countright = getcountright(i+1,range.second,rangefirstsort);
			//int countcurr = getcountleft(i+1,i+1,rangesecondsort);
			ans += countleft + countright - countcurr ;
		}
	}*/
	scanf("%d",&k);
	assert(k>=1 && k<=100000);
	int trans = 0;
	for(i = 0;i < k;i++)
	{
		scanf("%d",&x);
		y = x+ans;
		if(a[y-1]==0)
		{
			printf("%d\n",ans);
			continue;
		}
		a[y-1]--;

		update(y);
		int cnt = 0;
		if(a[y-1]==0)
		{
			pi range = findrange(y);
			bool every = true;
			set<int>::iterator it = done.lower_bound(range.first);
			if (it != done.end())
			{
				if ((*it) <= y)
					every = false;
			}

			int t = 0;
			if (every)
			{
				for (int x = range.first; x <= y; x++)
				{
					t += rangesols(first[x], y, range.second);
					done.insert(x);
				}
			}
			else
			{
				for (int z = y; z <= range.second; z++)
					t += rangesols(second[z], range.first, y);
  			}
			//int countright = getcountright(y+1,range.second,rangefirstsort);
			//int countrightall = getcountright(range.first,range.second,rangefirstsort);
			//int countcurr = getcountleft(y,y,rangesecondsort);
			//assert(countleft>=0 && countleft<=m && countright>=0 && countright<=m && countcurr>=0 && countcurr<=m);
			//ans += countrightall - countright - countleft + countcurr;
			ans+=t;
		}
		
		printf("%d\n",ans);
	}
	return 0;
}
