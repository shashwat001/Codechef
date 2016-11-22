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
	int a,b,c;
	cin>>a>>b>>c;
	vector<int> A;
	int a1,b1;
	for(int i = 0;i <= a;i++)
	{
		a1 = a;
		b1 = b;
		a1 -= i;
		b1 -= i;
		if(a1<0 || b1 <0)
			break;
		if(c==(a1+b1))
		{
			cout<<i<<" "<<b1<<" "<<a1<<endl;
			return 0;
		}
	}
	cout<<"Impossible";
	return 0;
	return 0;
}
