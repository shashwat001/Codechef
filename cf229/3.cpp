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
 int v[11][100001]={0};
int main ()
{
	int  n,k1,w,i,j,k,l,r;
	char s[100004];
	cin>>n>>k1>>w;
	cin>>s;
	int sum[100005];
	sum[0] = 0;
	for(i = 1;i <= n;i++)
	{
		sum[i] = sum[i-1]+s[i-1]-'0';
	}
	for ( i = 0; i <= k1; i += 1)
	{
		j = k1;
			int count = 0;
			for (unsigned int k = i; k <=  n; k += j)
			{
				if(k>0 && s[k-1]=='1')
				{
					count++;
				}
				v[i][k] = count;
			}
	}
	for(i = 0;i < w;i++)
	{
		cin>>l>>r;
		int beg = (l-1)%k1;
		int cleft = v[beg][l-1];
		int cright = v[beg][r];
		int countk = cright-cleft;
		int tot = sum[r]-sum[l-1];
		int totk = (r-l+1)/k1;
		int ans = totk-countk+tot-countk;
		cout<<ans<<endl;
	}
	return 0;
}
