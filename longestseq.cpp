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
	char a[100000],b[100000];
	int cnt[10000],k,prevk,max = -1,c,cur;
	memset(cnt,0,sizeof(cnt));
	/*scanf("%s",a);
	j = strlen(a);
	i = 0;
	prevk = 0;
	cur = 0;
	c = 0;
	while (i <j)
	{
		k = 0;
		while(a[i] != ' ')
		{
			k++;
			i++;
		}
		if(k == prevk)
		{
			cur++;
			while(a[i] == ' ')
			{
				i++;
			}
		}
		else
		{
			if(cnt[prevk] < cur)
			{
				cnt[prevk] = cur;
				if(max < cur)
				{
					max = cur;
					c = prevk;
				}
			}
			cur = 0;
			prevk = k;
		}
		
	}
	printf("%d\n",c);*/
	
	
	prevk = 0;
	cur = 1;
	scanf("%s",a);
	strcpy(b,a);
	k = strlen(a);
	while(k>0)
	{
		
		if(k == prevk)
		{
			cur++;
		}
		else
		{
			if(cnt[prevk] <= cur)
			{
				cnt[prevk] = cur;
				if(max < cur)
				{
					max = cur;
					c = prevk;
				}
			}
			cur = 1;
			prevk = k;
		}
		scanf("%s",b);
		if(strcmp(a,b) == 0)
		{
			break;
		}
		else
		{
			strcpy(a,b);
		}
		k = strlen(a);
	}
	printf("%d\n",c);
	return 0;
}
