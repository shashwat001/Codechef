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
	int n,t,i;
	scanf("%d",&t);
	while(t--){
	int p = 0;
	scanf("%d",&n);
	while((n%7)==0 && n>0)
	{
		p++;
		n = n/7;
	}
	if(p==2)
		printf("YES\n");
	else
		printf("NO\n");}
	return 0;
}
