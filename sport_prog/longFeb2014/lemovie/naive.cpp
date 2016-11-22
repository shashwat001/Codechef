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

int findexciteness(int a[],int b[],int n)
{
	int i;
	priority_queue<int> p;
	p.push(a[b[0]]);
	int count = 1;
	for(i = 1;i < n;i++)
	{
		int top = p.top();
		if(a[b[i]]>top)
			count++;
		p.push(a[b[i]]);
	}
	return count;
}


int main ()
{
	int t;
	cin>>t;
	while(t--){
	int n,i,a[20],k,b[20];
	cin>>n>>k;
	for(i = 0;i < n;i++)
	{
		cin>>a[i];
		b[i] = i;
	}
	int sum = 0;
	do
	{
		int ex = findexciteness(a,b,n);
		if(ex<=k)
			sum++;		
	}
	while(next_permutation(b,b+n));
	cout<<sum<<endl;
	}
	return 0;
}
