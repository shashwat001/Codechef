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
	unsigned long long int x,y;
	int i;
	int bs[100] = {0},bt[100] = {0};
	cin>>x>>y;
	int bitx[100] = {0},bity[100] = {0},bx = 0,by = 0;
	int carry = 0;
	while(x>0)
	{
		bitx[bx++] = x&1;
		x >>= 1;
	}
	while(y>0)
	{
		bity[by++] = y&1;
		y >>= 1;
	}
	int flag = 0;
	for(i = 63;i>=0;i--)
	{
		if(bitx[i]==0 && bity[i] == 0 )
		{
			if(carry == 1)
			{
				bs[i] = bt[i] = 1;
			}
			else
			{
				bs[i] = bt[i] = 0;
			}
			carry = 0;
			
		}
		else if((bitx[i]==0 && bity[i] == 1) )
		{
			if(carry == 0)
			{
				flag = 1;
				break;
			}
			else
			{
				bs[i] = 0;
				bt[i] = 1;
				carry = 1;
			}
		}
		else if((bitx[i]==1 && bity[i] == 0))
		{
			if(carry == 0)
			{
				bs[i] = bt[i] = 0;
				carry = 1;
			}
			else
			{
				bs[i] = bt[i] = 1;
				carry = 1;
			}
		}
		else
		{
			if(carry == 1)
			{
				flag = 1;
				break;
			}
			else
			{
				bs[i] = 0;
				bt[i] = 1;
				carry = 0;
			}
		}
	}
	if(flag == 1 || carry == 1)
	{
		cout<<"Impossible";
	}
	else
	{
		unsigned long long int s=0;
		for(i = 63;i>=0;i--)
		{
			s = s*2+bs[i];
		}
		unsigned long long int t=0;
		for(i = 63;i>=0;i--)
		{
			t = t*2+bt[i];
		}
		cout<<s<<" "<<t<<endl;
	}
	return 0;
}
