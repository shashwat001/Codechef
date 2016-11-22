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
	char s[10][10] = {"0-|-0000","0-|0-000","0-|00-00","0-|000-0","0-|0000-","-0|-0000","-0|0-000","-0|00-00","-0|000-0","-0|0000-"};
	int i,j,m,a[100005],n;
	cin>>n;
	while(n>0)
	{
		cout<<s[n%10]<<endl;
		n = n/10;
	}
	
	return 0;
}
