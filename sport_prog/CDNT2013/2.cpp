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
#define mp make_pair
#define pb push

typedef long long int lli;
typedef pair<int,int> pi;

int main ()
{	
	lli left=0,right=0,x,a;
	priority_queue<lli> pright;
	priority_queue<lli, vector<lli>, std::greater<lli> > pleft;
	char s[40];
	while(1)
	{
		scanf("%s",s);
		if(s[0]=='A')
		{
			scanf("%lld",&x);
			if(left==right)
			{
				a = -INF;
				if(!pright.empty())
					a = pright.top();
				if(x>=a)				
					pleft.pb(x);
				else
				{
					pright.pb(x);
					lli b = pright.top();
					pright.pop();
					pleft.pb(b);
				}
				left++;
			}
			else
			{
				lli a = pleft.top();
				if(a>=x)
					pright.pb(x);
				else
					{
						pleft.pb(x);
						lli b = pleft.top();
						pleft.pop();
										pright.pb(b);						
					}

				right++;
			}
		}
		else if(s[0]=='M')
		{
			if(left==right)
			{
				if(left==0)
				{
				printf("0\n");
				continue;
				}
//				assert(!pleft.empty());
//				assert(!pright.empty());
				lli a = pleft.top();
				lli b = pright.top();
				lli c = (a+b)/2;
				printf("%lld\n",c);
			}
			else
			{
				lli a = pleft.top();
				printf("%lld\n",a);
			}
		}
		else
		{
			break;
		}
	}
	return 0;
}
