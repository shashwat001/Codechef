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
	lli a,b,c;
	lli totala,totalb,totalc;
	
	lli costa,costb,costc;
		lli amnt;
bool check(lli cc)
{
	lli sum = 0;
	if(cc*a-totala >=0)
	{
		sum+=(cc*a-totala)*costa;
	}
	if(cc*b-totalb >=0)
	{
		sum+=(cc*b-totalb)*costb;
	}
	if(cc*c-totalc >=0)
	{
		sum+=(cc*c-totalc)*costc;
	}
	if(sum<=amnt)
		return true;
	return false;
}

int main ()
{

	cin>>a>>b>>c;
	cin>>totala>>totalb>>totalc;
	cin>>costa>>costb>>costc;

	cin>>amnt;
	lli low = 0;
	lli high = 2000000000000LL;
	while(low<high)
	{
		lli mid = (low+high)/2;
		bool get = check(mid);
		if(check(mid) && !check(mid+1))
		{
			low = mid;
			break;
		}
		if(get == true)
		{
			low = mid+1;
		}
		else
		{
			high = mid;
		}
	}

		cout<<low<<endl;
	return 0;
}
