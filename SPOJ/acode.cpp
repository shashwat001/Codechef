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
	char str[5005];
	unsigned long long a[5005];
	int len;
	scanf("%s",str);
	while(str[0] != '0')
	{
		len = strlen(str);
		a[0] = 1;
		if(len == 1)
		{
			printf("%llu\n",a[len-1]);
			scanf("%s",str);
			continue;
		}
		if(str[1] == '0')
		{
			a[1] = a[0];
		}
		else
		{
			if(str[0]<'2')
				a[1] = 2;
			else if(str[0] == '2')
			{
				if(str[1]<='6')
					a[1] = 2;
				else
					a[1] = 1;
			}
			else
				a[1] = 1;
		}
		if(len == 2)
		{
			printf("%llu\n",a[len-1]);
			scanf("%s",str);
			continue;
		}
		for(i = 1;i < len;i++)
		{
			if(i==1)
			{
				if(str[2] == '0')
				{
					a[1] = a[0];
				}
				continue;
			}
			if(str[i] == '0' || str[i-1] == '0')
			{
				a[i] = a[i-1];
				continue;
			}
			if(i<len-1)
				if(str[i+1] == '0')
				{
					a[i] = a[i-1];
					continue;
				}
			
			if(str[i-1]<'2')
			a[i] = a[i-1]+a[i-2];
			else if(str[i-1] == '2')
			{
				if(str[i]<='6')
					a[i] = a[i-1]+a[i-2];
				else
					a[i] = a[i-1];
			}
			else
				a[i] = a[i-1];
		}
		printf("%llu\n",a[len-1]);
		scanf("%s",str);
	}
	return 0;
}
