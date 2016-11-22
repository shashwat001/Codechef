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
	int i,j,k,n,m,a[100006],b[100005];
	cin>>n;
	int cnt = 0;
	for(i = 0;i < n;i++)
	{
		cin>>a[i];
		if(a[i]==5)
			cnt++;
	}
	if(n-cnt==0)
	{
		cout<<-1;
		return 0;
	}
	if(n-cnt>0)
	{
		for(i = 0;i<cnt/9;i++)
		{
			for(j = 0;j<9;j++)
				cout<<5;
		}
		if(i!=0)
		for(i = 0;i<n-cnt;i++)
		{
			cout<<0;
		}	
		else
		cout<<0;
	}
	
	return 0;
}
