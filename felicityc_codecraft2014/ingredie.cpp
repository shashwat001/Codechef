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

#define INF 100000000
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef pair<int,int> pi;
int CITY;
bool vis [10] [1024]; // is_visited
int val [10] [1024]; // cost at particular state


int dist[100][100];

int dp (int at, int mask,int arr[])
{
    if ( mask ==  (1 << CITY) - 1 ) { // all visited
        vis [at] [mask] = true;
        return val [at] [mask];
    }
 
    if ( vis [at] [mask] ) return val [at] [mask];
    vis [at] [mask] = true;
 
    int ans = INF;
    int costs;
 
    for ( int i = 0; i < CITY; i++ ) 
    {
        if ( dist [at] [arr[i]] != INF && (mask & (1 << i)) == 0 ) {
            costs = dp (arr[i], mask | (1 << i),arr)+dist [at] [arr[i]];
            if ( ans > costs ) 
            	ans = costs;
        }
    }
 
    return val [at] [mask] = ans;
}

int main ()
{
	int n,m,i,j;
	cin>>n>>m;
	for(i = 0;i < n;i++)
	{
		for (j = 0; j < n; j += 1)
		{
			if(i==j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
		}
	}
	for(i = 0;i < m;i++)
	{
		int x,y,c;
		cin>>x>>y>>c;
		dist[x][y] = c;
		dist[y][x] = c;
	}
	int s;
	cin>>s;
	int store[10];
	for(i = 0;i < s;i++)
	{
		cin>>store[i];
	}
	int s1,s2;
	cin>>s1>>s2;
	
	
	for (unsigned int k = 0; k < n; k += 1)
	{
		for (unsigned int i = 0; i < n; i += 1)
		{
			for (unsigned int j = 0; j < n; j += 1)
			{
				if(dist[i][k]+dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k]+dist[k][j];
				}
			}
		}
	}
	int minm = INF;
	for(i = 0;i < (1<<s);i++)
	{
		int j = i;
		int bit = 0;
		int bita=1,bitb=1;
		int a[10],b[10];
		a[0] = s1;
		b[0] = s2;
		while(j>0)
		{
			if(j&1)
			{
				if(store[bit] != s1)
				{
					a[bita++] = store[bit++]; 
				}
				else
					bit++;
			}
			else
			{
				if(store[bit] != s2)
				{
					b[bitb++] = store[bit++];
				}
				else
					bit++;
			}
			j = j>>1;
		}
		while(bit < s)
		{
			if(store[bit] != s2)
			{
				b[bitb++] = store[bit++];
			}
			else
				bit++;
		}
		CITY = bita;
		memset (vis, false, sizeof (vis));
		int sum1 = dp(a[0],1,a);
		memset (vis, false, sizeof (vis));
		CITY = bitb;
		int sum2 = dp(b[0],1,b);
		minm = min(minm,sum1+sum2);
	}
	cout<<minm<<endl;
	return 0;
}
