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
	lli t,r,c,sr,sc,tr,tc,out;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld%lld%lld%lld%lld",&r,&c,&sr,&sc,&tr,&tc);
		if(tr>sr)
		{
			if(tc==c)
			{
				out = c-sc+1+tr-sr;
			}
			else if((r-tr) %2==0)
			{
				out = c-sc+1+r-sr+((c-1)*(r-tr))+c-tc;
			}
			else
			{
				out = c-sc+1+r-sr+((c-1)*(r-tr))+tc;
			}
		}
		else if(tr==sr)
		{
			if(tc>=sc)
			{
				
			}
		}
		else
		{
			if(sc==1)
			{
			
				if((sr-tr) %2!=0)
				{
					out = c-sc+1+(sr-tr-1)*c +c-tc+1;
				}
				else
				{
					out = c-sc+1+(sr-tr-1)*c +tc;
				}
			}
			else
			{
				if((sr-tr) %2!=0)
				{
					out = c-sc+1+(sr-tr-1)*c +tc;
				}
				else
				{
					out = c-sc+1+(sr-tr-1)*c +c-tc+1;
				}
			}
			out+=(r-sr+1)*c;
		}
		printf("%lld\n",out);
	}
	return 0;
}
