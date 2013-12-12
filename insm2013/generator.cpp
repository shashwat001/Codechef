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
	int t = 5;
	cout<<t<<endl;
	while(t--)
	{
		int n = 100000;
		int m = 100000;
		cout<<n<<" "<<m<<endl;
		for(int i = 0;i < m;i++)
		{
			int x = rand()%n +1;
			int y = rand()%n + 1;
			cout<<x<<" "<<y<<endl;
		}
	}
	return 0;
}
