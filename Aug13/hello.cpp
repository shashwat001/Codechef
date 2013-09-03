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

int main ()
{
	int i,j,u,n,m,c,t;
	float d,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%f %d %d",&d,&u,&n);
		float min = u*d;
		int minidx = 0;
		for(i = 0;i < n;i++)
		{
			scanf("%d %f %d",&m,&r,&c);
			float avg = u*r+((float)c)/m;
			if(min>avg)
			{
				min = avg;
				minidx = i+1;
			}
		}
		cout<<minidx<<endl;
		
	}
	return 0;
}
