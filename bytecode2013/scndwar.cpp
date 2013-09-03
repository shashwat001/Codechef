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
	int t,l,mapp[300],flag,i,j;
	char s[70];
	scanf("%d",&t);
	while(t--)
	{
		flag = 0;
		for(i = 0;i < 300;i++)
		{
			mapp[i] = -1;
		}
		scanf("%s",s);
		l = strlen(s);
		int maxval = 0;
		
		int maxdig = 0;
//		if(s[0]>='1' && s[0]<='9')
//		{
//			flag = 1;
//			maxdig = s[0]-'0';
//		}
//		else
//		{
			mapp[(int)s[0]] = 1;
//		}
		for(i = 1;i < l;i++)
		{
//			if(s[i]>='a'&& s[i]<='z')
//			{
				if(mapp[(int)s[i]]==-1)
				{
					mapp[(int)s[i]] = maxval;
					maxval++;
					if(maxval==1 /*&& flag==0*/)
						maxval++;
				}
//			}
//			else
//			{
//				maxdig = max(maxdig,s[i]-48);
//			}
		}
		int base;
		if(maxval==0)
			base=2;
		else
		base = maxval;
		lli sum = 0;
		lli k = 1;
		for(i = l-1;i >= 0;i--)
		{
//			if(s[i]>='a'&& s[i]<='z')
//			{
				sum += k*mapp[(int)s[i]];
//			}
//			else
//			{
//				sum+= k*(s[i]-48);
//			}
			k = k*base;
		}
		printf("%lld\n",sum);
	}

	return 0;
}
