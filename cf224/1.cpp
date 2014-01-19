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

#define MAX5 100000
#define MAX9 1000000000
#define INF 2147483647
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef pair<int,int> pi;

int main ()
{
	int i,n,k;
	char s[10000];
	cin>>s;
	int l = strlen(s);
	for(i = 0;i < l;i++)
	{
		if(s[i]=='|')
			break;
	}
	char s1[10000];
	cin>>s1;
	int c = strlen(s1);
	int a = i;
	int b = l-a-1;
	if((c+b-a)>=0 && (c+b-a)%2==0)
	{
		int x = (c+b-a)/2;
		int y = c-x;
		if(x<0 || y<0)
		{
			cout<<"Impossible";
			return 0;
		}
		for(i = 0;i < a;i++ )
		{
			cout<<s[i];
		}
		for(i = 0;i < x;i++)
		{
			cout<<s1[i];
		}
		cout<<"|";
		for(i = a+1;i < l;i++)
		{
			cout<<s[i];
		}
		for(i = x;i<c;i++)
		{
			cout<<s1[i];
		}
	}
	else
		cout<<"Impossible";
	return 0;
}
