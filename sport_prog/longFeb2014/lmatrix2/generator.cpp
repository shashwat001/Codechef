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
	int n = rand()%34+66;
	int m = rand()%34+66;
	int i,a,p[200][200];
	n = m = 99;
	cout<<n<<" "<<m<<endl;
	for(i = 0;i < n;i++)
	{
		for (unsigned int j = 0; j < m; j += 1)
		{
			p[i][j] = rand()%10+1;
			cout<<p[i][j]<<" ";
		}
		cout<<endl;
	}
	for(i = 0;i < n;i++)
	{
		for (unsigned int j = 0; j < m; j += 1)
		{
			a = rand()%p[i][j];
			cout<<a<<" ";
		}
		cout<<endl;
	}
	return 0;
}
