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
	int k = 0;
	double a,d;
	int n,i;
	scanf("%lf %lf %d",&a,&d,&n);
	double x = 0.0,y = 0.0;
	for(i = 0;i < n;i++)
	{
		double rem;
		if(k%4 == 0)
			rem = a-x;
		else if(k%4==1)
			rem = a-y;
		else if(k%4==2)
			rem = x;
		else
			rem = y;
		if(rem >=d)
		{
			if(k%4 == 0)
				x+=d;
			else if(k%4==1)
				y+=d;
			else if(k%4==2)
				x-=d;
			else
				y-=d;
			if(rem==d)
			{
				k++;
			}
			
		}
		else
		{
			k++;
			double newd = d-rem;
			int turn = newd/a;
			k+=turn;
			double rem = newd-a*turn;
			if(k%4==0)
				x = rem,y = 0;
			else if(k%4==1)
				y = rem,x = a;
			else if(k%4==2)
				x = a- rem,y =a;
			else
				y = a-rem,x  = 0;
		}
		printf("%lf %lf\n",x,y);
	}
	return 0;
}
