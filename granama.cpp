#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

#define INF 2147483647
#define LLINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef unsigned int uint;
typedef unsigned long long int ulli;
typedef pair<int,int> pairint;

#define BUF 4096
char ibuf[BUF];
int ipt = BUF;

int readInt()
{
	while (ipt < BUF && ibuf[ipt] < '0')
		ipt++;

	if (ipt == BUF)
	{
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] < '0')
			ipt++;
	}

	int n = 0;
	while (ipt < BUF && ibuf[ipt] >= '0')
		n = (n*10)+(ibuf[ipt++]-'0');

	if (ipt == BUF)
	{
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] >= '0')
			n = (n*10)+(ibuf[ipt++]-'0');
	}
	return n;
}

/********************************************************************************************/

int i,j;

int main()
{
	int t,v1[26],v2[26],flag;
	char s1[1001],s2[1001];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s1);
		scanf("%s",s2);
		memset(v1,0,sizeof(v1));
		memset(v2,0,sizeof(v2));
		for(i = strlen(s1)-1;i>=0;i--)
		{
			v1[s1[i]-'a']++;
		}
		for(i = strlen(s2)-1;i>=0;i--)
		{
			v2[s2[i]-'a']++;
		}
		flag = 0;
		for(i = 0;i < 26;i++)
		{
			if(v1[i]==v2[i])
				continue;
			else if(v1[i] == 0 || v2[i]==0)
			{
				flag = 0;
				break;				
			}
			else
			{
				flag = 1;
			}
		}
		if(flag==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
