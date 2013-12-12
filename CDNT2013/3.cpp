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
	int t;
	char s1[100000],s2[100000];
	scanf("%d",&t);
	while(t--)
	{
		int a[256] = {0},i,flag = 0;
		scanf("%s",s1);
		scanf("%s",s2);
		for(i = 0;i < strlen(s1);i++)
		{
		
			a[s1[i]-'A']++;
		}
				for(i = 0;i < strlen(s2);i++)
		{
		
			a[s2[i]-'A']--;
		}
		for(i = 0;i < 256;i++)
		{
			if(a[i]!=0)
			{
				flag = 1;
				break;
			}
		}
		if(flag==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
