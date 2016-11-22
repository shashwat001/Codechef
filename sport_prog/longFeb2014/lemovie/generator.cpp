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
	srand(time(NULL));
	cout<<10<<endl;
	for (unsigned int j = 0; j < 10; j += 1)
	{
		int n = 4,i;
		int k = rand()%n+1;
		cout<<n<<" "<<k<<endl;
		for(i = 0;i < n;i++)
		{
			int a = rand()%n+1;
			cout<<a<<" ";
		}
		cout<<endl;
	}

	return 0;
}
