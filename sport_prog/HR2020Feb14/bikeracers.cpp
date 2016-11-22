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
#define x first
#define y second

typedef long long int lli;
typedef pair<int,int> pi;
typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, int w[300][300], VI &mr, VI &mc, VI &seen,int n,int m) {
  for (int j = 0; j < m; j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen,n,m)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(int w[300][300],int n,int m) 
{
  VI mr(n, -1);
  VI mc(m, -1);
  
  int ct = 0;
  for (int i = 0; i < n; i++) 
  {
    VI seen(m);
    if (FindMatch(i, w, mr, mc, seen,n,m)) ct++;
  }
  return ct;
}

bool check(lli distsq[300][300],lli T,int n,int m,int k)
{
	int i,j;
	int w[300][300] = {{0}};
	for (i = 0; i < n; i += 1)
	{
		for (j = 0; j < m; j += 1)
		{
			if(distsq[i][j]<= T)
			{
				w[i][j] = 1;
			}
		}
	}
	int match = BipartiteMatching(w,n,m);
	if(match >= k)
		return true;
	return false;
}

int main ()
{
	int n,m,k,i,j;
	pair<lli,lli> biker[300],bike[300];
	lli distsq[300][300];
	cin>>n>>m>>k;
	for(i = 0;i < n;i++)
	{
		cin>>biker[i].x>>biker[i].y;
	}
	for(i = 0;i < m;i++)
	{
		cin>>bike[i].x>>bike[i].y;
	}
	for (i = 0; i < n; i += 1)
	{
		for (j = 0; j < m; j += 1)
		{
			distsq[i][j] = (biker[i].x-bike[j].x)*(biker[i].x-bike[j].x) + (biker[i].y-bike[j].y)*(biker[i].y-bike[j].y);
		}
	}
	
	lli low = 0;
	lli high = 100000000000000LL;
	while(low < high)
	{
		lli mid = (low+high)/2;
		if(check(distsq,mid,n,m,k) == true)
		{
			high = mid;
		}
		else
		{
			low = mid+1;
		}
	}
	cout<<low<<endl;
	return 0;
}
