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

char s1[300000],s2[300000];
int main ()
{
	int n = 250000,i;
	srand(time(NULL));
	for(i = 0;i < n;i++)
	{
		s1[i] = rand()%26+'a';
		s2[i] = rand()%26+'a';
	}
	s1[i] = s2[i] = '\0';
	cout<<s1<<endl;
	cout<<s2;
	return 0;
}
