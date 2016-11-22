#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

#define INF 2147483647
#define LLINF 9223372036854775807

typedef long long int lli;
typedef unsigned int uint;
typedef unsigned long long int ulli;
typedef pair<int,int> pairint;

int i,j;

int main()
{
	long long int n,q,b[100001] = {0},sum,sum2,k,l,rem,anssum;
	vector<long long int> a;
	cin>>n;
	for(i = 0;i < n;i++)
	{
		cin>>j;
		a.push_back(j);
	}
	sort(a.begin(),a.end());
	b[n-1] = a[n-1];
	for(i = n-2;i>=0;i--)
	{
		b[i] = a[i]+b[i+1];
	}
	cin>>q;
	for(i = 0;i < q;i++)
	{
		cin>>k;
		sum = 0;
		rem = n%k;
		for(j = 0;j < rem;j++)
		{
			sum = sum+a[j];
		}
		anssum = sum-a[j-1];
		while(j < n)
		{
			sum2 = 0;
			for(l = j;l < j+k;l++)
				sum2 = sum2+a[l];
			j = j+k;
			
			sum = sum+sum2;
			anssum = anssum+sum-a[j-1];
			
			
		}
		cout<<anssum<<endl;
	}
	return 0;
}
