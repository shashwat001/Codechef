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
	char r[200][200];
int main ()
{

	int cr,cc,i,k;
	cin>>cr>>cc;
	int cnt = 0;
	char s[20] = "aaaaa",S[20] = "AAAAA";
	for(i = 0;i < cr;i++)
	{
		cin>>r[i];
		for (unsigned int j = 0; j < cc-4; j += 1)
		{
			for(k = 0;k < 5;k++)
			{
				if((r[i][j+k] != s[k] ) && (r[i][j+k] != S[k]))
					break;
			}
			if(k==5)
				cnt++;
		}
	}

	for(i = 0;i < cc;i++)
	{
		for (unsigned int j = 0; j < cr-4; j += 1)
		{
			for(k = 0;k < 5;k++)
			{
				if((r[j+k][i] != s[k]) && (r[j+k][i] != S[k]))
					break;
			}
			if(k==5)
				cnt++;
		}
	}

	
	for(i = 0;i < cr-4;i++)
	{
		for (unsigned int j = 0; j < cc-4; j += 1)
		{
			for(k = 0;k < 5;k++)
			{
				if((r[i+k][j+k] != s[k]) && (r[i+k][j+k] != S[k]))
					break;
			}
			if(k==5)
				cnt++;
		}
	}

	for(i = 0;i < cr-4;i++)
	{
		for (unsigned int j = cc-1; j >= 4; j -= 1)
		{
			for(k = 0;k < 5;k++)
			{
				if((r[i+k][j-k] != s[k]) && (r[i+k][j-k] != S[k]))
					break;
			}
			if(k==5)
				cnt++;
		}
	}

	cout<<cnt*2<<endl;
	return 0;
}
