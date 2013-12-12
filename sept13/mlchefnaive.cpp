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
void update(int a[],vector<vector<int> > edge, int A, int X)
{
	int i;
	stack<int> s;
	s.push(A);
	while(!s.empty())
	{
		int top = s.top();
		s.pop();
		for(i = 0;i < (int)edge[top].size();i++)
		{
			s.push(edge[top][i]);
			a[edge[top][i]]-= X;
		}
	}
}

int countval(int a[],vector<vector<int> > edge, int A)
{
	int cnt = 0,i;
	stack<int> s;
	s.push(A);
	while(!s.empty())
	{
		int top = s.top();
		s.pop();
		for(i = 0;i < (int)edge[top].size();i++)
		{
			s.push(edge[top][i]);
			if(a[edge[top][i]] > 0)
			{
				cnt++;
			}
		}
	}
	return cnt;
}
int main ()
{
	int i,n,x,y,q,c,A,X;
	int a[100006];
	scanf("%d",&n);
	vector<vector<int> > edge(n+1);
	for(i = 1;i <= n;i++)
	{
		scanf("%d %d",&x,&y);
		a[i] = x;
		edge[y].pb(i);
	}
	scanf("%d",&q);

	for(i = 0;i < q;i++)
	{
		scanf("%d",&c);
		if(c==1)
		{
			scanf("%d %d",&A, &X);
			update(a,edge,A,X);
		}
		else
		{
			scanf("%d",&A);
			printf("%d\n",countval(a,edge,A));
		}
	}
	return 0;
}
