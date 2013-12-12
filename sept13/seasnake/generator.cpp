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
	int i;
	srand(time(NULL));
	int n = rand()%30+1;
	int m = rand()%30+1;
	cout<<n<<" "<<m<<endl;
	for(i = 0;i < n*m-1;i++)
	{
		int a,b;
		if(i==0)
		{
			a = rand()%(n);
			b = rand()%(m-1)+1;
		}
		else
		{
			a = rand()%n;
			b = rand()%m;
		}
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}
