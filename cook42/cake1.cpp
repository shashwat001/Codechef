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
	int t,x1,x2,y1,y2;
	cin>>t;
	while(t--)
	{
		int a1,b1,a2,b2,left,right,bottom,top,area;
		cin>>x1>>y1>>x2>>y2;
		cin>>a1>>b1>>a2>>b2;
		left = max(x1, a1);
		right = min(x2, a2);
		bottom = max(y1, b1);
		top = min(y2, b2);
		if(left<right && bottom<top)
			 area = (x2-x1)*(y2-y1)+(a2-a1)*(b2-b1)-(right-left)*(top-bottom);
		else
			area = (x2-x1)*(y2-y1)+(a2-a1)*(b2-b1);
		cout<<area<<endl;
	}
	return 0;
}
