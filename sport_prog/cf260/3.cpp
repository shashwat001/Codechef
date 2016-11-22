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

#define INF 100000000
#define LLINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef unsigned int uint;
typedef unsigned long long int ulli;
typedef pair<int,int> pairint;

int main()
{
	lli n,i;
	scanf("%lld",&n);
	lli hash[100005] = {0};
	for(int i = 0;i < n;i++)
	{
		lli temp;
		scanf("%lld",&temp);
		hash[temp] += 1;
	}
	lli pts[100003] = {0};
	if(hash[1]>0)
		pts[1] = hash[1];
	for(i = 2;i <= 100000;i++)
	{
		if(hash[i]>0)
		{
			pts[i] = max(pts[i-2]+i*hash[i],pts[i-1]);
		}
		else
		{
			pts[i] = max(pts[i-1],pts[i-2]);
		}
	}
	
	lli revpts[100003] = {0};
	for(i = 100000;i > 0;i--)
	{

		if(hash[i]>0)
		{
			revpts[i] = max(revpts[i+2]+i*hash[i],revpts[i+1]);
		}
		else
		{
			revpts[i] = max(revpts[i+1],revpts[i+2]);
		}
	}
	lli maxpts = 0;
	for(i = 100000;i > 0;i--)
	{
		
		maxpts = max(maxpts,pts[i]+revpts[i+2]);
	}
	printf("%lld",maxpts);
	
	return 0;
}
