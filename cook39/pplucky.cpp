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
	int t,i;
	cin>>t;
	while(t--)
	{
		char s[100005];
		cin>>s;
		char res[100007];
		int top = 0;
		int l = strlen(s);
		for(i = 0;i < l;i++)
		{
			char c;
			if(top>0)
			{
				c = res[top-1];
				if(c=='4' && s[i]=='7')
				{
					top--;
				}
				else
				{
					res[top++] = s[i];
				}
			}
			else
			{
				res[top++] = s[i];
			}
			
		}
		res[top] = '\0';
		cout<<res<<endl;
	}
	return 0;
}
